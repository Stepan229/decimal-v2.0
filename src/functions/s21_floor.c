#include "../s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;
  zeroing_decimal(result);
  int code = s21_truncate(value, result);
  int sign = get_sign_decimal(value);

  if (get_scale(value) > 0) {
    s21_decimal one = {{1, 0, 0, 0}};
    if (sign) {
      add_fast(*result, one, result);
      set_sign(result, sign);
    }
  }

  return code;
}
