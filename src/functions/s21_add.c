#include "../s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  if (result == NULL) return 1;
  zeroing_decimal(result);
  s21_decimal_big val_big_1;
  s21_decimal_big val_big_2;
  s21_decimal_big res_big;
  convert_big_decima(value_1, &val_big_1);
  convert_big_decima(value_2, &val_big_2);
  add_big(val_big_1, val_big_2, &res_big);
  round_banker_big(&res_big);
  int error = from_big_to_decimal(res_big, result);
  return error;
}
// Нет банковского округления
int add_big(s21_decimal_big value_1, s21_decimal_big value_2,
            s21_decimal_big *result) {
  unsigned int rem = 0, scale = 0;
  int error = 0;
  int sign_1 = get_sign(value_1), sign_2 = get_sign(value_2);
  s21_decimal_big nul;
  zeroing_big(&nul);
  zeroing_big(result);
  // нормализация
  error = normalize(&value_1, &value_2);
  // printf("__________________________________\n");
  // show_digits_big(&value_1);
  // show_digits_big(&value_2);
  // printf("__________________________________\n");
  scale = get_scale_big(value_1);
  if (sign_1 != sign_2) {
    s21_decimal_big value_modul_1, value_modul_2;
    value_modul_1 = value_1;
    value_modul_2 = value_2;
    set_bit_big(&value_modul_1, 255, 0);
    set_bit_big(&value_modul_2, 255, 0);
    if (is_less_big(value_modul_1, value_modul_2) && sign_2)
      set_bit_big(result, 255, 1);
    else if (is_less_big(value_modul_2, value_modul_1) && sign_1)
      set_bit_big(result, 255, 1);
  }
  if (sign_1 == 1 && sign_2 == 1) set_bit_big(result, 255, 1);
  if (get_sign(value_1) == 1) invert_decimal_big(&value_1);
  if (get_sign(value_2) == 1) invert_decimal_big(&value_2);
  // printf("zalupew\n");
  for (int i = 0; i < 32 * 7; i++) {
    unsigned int bit_1 = get_bit_big(value_1, i),
                 bit_2 = get_bit_big(value_2, i), temp = 0;
    temp = bit_1 + bit_2 + rem;
    rem = get_bit_int(temp, 1);
    set_bit_int(&temp, 1, 0);
    set_bit_big(result, i, temp);
  }
  set_scale_big(result, scale);
  // Сравнение с нулём

  if (get_bit_big(*result, 255) == 1) invert_decimal_big(result);
  if (rem != 0) {
    if (!get_bit_big(*result, 127))
      error = 1;
    else
      error = 2;
  }

  return error;
}
