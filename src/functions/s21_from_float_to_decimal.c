#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  zeroing_decimal(dst);

  //Проверки на бесконечность
  if (src == 1.0 / 0.0 || src == 1.0 / 0.0 * -1) {
    return 1;
  }

  //Проверка на слишком маленькое число
  if (fabs(src) <= 1e-28 || fabs(src) >= 7.922817E+28) {
    return 1;
  }

  if (src < 0) set_sign(dst, 1);

  src = fabs(src);

  float scale = log10(src);
  scale = scale >= 0 ? scale : (int)scale - 1;
  src = src < 1.0 ? src * pow(10.0, (int)fabs(scale))
                  : src * pow(0.1, (int)scale);
  src *= pow(10, 6);

  unsigned int val = roundf(src);

  if (6 - (int)scale > 0) {
    int finalscale = 6 - (int)scale;

    while (val % 10 == 0 && (int)log10(val) != (int)scale) {
      val /= 10;
      finalscale -= 1;
    }
    dst->bits[0] = val;
    set_scale(dst, finalscale);
  } else {
    dst->bits[0] = val;
    scale -= 7;
    s21_decimal ten = {{10, 0, 0, 0}};

    while (scale > 0) {
      scale--;
      s21_mul(*dst, ten, dst);
    }
  }
  return 0;
}
