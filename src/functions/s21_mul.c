#include "../s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = validity_check(value_1, value_2);
  if (error != 0) return error;

  s21_decimal_big big_result;
  s21_decimal_big val1_big;
  s21_decimal_big val2_big;

  zeroing_decimal(result);
  zeroing_big(&big_result);

  convert_big_decima(value_1, &val1_big);
  convert_big_decima(value_2, &val2_big);

  for (unsigned i = 0; i < 32 * 7; i++) {
    if (get_bit_big(val2_big, i) == 1) {
      s21_decimal_big res = val1_big;
      unsigned tmp = 0;
      while (tmp < i) {
        bit_shift_big(&res, 1);
        tmp += 1;
      }
      sum_bit_big(res, &big_result);
    }
  }

  big_result.bits[255 / 32] ^= val1_big.bits[255 / 32];
  big_result.bits[255 / 32] ^= val2_big.bits[255 / 32];

  int scale = get_scale_big(val1_big) + get_scale_big(val2_big);

  set_scale_big(&big_result, scale);
  round_banker_big(&big_result);

  error = from_big_to_decimal(big_result, result);
  return error;
}
