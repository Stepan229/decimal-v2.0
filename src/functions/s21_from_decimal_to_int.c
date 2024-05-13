
#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  if (dst == NULL) return 1;
  s21_decimal result_decimal;
  int error = 0;
  zeroing_decimal(&result_decimal);
  s21_truncate(src, &result_decimal);
  if (result_decimal.bits[1] == 0 && result_decimal.bits[2] == 0) {
    *dst = result_decimal.bits[0];
    if (get_bit(&src, 127)) *dst *= -1;
  } else
    error = 1;
  return error;
}