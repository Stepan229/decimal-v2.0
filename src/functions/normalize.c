#include "../s21_decimal.h"

int normalize(s21_decimal_big *value_1, s21_decimal_big *value_2) {
  unsigned int scale_1 = 0, scale_2 = 0;
  int difference_scale = 0, error = 0;
  scale_1 = get_scale_big(*value_1);
  scale_2 = get_scale_big(*value_2);
  if (scale_1 == scale_2) return error;
  difference_scale = scale_1 - scale_2;

  if (difference_scale < 0 && scale_2 < 60) {
    difference_scale = -difference_scale;
    scale_1 += difference_scale;
    for (int i = 0; i < difference_scale; i++) {
      mul_10(value_1);
    }
    set_scale_big(value_1, scale_1);

  } else if (difference_scale > 0 && scale_1 < 60) {
    scale_2 += difference_scale;
    for (int i = 0; i < difference_scale; i++) {
      mul_10(value_2);
    }
    set_scale_big(value_2, scale_2);
  }
  return error;
}

int round_banker_big(s21_decimal_big *result) {
  int error = 0;
  int scale = get_scale_big(*result);
  int sign = get_sign(*result);
  s21_decimal_big temp_ost, temp_null, ten;
  if (!scale) return error;
  zeroing_big(&temp_ost);  //  остатока от банковского результата
  zeroing_big(&temp_null);  // 0 не где не используем
  zeroing_big(&ten);
  ten.bits[0] = 10;

  int is_greater = 0;
  int tale = 0;  //  (хронит количество цифр после запятой увеличиваем каждую
                 //  итерацию на 1 т.к делем на 10)
  //херачим пока децимал или степень больше 0
  while (!is_greater && scale >= 0) {
    is_greater = 1;
    //проверка являится ли big decimal больше обычного  decimal(как я понял)
    for (int i = 96; i < 224; i++) {
      //почемуто используют инвертированное значени (is_greater = TRUE то число
      //равное децимал, is_greater = FALSE то число болше decimal_big обычного)
      if (get_bit_big(*result, i)) {
        is_greater = 0;
        break;
      }
    }
    if (is_greater_fast_big(temp_ost, temp_null))  //сравниваем с нулём
      tale++;  // если есть хвост и он не 0
    //Если наше число больше decimal то делем на 10 уменьшая scale
    if (!is_greater) {
      temp_ost = mod_big(*result, ten, result);
      scale--;
    }
    //случий когда у нас децимал с максимальной степенью
    if (scale > 28 && is_greater) {
      temp_ost = mod_big(*result, ten, result);
      scale--;
      is_greater = 0;
    }
  }

  //после этого кода у нас становится 21312.12321 в 21312.1
  //--------------------------
  //вылетили за предел
  if (!is_greater && scale == 0) {
    error = ERROR_CONVERT;
    return error;
  }
  s21_decimal_big five_mask = {{0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                                0x0}};  // бред с 5 (скорее всего смотрят
                                        // последнию цифру перед дробной части))
  s21_decimal_big one = {{0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}};
  //-----------------
  // добавляем 1 в случие если 5 или больше
  // printf("scale112 = %u\n", get_scale_big(*result));
  // show_digits_big(result);

  if (is_equal_fast_big(temp_ost, five_mask)) {
    if (get_bit_big(*result, 0) || tale > 1) add_fast_big(*result, one, result);
  } else if (is_greater_fast_big(temp_ost, five_mask)) {
    add_fast_big(*result, one, result);
  }

  //------------
  // printf("scale112 = %u\n", get_scale_big(*result));
  // show_digits_big(result);
  s21_decimal_big val = *result;
  //Функция делит до тех пор пока не отбросится вся дробная часть числа
  while (!get_bit_big(*result, 0) && scale > 0) {
    s21_decimal_big tmp = mod_big(val, ten, &val);
    if (is_equal_fast_big(tmp, temp_null)) {
      scale--;
      for (int i = 0; i < 8; i++) {
        result->bits[i] = val.bits[i];
      }
    } else
      break;
  }

  // printf("scale12 = %u\n", get_scale_big(*result));
  set_scale_big(result, scale);

  set_bit_big(result, 255, sign);
  // set_sign_big(result, sign);

  return error;
}
