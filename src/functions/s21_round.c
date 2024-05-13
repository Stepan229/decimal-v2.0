#include "../s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  s21_decimal tmp;
  // s21_decimal
  s21_decimal_big remainder_big;
  s21_decimal_big ten_big = {{10, 0, 0, 0, 0, 0, 0, 0}};

  convert_big_decima(value, &remainder_big);

  int sign = get_sign_decimal(value);
  int scale = get_scale(value);

  s21_truncate(value, result);
  if (scale) {
    s21_sub(value, *result, &tmp);

    convert_big_decima(tmp, &remainder_big);

    scale--;
    while (scale > 0) {
      mod_big(remainder_big, ten_big, &remainder_big);
      scale--;
    }

    remainder_big.bits[7] = 0;

    if (is_greater_or_equal_fast_big(
            remainder_big, (s21_decimal_big){{5, 0, 0, 0, 0, 0, 0, 0}})) {
      add_fast(*result, (s21_decimal){{1, 0, 0, 0}}, result);
    }
  }

  if (!is_zero(*result)) set_sign(result, sign);

  return 0;
}