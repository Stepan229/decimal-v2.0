#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(sub_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 2
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 3
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 5
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-2
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-5
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-2
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-3
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-5
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 2
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 5
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-5
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-5
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 535463456354346534535687826
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 463456354346534535687826123
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 72007102007811998847861703
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 463456354346534535687826123
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 535463456354346534535687826
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-72007102007811998847861703
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-535463456354346534535687826
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-463456354346534535687826123
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-72007102007811998847861703
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_10) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-463456354346534535687826123
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-535463456354346534535687826
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 72007102007811998847861703
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_11) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-535463456354346534535687826
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 463456354346534535687826123
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000110011101001001001011111110111000111101101110100111100001000101101"
      "001111111101100101011101";  // 998919810700881070223513949

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-998919810700881070223513949
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 535463456354346534535687826
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-463456354346534535687826123
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000110011101001001001011111110111000111101101110100111100001000101101"
      "001111111101100101011101";  // 998919810700881070223513949

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 998919810700881070223513949
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111011";  // 79228162514264337593543950331

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 79228162514264337593543950331
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(sub_15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(2, response);
}
END_TEST

START_TEST(sub_16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 1
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "110111111011000000110001101000011100000111011010111111011001111011101111"
      "111111111111111111111110";  // 69228162514264337593543950334

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 69228162514264337593543950334
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-1
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "110111111011000000110001101000011100000111011010111111011001111011101111"
      "111111111111111111111110";  // 69228162514264337593543950334

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 69228162514264337593543950334
  ck_assert_int_eq(28, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_18) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000001";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-1
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000111001101010011000111110101100011100101101010000110011101011010000001"
      "100110011001100110011001";  // 8922816251426433759354395033

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 8922816251426433759354395033
  ck_assert_int_eq(27, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_19) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950335
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000110";  // 6
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 6
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 7922816251426433759354395035
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_20) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950335
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000110";  // 6
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  // 6
  set_scale(&dec2, 1);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(sub_21) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000110";  // 6
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 6
  set_scale(&dec1, 1);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 79228162514264337593543950335
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(sub_22) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 3
  set_scale(&dec1, 1);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 79228162514264337593543950335
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950334

  int response = s21_sub(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *s = suite_create("sub");
  TCase *tc = tcase_create("sub");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sub_1);
  tcase_add_test(tc, sub_2);
  tcase_add_test(tc, sub_3);
  tcase_add_test(tc, sub_4);
  tcase_add_test(tc, sub_5);
  tcase_add_test(tc, sub_6);
  tcase_add_test(tc, sub_7);
  tcase_add_test(tc, sub_8);
  tcase_add_test(tc, sub_9);
  tcase_add_test(tc, sub_10);
  tcase_add_test(tc, sub_11);
  tcase_add_test(tc, sub_12);
  tcase_add_test(tc, sub_13);
  tcase_add_test(tc, sub_14);
  tcase_add_test(tc, sub_15);
  tcase_add_test(tc, sub_16);
  tcase_add_test(tc, sub_17);
  tcase_add_test(tc, sub_18);
  tcase_add_test(tc, sub_19);
  tcase_add_test(tc, sub_20);
  tcase_add_test(tc, sub_21);
  tcase_add_test(tc, sub_22);
  return s;
}
