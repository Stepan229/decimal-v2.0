#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(add_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-5

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001000";  // 8

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-8
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001000";  // 8

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 8
  ck_assert_int_eq(1, 1);                      //-8

  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-5

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 5

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 2
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-5

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-2
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 3

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-5

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-2
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-3

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 5

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000010";  // 2

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 2
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000101110011100011010110101011010011110011100"
      "010111101110011100001101";  // 53546345635434653453
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 53546345635434653453

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000111101110110001010101101110010000010000100110001"
      "011001110110001010001100";  // 4563456345637835465356
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 4563456345637835465356

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000111110100100100111001000100111011100100011001101"
      "110001100100100110011001";  // 4617002691273270118809

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 4617002691273270118809
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000101110011100011010110101011010011110011100"
      "010111101110011100001101";  // 53546345635434653453
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-53546345635434653453

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000111101110110001010101101110010000010000100110001"
      "011001110110001010001100";  // 4563456345637835465356
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-4563456345637835465356

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000111110100100100111001000100111011100100011001101"
      "110001100100100110011001";  // 4617002691273270118809

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-4617002691273270118809
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_10) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-535463456354346534535687826

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 463456354346534535687826123

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-72007102007811998847861703
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_11) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000011011101011101100110011000010001000011111111000011100011011111010"
      "111000111110111010010010";  // 535463456354346534535687826
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 535463456354346534535687826

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000010111111101011100101100110100111111001101111100011111101100110010"
      "010110111110101011001011";  // 463456354346534535687826123
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-463456354346534535687826123

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000011101110010000000110001101001001010001111011111100101111001000"
      "100010000000001111000111";  // 72007102007811998847861703

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 72007102007811998847861703
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000110011001100110011001100110011001100110011001100110011001100110011001"
      "100110011001100110011010";  // 7922816251426433759354395034
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 7922816251426433759354395034
  set_scale(&dec1, 27);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000010101";  // 21
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 21
  set_scale(&dec2, 28);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000110011001100110011001100110011001100110011001100110011001100110011001"
      "100110011001100110011100";  // 7922816251426433759354395034

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 7922816251426433759354395036
  ck_assert_int_eq(get_scale(dec1), get_scale(res));  // 27
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000110011001100110011001100110011001100110011001100110011001100110011001"
      "100110011001100110011010";  // 7922816251426433759354395034
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 7922816251426433759354395034
  set_scale(&dec1, 27);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 1
  set_scale(&dec2, 28);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000110011001100110011001100110011001100110011001100110011001100110011001"
      "100110011001100110011010";  // 7922816251426433759354395034

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 7922816251426433759354395034
  ck_assert_int_eq(get_scale(dec1), get_scale(res));  // 27
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 1
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000111001101010011000111110101100011100101101010000110011101011010000001"
      "100110011001100110011001";  // 8922816251426433759354395033

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }

  ck_assert_int_eq(0, get_sign_decimal(res));  // 8922816251426433759354395033
  ck_assert_int_eq(27, get_scale(res));        // 27
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_BIG, response);  // too big
}
END_TEST

START_TEST(add_16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111011";  // 79228162514264337593543950331

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 79228162514264337593543950331
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-79228162514264337593543950334
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-3
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_SMALL, response);  // too small
}
END_TEST

START_TEST(add_18) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 3
  set_scale(&dec1, 0);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 1);  //-79228162514264337593543950334
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111011";  // 79228162514264337593543950331

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-79228162514264337593543950331
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_19) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-79228162514264337593543950334
  set_scale(&dec1, 28);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000001";  // 1
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 1
  set_scale(&dec2, 0);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "110111111011000000110001101000011100000111011010111111011001111011101111"
      "111111111111111111111110";  // 69228162514264337593543950334

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(1, get_sign_decimal(res));  //-69228162514264337593543950334
  ck_assert_int_eq(28, get_scale(res));        // 28
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_20) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 2);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000111110101";  // 501
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 501
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111111";  // 79228162514264337593543950335

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 79228162514264337593543950335
  ck_assert_int_eq(2, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_21) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 2);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000111110100";  // 500
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 500
  set_scale(&dec2, 5);

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111111111111111111111111111111111111111111111111111"
      "111111111111111111111110";  // 79228162514264337593543950334

  int response = s21_add(dec1, dec2, &res);

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  // 79228162514264337593543950334
  ck_assert_int_eq(2, get_scale(res));
  ck_assert_int_eq(TEST_ARITHMETIC_OK, response);
}
END_TEST

START_TEST(add_22) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000111110100";  // 79228162514264337593543950334
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 79228162514264337593543950334
  set_scale(&dec1, 2);

  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000111111111";  // 500
  set_binary_number(&dec2, string_number2);
  set_sign(&dec2, 0);  // 500
  set_scale(&dec2, 5);

  s21_decimal *res = NULL;
  int response = s21_add(dec1, dec2, res);
  ck_assert_int_eq(ERROR_CONVERT, response);
}
END_TEST

Suite *suite_s21_add(void) {
  Suite *s = suite_create("add");
  TCase *tc = tcase_create("add");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, add_1);
  tcase_add_test(tc, add_2);
  tcase_add_test(tc, add_3);
  tcase_add_test(tc, add_4);
  tcase_add_test(tc, add_5);
  tcase_add_test(tc, add_6);
  tcase_add_test(tc, add_7);
  tcase_add_test(tc, add_8);
  tcase_add_test(tc, add_9);
  tcase_add_test(tc, add_10);
  tcase_add_test(tc, add_11);
  tcase_add_test(tc, add_12);
  tcase_add_test(tc, add_13);
  tcase_add_test(tc, add_14);
  tcase_add_test(tc, add_15);
  tcase_add_test(tc, add_16);
  tcase_add_test(tc, add_17);
  tcase_add_test(tc, add_18);
  tcase_add_test(tc, add_19);
  tcase_add_test(tc, add_20);
  tcase_add_test(tc, add_21);
  tcase_add_test(tc, add_22);
  return s;
}
