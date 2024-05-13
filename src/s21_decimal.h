#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_decimal_big;

typedef enum error_arithmetic {
  TEST_ARITHMETIC_OK,
  TEST_ARITHMETIC_BIG,
  TEST_ARITHMETIC_SMALL,
  TEST_ARITHMETIC_ZERO_DIV
} Arithmetic;

typedef enum error_convert {
  OK,
  ERROR_CONVERT,
  NUMBER_MAX_INF = 1,
  NUMBER_MIN_INF
} Convert;

// Математика
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
s21_decimal mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int decimal2int(s21_decimal src, int *dst);
int int2decimal(int src, s21_decimal *dst);

void norm_byte_a(int num, unsigned int *a, int *num_int);

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

int normalize(s21_decimal_big *value_1, s21_decimal_big *value_2);

// Сравнение
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);

// Вспомогательные
int is_zero(s21_decimal dec);
void zeroing_decimal(s21_decimal *dec);
// int mul_10(s21_decimal value_1, s21_decimal *result); //пока убрал ниже
// указано

unsigned int get_bit(s21_decimal *decimal, int num);
int set_bit(s21_decimal *decimal, int num, int bit);
int set_scale(s21_decimal *value, unsigned int scale);
unsigned int get_scale(s21_decimal dec);
void set_sign(s21_decimal *dst, int src);

int set_bit_int(unsigned int *bits, int num, int bit);
int get_bit_int(unsigned int value, int i);
void bank_round(s21_decimal *val_1);

// Для тестов
// void view_bit(unsigned int);
// void show_digits(s21_decimal *dts);
s21_decimal mod_for_add(s21_decimal value_1, s21_decimal value_2,
                        s21_decimal *result);
s21_decimal s21_add_2(s21_decimal value_1, s21_decimal value_2,
                      s21_decimal *result);
// s21_decimal shift_right_g(s21_decimal val, int shift);
// int shift_left_g(s21_decimal *val, int shift);
s21_decimal mod_10(s21_decimal n, s21_decimal *rem);
s21_decimal bit_shift_right(s21_decimal val, int shift);

// big decimal
void convert_big_decima(s21_decimal val, s21_decimal_big *new_val);

unsigned get_sign(s21_decimal_big val);
unsigned get_sign_decimal(s21_decimal val);

void set_scale_big(s21_decimal_big *value, unsigned int scale);

unsigned int get_bit_big(s21_decimal_big decimal, int num);
void norm_byte_big(int num, unsigned int *a, int *num_int);
int set_bit_big(s21_decimal_big *decimal, int num, int bit);
int is_less_big(s21_decimal_big value_1, s21_decimal_big value_2);
unsigned int get_scale_big(s21_decimal_big dec);
void invert_decimal_big(s21_decimal_big *value);

// void show_digits_big(s21_decimal_big *dts);
void zeroing_big(s21_decimal_big *dec);
int is_zero(s21_decimal dec);
// int shift_left_g(s21_decimal_big *val, int shift);

int add_big(s21_decimal_big value_1, s21_decimal_big value_2,
            s21_decimal_big *result);
int bit_shift_big(s21_decimal_big *val, int shift);
int is_equal_big(s21_decimal_big value_1, s21_decimal_big value_2);
s21_decimal_big mod_big(s21_decimal_big value_1, s21_decimal_big value_2,
                        s21_decimal_big *result);

int sub_big(s21_decimal_big value_1, s21_decimal_big value_2,
            s21_decimal_big *result);
s21_decimal_big bit_shift_big_2(s21_decimal_big val, int shift);

void add_fast_big(s21_decimal_big value_1, s21_decimal_big value_2,
                  s21_decimal_big *result);
void set_scale_null(s21_decimal_big *value);
//////////////////////////////////////
int from_big_to_decimal(s21_decimal_big value, s21_decimal *result);
void set_binary_number(s21_decimal *number, const char *string_number);

// Fast

int is_greater_or_equal_fast_big(s21_decimal_big val1, s21_decimal_big val2);
int is_greater_fast_big(s21_decimal_big val1, s21_decimal_big val2);
int is_equal_fast_big(s21_decimal_big val1, s21_decimal_big val2);

int round_banker_big(s21_decimal_big *result);
int is_equal_fast(s21_decimal val1, s21_decimal val2);
int mul_10(s21_decimal_big *val);

int validity_check(s21_decimal value_1, s21_decimal value_2);
int s21_null_check_bits(s21_decimal value);
void sum_bit_big(s21_decimal_big res, s21_decimal_big *result);
int is_equal_null(s21_decimal_big *value_1, s21_decimal_big *value_2);

int add_fast(s21_decimal val1, s21_decimal val2, s21_decimal *result);

int is_equal_fast(s21_decimal val1, s21_decimal val2);

int convert_to_int(s21_decimal val);

int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
#endif
