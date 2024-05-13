
#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_truncate0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 1);  // 35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000011";  // 3
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000100";  // 4
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 1);  // 4/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";  // 0
  s21_truncate(dec1, &res);

  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000010011";  // 19
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 1);  // 10/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 1
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000010000001001111110011"
      "1001011110001111100"
      "01001010000001001100001000011111111111111111111111111"
      "111";  // 19999999999999999999999999999
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 28);  // 19999999999999999999999999999/10^28
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 1
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000010000001001111110011"
      "1001011110001111100"
      "01001010000001001100001000011111111111111111111111111"
      "111";  // 19999999999999999999999999999
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);    // -19999999999999999999999999999
  set_scale(&dec1, 28);  // -19999999999999999999999999999/10^28
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // -1
  s21_truncate(dec1, &res);
  //   for (int i = 127; i >= 0; i--) {
  //     printf("%d", string_number_res[127 - i] - '0');
  //   }
  //   printf("\n");
  //   for (int i = 127; i >= 0; i--) {
  //     printf("%d", get_bit(&res, i));
  //   }
  //   printf("\n");
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000101000011000111100000111110101110011011010"
      "11100100001011111001010100111111111111111111111111111111";  // 5
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 29);
  s21_decimal res = {{0, 0, 0, 0}};
  int x = s21_truncate(dec1, &res);

  ck_assert_int_eq(x, OK);
}
END_TEST

START_TEST(test_truncate6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000100000010011111100111"
      "001011110001111100010010100000010011000010000111111111"
      "11111111111111111111";  // 19999999999999999999999999999
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);     // -19999999999999999999999999999
  set_scale(&dec1, -28);  // -19999999999999999999999999999/10^28
  s21_decimal res = {{0, 0, 0, 0}};
  int x = s21_truncate(dec1, &res);

  ck_assert_int_eq(x, OK);
}
END_TEST

START_TEST(test_truncate7) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 13);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(-0.4744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate8) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 12);  // 4.74444444444
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(4.744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010011101101000001"
      "0011101000000100100011";  // 4736548765987
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 11);  // -4736548765987/10^11
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000101111";  // -47
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate10) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000001111111111111111111111"
      "111111111111111111111111111111111111111111111111111111"
      "11111111111111111111";  // 79228162514264337593543950335
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 28);  // -79228162514264337593543950335/10^28 =
                         // -7.9228162514264337593543950335
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000111";  // -7
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate11) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000001110111111011000000110"
      "001101000011100000111011010111111011001111011101111111"
      "11111111111111111111";  // 74228162514264337593543950335
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 28);  // 74228162514264337593543950335/10^28 =
                         // 7.4228162514264337593543950335
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000111";  // 7
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate12) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&dec1, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000001110011000100110100011"
      "100001101100000001011110111111111000011000101111111111"
      "11111111111111111111";  // 71228162514264337593543950335
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 28);  // -71228162514264337593543950335/10^28 =
                         // -7.1228162514264337593543950335
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000111";  // -7
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000001010100111"
      "01001000111000011001";  // 71228162514
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 28);  // -71228162514/10^28 =
                         // -0.00000000771228162514
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";  // 0
  s21_truncate(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_truncate15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000001010100111"
      "01001000111000011001";  // 71228162514
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 28);  // -71228162514/10^28 =
                         // -0.00000000771228162514
  s21_decimal *res = NULL;
  int code = s21_truncate(dec1, res);
  ck_assert_int_eq(ERROR_CONVERT, code);
}
END_TEST

START_TEST(test_truncate16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  s21_decimal res = {{0, 0, 0, 0}};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(test_truncate17) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 10);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(-474.4444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate18) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 14);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(-0.04744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate19) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 14);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(0.04744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate20) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 12);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(4.744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate21) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 12);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(-4.744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate22) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 11);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(-47.44444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate23) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 11);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(47.44444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate24) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 10);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(474.4444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_truncate25) {
  s21_decimal dec = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_truncate(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = trunc(0);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

Suite *suite_s21_truncate(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_truncate");
  tc = tcase_create("case_s21_truncate");

  tcase_add_test(tc, test_truncate0);
  tcase_add_test(tc, test_truncate1);
  tcase_add_test(tc, test_truncate2);
  tcase_add_test(tc, test_truncate3);
  tcase_add_test(tc, test_truncate4);
  tcase_add_test(tc, test_truncate5);
  tcase_add_test(tc, test_truncate6);
  tcase_add_test(tc, test_truncate7);
  tcase_add_test(tc, test_truncate8);
  tcase_add_test(tc, test_truncate9);
  tcase_add_test(tc, test_truncate10);
  tcase_add_test(tc, test_truncate11);
  tcase_add_test(tc, test_truncate12);
  tcase_add_test(tc, test_truncate13);
  tcase_add_test(tc, test_truncate14);
  tcase_add_test(tc, test_truncate15);
  tcase_add_test(tc, test_truncate16);
  tcase_add_test(tc, test_truncate17);
  tcase_add_test(tc, test_truncate18);
  tcase_add_test(tc, test_truncate19);
  tcase_add_test(tc, test_truncate20);
  tcase_add_test(tc, test_truncate21);
  tcase_add_test(tc, test_truncate22);
  tcase_add_test(tc, test_truncate23);
  tcase_add_test(tc, test_truncate24);
  tcase_add_test(tc, test_truncate25);

  suite_add_tcase(s, tc);
  return s;
}
