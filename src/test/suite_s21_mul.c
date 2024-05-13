#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_mul0) {
  s21_decimal decimal1 = {{1, 0, 0, 0}};
  s21_decimal decimal2 = {{1, 0, 0, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, OK);
}
START_TEST(test_mul1) {
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "00000000000010100000000000000000"
      "00010100010010000100101111111110111010111100001010"
      "0111111000011000110100001001001011000001101111";
  int code = s21_mul(decimal1, decimal2, &result);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&result, i));
  }
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_mul2) {
  s21_decimal decimal1 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_mul3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000100000000000000000000000000000011";
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000001011";
  for (int i = 0; i < 96; i++) {
    set_bit(&dec2, i, string_number2[95 - i] - '0');
  }
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000101100000000"
      "000000000000000000100001";  // 8
  s21_mul(dec1, dec2, &res);
  // for (int i = 95; i >= 0; i--) {
  //   printf("%d", string_number_res[95 - i] - '0');
  // }
  // printf("\n");
  // for (int i = 95; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }

  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));  //-8
}
END_TEST
//
START_TEST(test_mul4) {
  // 20е степени максимальных чисел, первое с отричательной степенью
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000101000000000000000000001010001001000010010111111111011101011"
      "11000010100111111000011000110100001001001011000001101111";
  int code = s21_mul(decimal1, decimal2, &result);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&result, i));
  }
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&result, i));
  // }
  // printf("\n code = %d", code);

  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_mul5) {
  // 0xFFFFFFFF
  // 0x1C0000 - 28
  // 0x10000 - 1
  // число стремится к нулю
  s21_decimal decimal1 = {{2, 0, 0, 0x1C0000}};
  s21_decimal decimal2 = {{2, 0, 0, 0x10000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, &result);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&result, i));
  // }
  // printf("\n");
  // printf("%d\n", get_scale(result));
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_mul6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000101";  // 5
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000000000000000000011";  // 3
  for (int i = 0; i < 96; i++) {
    set_bit(&dec2, i, string_number2[95 - i] - '0');
  }
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001111";  // 15
  s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_eq(0, get_sign_decimal(res));
}
END_TEST

START_TEST(test_mul7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000100000000000000000000000000000011";  // 4294967299
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000000000011011001000000111";  // 111111
  for (int i = 0; i < 96; i++) {
    set_bit(&dec2, i, string_number2[95 - i] - '0');
  }
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000001101100100000011100000000"
      "000001010001011000010101";  // 477218111559189
  s21_mul(dec2, dec1, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);   //
  set_scale(&dec1, 1);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   //
  set_scale(&dec2, 1);  // 35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  // 1225 / 10 ^ 2
  char *string_number_res =
      "000000000000001000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000010011001001";
  s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);   //-35
  set_scale(&dec1, 1);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 35
  set_scale(&dec2, 1);  // 35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  //-1225 / 10 ^ 2
  char *string_number_res =
      "100000000000001000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000010011001001";
  s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul10) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 1
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);   //-35
  set_scale(&dec1, 0);  // 35/10^0
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000001111111111111111111111"
      "111111111111111111111111111111111111111111111111111111"
      "11111111111111111111";  // 79228162514264337593543950335
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 79228162514264337593543950335
  set_scale(&dec2, 0);  // 79228162514264337593543950335/10^0
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000001111111111111111111111"
      "111111111111111111111111111111111111111111111111111111"
      "11111111111111111111";  // 79228162514264337593543950335
  s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul11) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000111111111111111111111"
      "111111111111111111111111111111111111111111111111111111"
      "11111111111111111111";  //  39614081257132168796771975167
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);   //-39614081257132168796771975167
  set_scale(&dec1, 0);  // -39614081257132168796771975167/10^0
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000"
      "00000000000000000010";  // 10
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 2
  set_scale(&dec2, 0);  // 2/10^0
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111110";  //
  s21_mul(dec1, dec2, &res);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&dec1, i));
  // }
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // printf("%s", string_number_res);
  // printf("\n");
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "0000000000000000000000000000000011111111111111111111111"
      "1111111111111111111111111111111111111111111111111111111"
      "111111111111110111";  //  396140812571321687967719751671
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);   //-39614081257132168796771975167
  set_scale(&dec1, 0);  // -39614081257132168796771975167/10^0
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000000000000000"
      "00000000000000000010";  // 2
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 2
  set_scale(&dec2, 0);  // 2/10^0
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";
  s21_decimal res = {{0, 0, 0, 0}};
  int code = s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_mul13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000001010010111010101111011"
      "1011001100100100011011";  //  11396140812571
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);    //-11396140812571
  set_scale(&dec1, 14);  // -11396140812571/10^14 = 0.11396140812571
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100111";  // 39
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);    // 39
  set_scale(&dec2, 14);  // 39/10^14 = 0.00000000000039
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "1000000000011100000000000000000000000000000000000000000000000"
      "0000000000000000001100101000011100101110110000100101010001100011"
      "101";  // 4.44449491690269/10^14 =
              // 0.0000000000000444449491690269
  s21_mul(dec1, dec2, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000001010010111010101111011"
      "1011001100100100011011";  //  11396140812571
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);    //-11396140812571
  set_scale(&dec1, 15);  // -11396140812571/10^15 = 0.011396140812571
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100111";  // 39
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);    // 39
  set_scale(&dec2, 14);  // 39/10^14 = 0.00000000000039
  s21_decimal res = {{0, 0, 0, 0}};
  s21_decimal res_21 = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000001110000000000000000000000000000000000000000000000000000000000"
      "00000000001010000110110000100101011010000100001110000011";
  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number_res[127 - i] - '0');
  }
  set_sign(&res, 1);  // 39
  set_scale(&res, 28);
  int code = s21_mul(dec1, dec2, &res_21);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res_21, i));
  // }
  // printf("\n");
  ck_assert_int_eq(code, OK);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&res, i), get_bit(&res_21, i));
  }
}

START_TEST(test_mul15) {
  // 28-е степени
  s21_decimal decimal1 = {{0, 0, 0, 0}};
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  //
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_eq(code, OK);
  // for (int i = 0; i < 128; i++) {
  //   printf("%d", get_bit(&result, i));
  // }
  // printf("\n%d\n", get_scale(result));
}
END_TEST

START_TEST(test_mul16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      // 79228162514264337593543950335
      "000000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100111";  // 39
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 39
  set_scale(&dec2, 6);  // 39/10^2 = 0.000039
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000110001111010111000010100011110101110000"
      "10100011110101110000101000111101011100001010001111010111";
  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number_res[127 - i] - '0');
  }
  set_sign(&res, 1);
  set_scale(&res, 4);
  s21_decimal s21res = {{0, 0, 0, 0}};
  s21_mul(dec1, dec2, &s21res);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&s21res, i));
  // }
  // printf("\n");
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&s21res, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      // 792281625142643375935
      "000000000000000000000000000000000000000000000000000000000010101011110011"
      "00011101110001000110000100011000011100111011111100111111";
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100111";  // 39
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 39
  set_scale(&dec2, 6);  // 39/10^2 = 0.000039
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "00000000000000000000000000000000000000000000000000"
      "00011010001011000010011000100"
      "011101010110010101011100"
      "1101000100010001010011001";
  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number_res[127 - i] - '0');
  }
  set_sign(&res, 1);
  set_scale(&res, 6);
  s21_decimal s21res = {{0, 0, 0, 0}};
  s21_mul(dec1, dec2, &s21res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&s21res, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul18) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      // 792281625142643375935567
      "000000000000000000000000000000000000000000000000101001111100010110101100"
      "01000111000110110100011110000100001000110001000001001111";
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000101011010";  // 346
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);    // 346
  set_scale(&dec2, 10);  // 346/10^10 = 0.0000000346
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "00000000000000000000000000000000000000001110001011"
      "0000010010101011011000000110101101111010"
      "10100010010111011001000000101011000110";
  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number_res[127 - i] - '0');
  }
  set_sign(&res, 0);
  set_scale(&res, 10);
  s21_decimal s21res = {{0, 0, 0, 0}};
  s21_mul(dec1, dec2, &s21res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&s21res, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul19) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      // 79228162514264
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000010010000000111010111110011110111001110101011000";
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 21);
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000010100000111101110"
      "1111100101101110110111";  // 345673456567
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);   // 346
  set_scale(&dec2, 8);  // 346/10^10 = 0.0000000346
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number3 =
      "000000000001110000000000000000000000000000000010010000"
      "111111000110011110011111011010101100110101100111011101"
      "11000110000000110001";  // 27387072793757654321971688
                               // 0.0 027 387 072 793 757 655

  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number3[127 - i] - '0');
  }
  set_sign(&res, 1);
  set_scale(&res, 28);
  s21_decimal s21res = {{0, 0, 0, 0}};
  s21_mul(dec1, dec2, &s21res);
  // printf("scale = %d\n", get_scale(s21res));
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&s21res, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_mul20) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      // 33333333333333333333333333333
      "000000000000000000000000000000000110101110110100101011111110010011001111"
      "00100110000001111110111000110101010101010101010101010101";
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 15);  // 33333333333333.333333333333333
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 1
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);    //
  set_scale(&dec2, 10);  // 0.000000001
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number3 =
      "000000000000000000000000000000000110101110110100101011111110010011001111"
      "00100110000001111110111000110101010101010101010101010101";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&res, i, string_number3[127 - i] - '0');
  }
  set_sign(&res, 1);
  set_scale(&res, 25);
  s21_decimal s21res = {{0, 0, 0, 0}};
  s21_mul(dec1, dec2, &s21res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&s21res, i), get_bit(&res, i));
  }
  // printf("scale = %d\n", get_scale(s21res));
}
END_TEST

START_TEST(test_mul21) {
  // -1/10^28
  s21_decimal decimal1 = {{0x1, 0, 0, 0xE0001}};
  // самое большое положительное/10^28
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  s21_decimal result = {{0, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, &result);
  // код ошибки - 2
  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_mul22) {
  // самое большое положительное
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, &result);
  // слишком большое число
  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_mul23) {
  // самое маленькое отрицательное
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 1}};
  // самое большое положительное
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  s21_decimal result = {{0, 0, 0, 0}};
  int code = s21_mul(decimal1, decimal2, &result);
  // слишком маленькое число
  // printf("%d\n", code);
  ck_assert_int_ne(code, OK);
}
END_TEST

START_TEST(test_mul24) {
  s21_decimal decimal2 = {{0, 0, 0, 1000000000}};
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int code = s21_mul(decimal1, decimal2, &result);
  ck_assert_int_ne(code, OK);
}
END_TEST

Suite *suite_s21_mul(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_mul");
  tc = tcase_create("case_mul");

  tcase_add_test(tc, test_mul0);
  tcase_add_test(tc, test_mul1);
  tcase_add_test(tc, test_mul2);
  tcase_add_test(tc, test_mul3);
  tcase_add_test(tc, test_mul4);
  tcase_add_test(tc, test_mul5);
  tcase_add_test(tc, test_mul6);
  tcase_add_test(tc, test_mul7);
  tcase_add_test(tc, test_mul8);
  tcase_add_test(tc, test_mul9);
  tcase_add_test(tc, test_mul10);
  tcase_add_test(tc, test_mul11);
  tcase_add_test(tc, test_mul12);
  tcase_add_test(tc, test_mul13);
  tcase_add_test(tc, test_mul14);
  tcase_add_test(tc, test_mul15);
  tcase_add_test(tc, test_mul16);
  tcase_add_test(tc, test_mul17);
  tcase_add_test(tc, test_mul18);
  tcase_add_test(tc, test_mul19);
  tcase_add_test(tc, test_mul20);
  tcase_add_test(tc, test_mul21);
  tcase_add_test(tc, test_mul22);
  tcase_add_test(tc, test_mul23);
  tcase_add_test(tc, test_mul24);

  suite_add_tcase(s, tc);
  return s;
}