#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int response = 0;
  if (is_equal_fast(value_2, (s21_decimal){{0, 0, 0, 0}})) return 3;

  s21_decimal_big zero;
  s21_decimal_big res_big;
  s21_decimal_big value_1_big;
  s21_decimal_big value_2_big;
  s21_decimal_big pre_frac;  // хранит результат диления дробной части
  s21_decimal_big fraction;  // хранит результат дробной части
  s21_decimal_big integral;  // хранит результат диления

  convert_big_decima(value_1, &value_1_big);
  convert_big_decima(value_2, &value_2_big);
  int scl1 = get_scale_big(value_1_big);
  int scl2 = get_scale_big(value_2_big);
  zeroing_decimal(result);
  set_scale_null(&value_1_big);
  set_scale_null(&value_2_big);
  zeroing_big(&zero);
  zeroing_big(&res_big);
  zeroing_big(&pre_frac);
  zeroing_big(&fraction);
  zeroing_big(&integral);

  s21_decimal_big remainder = mod_big(value_1_big, value_2_big, &integral);
  int scl_result = 0;
  //Поблема с подчётом степени

  while ((is_greater_fast_big(remainder, zero)) && scl_result <= 31) {
    scl_result++;
    mul_10(&remainder);
    remainder = mod_big(remainder, value_2_big, &pre_frac);
    set_scale_big(&pre_frac, scl_result);
    add_big(fraction, pre_frac, &fraction);
  }

  add_big(integral, fraction, &res_big);

  int overflow = 0;

  scl_result = get_scale_big(res_big);
  scl_result = scl1 - scl2 + scl_result;

  if (scl_result < 0) {
    while (scl_result < 0) {
      overflow += mul_10(&res_big);
      scl_result++;
    }
  }
  set_scale_big(&res_big, scl_result);
  round_banker_big(&res_big);
  overflow += from_big_to_decimal(res_big, result);
  if (get_sign_decimal(value_1) == get_sign_decimal(value_2))
    set_bit(result, 127, 0);
  // set_sign(result, 0);
  else
    set_bit(result, 127, 1);
  // set_sign(result, 1);
  if (overflow) response = get_sign_decimal(*result) ? 2 : 1;
  return response;
}

s21_decimal_big mod_big(s21_decimal_big value_1, s21_decimal_big value_2,
                        s21_decimal_big *result) {
  set_scale_null(&value_1);
  set_scale_null(&value_2);
  // printf("val1\n");
  // show_digits_big(&value_1);

  s21_decimal_big value_2_1, value_2_2, rem, one, temp_val_1;
  zeroing_big(&value_2_1);
  zeroing_big(&value_2_2);
  zeroing_big(&rem);
  zeroing_big(result);
  zeroing_big(&one);
  zeroing_big(&temp_val_1);

  one.bits[0] = 1;
  temp_val_1 = value_1;
  value_2_1 = value_2;
  value_2_2 = value_2;
  int i = 0;
  while (1) {
    value_2_1 = bit_shift_big_2(value_2_1, i);
    if (is_less_big(value_1, value_2_1)) {
      sub_big(value_1, value_2_2, &value_1);
      rem = value_1;
      value_2_1 = value_2;
      value_2_2 = value_2;
      if (is_less_big(value_1, value_2) == 1) {
        add_big(*result, bit_shift_big_2(one, i - 1), result);
        break;
      }
      add_big(*result, bit_shift_big_2(one, i - 1), result);

      i = 0;
    } else {
      i = i + 1;
      value_2_2 = value_2_1;
      value_2_1 = value_2;
    }
  }
  if (is_less_big(temp_val_1, value_2)) rem = temp_val_1;
  return rem;
}
