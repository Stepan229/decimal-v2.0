#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  s21_decimal_big val1;
  s21_decimal_big val2;

  convert_big_decima(value_1, &val1);
  convert_big_decima(value_2, &val2);

  return is_less_big(val1, val2);
}

int is_less_big(s21_decimal_big value_1, s21_decimal_big value_2) {
  int ans = 0;
  // int flag_null = 0;
  normalize(&value_1, &value_2);
  is_equal_null(&value_1, &value_2);
  int sign_1 = get_bit_big(value_1, 255), sign_2 = get_bit_big(value_2, 255);
  if (sign_1 != sign_2) {
    if (sign_1 == 1) ans = 1;
  } else if (is_equal_big(value_1, value_2)) {
    ans = 0;
  } else {
    for (int i = 254; i >= 0; i--) {
      if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
        if (get_bit_big(value_2, i) == 1) ans = 1;
        break;
      }
    }
    if (sign_1 == 1 && sign_2 == 1) ans = (ans == 1) ? 0 : 1;
  }
  return ans;
}
