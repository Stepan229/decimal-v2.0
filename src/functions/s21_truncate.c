#include "../s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (result == NULL) return 1;

  s21_decimal ten;
  s21_from_int_to_decimal(10, &ten);

  s21_decimal_big val_big;
  s21_decimal_big ten_big;
  // s21_decimal_big result_big;

  convert_big_decima(value, &val_big);
  convert_big_decima(ten, &ten_big);
  val_big.bits[7] = 0;
  // is_zero)
  int scale = get_scale(value);

  while (scale > 0 && !is_zero(value)) {
    mod_big(val_big, ten_big, &val_big);
    scale -= 1;
  }

  result->bits[0] = val_big.bits[0];
  result->bits[1] = val_big.bits[1];
  result->bits[2] = val_big.bits[2];

  if (!is_zero(*result)) set_sign(result, get_sign_decimal(value));

  return 0;

  // if(result == NULL) return 1;

  // s21_decimal ten;
  // s21_from_int_to_decimal(10, &ten);

  // int scale = get_scale(value);

  // while(scale > 0 && !is_zero(value)){
  //     scale-=1;
  //     div_fast(value, ten, &value);
  // }

  // *result = value;

  // if(!is_zero(*result)) set_sign(result, get_sign_decimal(value));

  // return 0;
}