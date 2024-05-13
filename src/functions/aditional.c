#include "../s21_decimal.h"

#define S21_MASK_BIT (1 << bit % 32)

unsigned int get_bit(s21_decimal *decimal, int num) {
  unsigned int a = 1;
  int num_int = 0;
  norm_byte_a(num, &a, &num_int);
  return (decimal->bits[num_int] & a) == 0 ? 0 : 1;
}

int set_bit(s21_decimal *decimal, int num, int bit) {
  unsigned int a = 1;
  int error = 0, num_byte = 0;
  norm_byte_a(num, &a, &num_byte);
  if (bit == 0) {
    a = ~a;
    decimal->bits[num_byte] = decimal->bits[num_byte] & a;
  } else
    decimal->bits[num_byte] = decimal->bits[num_byte] | a;
  return error;
}

unsigned int get_bit_big(s21_decimal_big decimal, int num) {
  unsigned int a = 1;
  int num_int = 0;
  norm_byte_big(num, &a, &num_int);
  return (decimal.bits[num_int] & a) == 0 ? 0 : 1;
}

int set_bit_big(s21_decimal_big *decimal, int num, int bit) {
  unsigned int a = 1;
  int error = 0, num_byte = 0;
  norm_byte_big(num, &a, &num_byte);
  if (bit == 0) {
    a = ~a;
    decimal->bits[num_byte] = decimal->bits[num_byte] & a;
  } else
    decimal->bits[num_byte] = decimal->bits[num_byte] | a;
  return error;
}

int set_bit_int(unsigned int *bits, int num, int bit) {
  unsigned int a = 1;
  int error = 0;
  a = a << num;
  if (bit == 0)
    *bits = *bits & ~a;
  else
    *bits = *bits | a;
  return error;
}

int get_bit_int(unsigned int value, int i) {
  unsigned int a = 1;
  return (value & a << i) == 0 ? 0 : 1;
}

void norm_byte_a(int num, unsigned int *a, int *num_int) {
  if (num < 32) {
    *num_int = 0;
    *a = *a << num;
  } else if (32 <= num && num < 64) {
    *num_int = 1;
    *a = *a << (num - 32);
  } else if (64 <= num && num < 96) {
    *num_int = 2;
    *a = *a << (num - 64);
  } else if (96 <= num && num < 128) {
    *num_int = 3;
    *a = *a << (num - 96);
  }
}

void norm_byte_big(int num, unsigned int *a, int *num_int) {
  if (num < 32) {
    *num_int = 0;
    *a = *a << num;
  } else if (32 <= num && num < 64) {
    *num_int = 1;
    *a = *a << (num - 32);
  } else if (64 <= num && num < 96) {
    *num_int = 2;
    *a = *a << (num - 64);
  } else if (96 <= num && num < 128) {
    *num_int = 3;
    *a = *a << (num - 96);
  } else if (128 <= num && num < 160) {
    *num_int = 4;
    *a = *a << (num - 128);
  } else if (160 <= num && num < 192) {
    *num_int = 5;
    *a = *a << (num - 160);
  } else if (192 <= num && num < 224) {
    *num_int = 6;
    *a = *a << (num - 192);
  } else if (224 <= num && num < 256) {
    *num_int = 7;
    *a = *a << (num - 224);
  }
}

unsigned int get_scale(s21_decimal dec) {
  unsigned int shift = 0b11111111;
  unsigned int scale = dec.bits[3] & (shift << 16);
  return scale >> 16;
}

unsigned int get_scale_big(s21_decimal_big dec) {
  unsigned int shift = 0b11111111;
  unsigned int scale = dec.bits[7] & (shift << 16);
  return scale >> 16;
}
// Инвертирует всё кроме знака и степени
void invert_decimal_big(s21_decimal_big *value) {
  // value->bits[0] = ~value->bits[0] + 1;
  s21_decimal_big one;
  zeroing_big(&one);
  one.bits[0] = 1;
  for (int i = 0; i < 7; i++) {
    value->bits[i] = ~value->bits[i];
  }
  // printf("zalupa\n");
  // show_digits_big(value);
  add_fast_big(*value, one, value);
}

// void view_bit(unsigned int bits){
//     unsigned int a = 1;
//     for (int i = 31; i >= 0; i--)
//     {
//         printf("%d", ((bits & a << i) == 0 ? 0 : 1));
//     }
//     printf("\n");
// }

// void show_digits(s21_decimal *dts){
//     for(int i = 3; i >= 0; i--){
//         for(int j = 31; j >= 0; j--){
//             int bit = get_bit(dts, (i * 32) + j);
//             printf("%d", bit);
//         }
//         printf("_");
//         if(i == 3){
//             printf("\n");
//         }
//     }
//     printf("\n");
// }

// void show_digits_big(s21_decimal_big *dts){
//     for(int i = 7; i >= 0; i--){
//         for(int j = 31; j >= 0; j--){
//             int bit = get_bit_big(*dts, (i * 32) + j);
//             printf("%d", bit);
//         }
//         printf(" ");
//         if(i == 7 || i % 4 == 0 ){
//             printf("\n");
//         }
//         // if(i % 4 == 0){
//         //     printf('\n');
//         // }
//     }
//     printf("\n");
// }

void convert_big_decima(s21_decimal val, s21_decimal_big *new_val) {
  zeroing_big(new_val);
  new_val->bits[7] = val.bits[3];
  for (int i = 0; i < 3; i++) {
    new_val->bits[i] = val.bits[i];
  }
}

//Установка знака в dst
void set_sign(s21_decimal *dst, int src) { set_bit(dst, 127, src); }

int set_scale(s21_decimal *value, unsigned int scale) {
  int error = 0;
  if (scale > 28) error = 1;
  scale = scale << 16;
  value->bits[3] = value->bits[3] | scale;
  return error;
}

void set_scale_big(s21_decimal_big *value, unsigned int scale) {
  for (int shift = 16; shift <= 23; ++shift) {
    unsigned int mask = 0;
    mask = 1U << shift;
    if (scale > 0 && scale % 2 == 1) {
      value->bits[7] |= mask;
    } else {
      value->bits[7] &= ~mask;
    }
    scale /= 2;
  }
}

void set_scale_null(s21_decimal_big *value) {
  unsigned int scale = 0;
  value->bits[7] = value->bits[7] & scale;
}

int mul_10(s21_decimal_big *val) {
  int overflow = 0;
  s21_decimal_big copy_val1;
  s21_decimal_big copy_val2;

  zeroing_big(&copy_val1);
  zeroing_big(&copy_val2);

  copy_val1 = *val;
  copy_val2 = *val;

  overflow += bit_shift_big(&copy_val1, 3);
  overflow += bit_shift_big(&copy_val2, 1);

  overflow += add_big(copy_val1, copy_val2, val);

  return overflow;
}

void zeroing_decimal(s21_decimal *dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0;
  }
}

void zeroing_big(s21_decimal_big *dec) {
  for (int i = 0; i < 8; i++) {
    dec->bits[i] = 0;
  }
}

int is_zero(s21_decimal dec) {
  s21_decimal zero;
  int ans = 0;
  zeroing_decimal(&zero);
  if (s21_is_equal(zero, dec)) ans = 1;
  return ans;
}

// int shift_left_g(s21_decimal_big *val, int shift){
//     unsigned    in_next = 0;
//     unsigned    new_val = 0;

//     if(val->bits[7] >>(31 - shift) > 0){
//         return 1;
//     }
//     for(int i = 0; i < 7; i++){
//         new_val = val->bits[i] << shift;
//         new_val |= in_next;
//         in_next = val->bits[i] >> (31 - shift);
//         val->bits[i] = new_val;
//     }

//     return 0;
// }

int bit_shift_big(s21_decimal_big *val, int shift) {
  int error = 0;
  unsigned int temp = 0;
  for (int i = 223; i > (223 - shift); i--) {
    if (get_bit_big(*val, i) == 1) error = 1;
  }
  if (error == 0) {
    for (int k = 223 - shift; k >= 0; k--) {
      temp = get_bit_big(*val, k);
      set_bit_big(val, k + shift, temp);
    }
    for (int i = 0; i < shift; i++) set_bit_big(val, i, 0);
  }
  return error;
}

s21_decimal_big bit_shift_big_2(s21_decimal_big val, int shift) {
  int error = 0;
  unsigned int temp = 0;
  for (int i = 223; i > (223 - shift); i--) {
    if (get_bit_big(val, i) == 1) error = 1;
  }
  if (error == 0) {
    for (int k = 223 - shift; k >= 0; k--) {
      temp = get_bit_big(val, k);
      set_bit_big(&val, k + shift, temp);
    }
    for (int i = 0; i < shift; i++) set_bit_big(&val, i, 0);
  }
  return val;
}

unsigned get_sign(s21_decimal_big val) {
  unsigned sing = val.bits[7] >> 31;
  return sing;
}

unsigned get_sign_decimal(s21_decimal val) {
  unsigned sing = val.bits[3] >> 31;
  return sing;
}

int from_big_to_decimal(s21_decimal_big value, s21_decimal *result) {
  zeroing_decimal(result);
  int overflow = 0;
  if (((value.bits[3])) || (value.bits[4]) || (value.bits[5]) ||
      (value.bits[6])) {
    overflow = 1;
  } else {
    result->bits[0] = value.bits[0];
    result->bits[1] = value.bits[1];
    result->bits[2] = value.bits[2];
    result->bits[3] = value.bits[7];
  }
  if (overflow && get_bit_big(value, 255)) {
    overflow = 2;
  }
  return overflow;
}

void set_binary_number(s21_decimal *number, const char *string_number) {
  for (int i = 0; i < 96; i++) {
    set_bit(number, i, string_number[95 - i] - '0');
  }
}

int validity_check(s21_decimal value_1, s21_decimal value_2) {
  int error = 0;
  int null_check_one = s21_null_check_bits(value_1);
  int null_check_two = s21_null_check_bits(value_2);
  if (null_check_one != 0) error = null_check_one;
  if (null_check_two != 0) error = null_check_two;

  return error;
}

int s21_null_check_bits(s21_decimal value) {
  int res = 0;
  for (unsigned i = 96; i < 112; i++) {
    unsigned res1 = get_bit(&value, i);
    res = res1 + res;
  }
  for (unsigned i = 120; i < 127; i++) {
    unsigned res1 = get_bit(&value, i);
    res = res1 + res;
  }
  if (get_sign_decimal(value) == 1) {
    res *= -1;
  }
  return res == 0 ? 0 : res < 0 ? 2 : 1;
}

void sum_bit_big(s21_decimal_big res, s21_decimal_big *result) {
  for (int i = 0, in_next = 0; i < 32 * 7; i++) {
    int tmp = 0;
    int x = get_bit_big(*result, i);
    int y = get_bit_big(res, i);

    tmp = x + y + in_next;

    if (tmp > 1) {
      in_next = 1;
      tmp %= 2;
    } else {
      in_next = 0;
    }
    set_bit_big(result, i, tmp);
  }
}

int convert_to_int(s21_decimal val) {
  return get_sign_decimal(val) == 0 ? val.bits[0] : val.bits[0] * -1;
}
