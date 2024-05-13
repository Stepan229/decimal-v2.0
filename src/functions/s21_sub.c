#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return 1;
  zeroing_decimal(result);
  s21_decimal_big val_big_1;
  s21_decimal_big val_big_2;
  s21_decimal_big res_big;
  convert_big_decima(value_1, &val_big_1);
  convert_big_decima(value_2, &val_big_2);
  sub_big(val_big_1, val_big_2, &res_big);
  round_banker_big(&res_big);
  int error = from_big_to_decimal(res_big, result);
  return error;
}

int sub_big(s21_decimal_big value_1, s21_decimal_big value_2,
            s21_decimal_big *result) {
  int error = 0;
  zeroing_big(result);
  set_bit_big(&value_2, 255, !get_bit_big(value_2, 255));
  error = add_big(value_1, value_2, result);
  return error;
}