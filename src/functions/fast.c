#include "../s21_decimal.h"

void add_fast_big(s21_decimal_big value_1, s21_decimal_big value_2,
                  s21_decimal_big *result) {
  unsigned int rem = 0;
  for (int i = 0; i < 32 * 7; i++) {
    unsigned int bit_1 = get_bit_big(value_1, i),
                 bit_2 = get_bit_big(value_2, i), temp = 0;
    temp = bit_1 + bit_2 + rem;
    rem = get_bit_int(temp, 1);
    set_bit_int(&temp, 1, 0);
    set_bit_big(result, i, temp);
  }
  set_bit_big(result, 32 * 7, 0);
}

// Сравнивает только манитису
int is_equal_fast_big(s21_decimal_big val1, s21_decimal_big val2) {
  int result = 1;
  for (int i = 223; i >= 0; i--) {
    if (get_bit_big(val1, i) != get_bit_big(val2, i)) {
      result = 0;
      break;
    }
  }

  return result;
}

int is_greater_fast_big(s21_decimal_big value_1, s21_decimal_big value_2) {
  int result = 0;
  for (int i = 254; i >= 0; i--) {
    if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
      if (get_bit_big(value_1, i) == 1) {
        result = 1;
      }
      break;
    }
  }
  return result;
}

int is_greater_or_equal_fast_big(s21_decimal_big val1, s21_decimal_big val2) {
  return is_greater_fast_big(val1, val2) || is_equal_fast_big(val1, val2);
}

int add_fast(s21_decimal val1, s21_decimal val2, s21_decimal *result) {
  int error = 0;
  s21_decimal tmp;
  zeroing_decimal(&tmp);

  for (int i = 0, val_new = 0, in_next = 0; i < 96; i++) {
    error = 0;
    val_new = 0;
    unsigned bit1 = get_bit(&val1, i);
    unsigned bit2 = get_bit(&val2, i);

    val_new = bit1 + bit2 + in_next;

    if (val_new > 1) {
      error = 1;
      in_next = 1;
    } else {
      in_next = 0;
    }
    set_bit(&tmp, i, val_new % 2);
  }

  *result = tmp;
  return error;
}

int is_equal_fast(s21_decimal val1, s21_decimal val2) {
  int result = 1;
  for (int i = 2; i >= 0; i--) {
    if (val1.bits[i] != val2.bits[i]) {
      result = 0;
      break;
    }
  }

  return result;
}
