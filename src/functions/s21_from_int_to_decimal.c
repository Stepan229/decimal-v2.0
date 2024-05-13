#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if (dst == NULL) return 1;
  zeroing_decimal(dst);
  if (src < 0) {
    set_sign(dst, 1);
  }
  dst->bits[0] = src > 0 ? src : src * -1;
  return 0;
}
