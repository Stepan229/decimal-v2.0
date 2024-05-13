#include "../s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  unsigned sing = (((value.bits[3] >> 31) + 1) % 2) << 31;
  set_sign(&value, sing);
  return 0;
}
