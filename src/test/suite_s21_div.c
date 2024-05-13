#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(div_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5
  set_scale(&dec1, 1);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000100";  // 4
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 4
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111101";  // 125

  int response = s21_div(dec1, dec2, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }

  ck_assert_int_eq(0, get_sign_decimal(res));  // 125
  ck_assert_int_eq(3, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5
  set_scale(&dec1, 5);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "001101011101101001010111111100100110011110010011000000111111011100011010"
      "101010101010101010101011";  // 16666666666666666666666666667

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 16666666666666666666666666667
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5
  set_scale(&dec1, 7);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =

      "000000001000100111011101000010100001101010100010110000000000101000100110"
      "101010101010101010101011";  // 16666666666666666666666666667

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 166666666666666666666666667
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-5
  set_scale(&dec1, 2);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000100";  // 4
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-4
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000001111101";  // 125

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 125
  ck_assert_int_eq(4, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000010101100010101000100110010100001010010110111000000001100101100000101"
      "010101010101010101010101";  // 3333333333333333333333333333

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 3333333333333333333333333333
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 79228162514264337593543950335
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000001";  // 1

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 1
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111110101";  // 79228162514264337593543950325
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950325
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 79228162514264337593543950335
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "001000000100111111001110010111100011111000100101000000100110000100001111"
      "111111111111111111111111";  // 9999999999999999999999999999

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 9999999999999999999999999999
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000010";  // 2
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 2
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 5
  ck_assert_int_eq(1, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000010";  // 2
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 2
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 5
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_10) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000010";  // 2
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 2
  set_scale(&dec2, 2);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000110010";  // 50

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 50
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_11) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000010";  // 2
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 2
  set_scale(&dec2, 4);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000001001110001000";  // 5000

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 5000
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  // 1
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 3
  set_scale(&dec2, 4);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "011010111011010010101111111001001100111100100110000001111110111000110101"
      "010101010101010101010101";  // 33333333333333333333333333333

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 33333333333333333333333333333
  ck_assert_int_eq(25, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001010";  // 10
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 10
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 10
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(div_15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 10
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(2, response);
}
END_TEST

START_TEST(div_16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000000";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 0
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(3, response);
}
END_TEST

START_TEST(div_17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000000";  // 0
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 0
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(3, response);
}
END_TEST

START_TEST(div_18) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000001";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 0
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 0
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(div_19) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 1
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 0
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_div(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(3, response);
}
END_TEST

Suite *suite_s21_div(void) {
  Suite *s = suite_create("div");
  TCase *tc = tcase_create("div");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, div_1);
  tcase_add_test(tc, div_2);
  tcase_add_test(tc, div_3);
  tcase_add_test(tc, div_4);
  tcase_add_test(tc, div_5);
  tcase_add_test(tc, div_6);
  tcase_add_test(tc, div_7);
  tcase_add_test(tc, div_8);
  tcase_add_test(tc, div_9);
  tcase_add_test(tc, div_10);
  tcase_add_test(tc, div_11);
  tcase_add_test(tc, div_12);
  tcase_add_test(tc, div_13);
  tcase_add_test(tc, div_14);
  tcase_add_test(tc, div_15);
  tcase_add_test(tc, div_16);
  tcase_add_test(tc, div_17);
  tcase_add_test(tc, div_18);
  tcase_add_test(tc, div_19);
  return s;
}
