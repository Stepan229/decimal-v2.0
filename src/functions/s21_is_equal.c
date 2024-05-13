

#include "../s21_decimal.h"

// я исправил 19 строчку
int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  // int result = 1;

  s21_decimal_big val1;
  s21_decimal_big val2;

  convert_big_decima(value_1, &val1);
  convert_big_decima(value_2, &val2);

  return is_equal_big(val1, val2);
}

int is_equal_big(s21_decimal_big value_1, s21_decimal_big value_2) {
  int result = 1;

  normalize(&value_1, &value_2);
  is_equal_null(&value_1, &value_2);
  if (get_sign(value_1) != get_sign(value_2)) {
    result = 0;
  } else {
    for (int i = 0; i <= 32 * 7; i++) {
      if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
        result = 0;
        break;
      }
    }
  }
  return result;
}

int is_equal_null(s21_decimal_big *value_1, s21_decimal_big *value_2) {
  s21_decimal_big null;
  int result = 0;
  zeroing_big(&null);
  if (is_equal_fast_big(*value_1, null)) {
    set_bit_big(value_1, 255, 0);
    result = 1;
  }
  if (is_equal_fast_big(*value_1, null)) {
    set_bit_big(value_2, 255, 0);
    result = 1;
  }
  return result;
}
