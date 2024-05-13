
#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_round0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000101100010";  // 354
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 2);  // 35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000100";  // 4
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000"
      "00000000000001000100111011010000010011101000000100100"
      "011";  // 4736548765987
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 11);  // 4736548765987/10^11
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000101111";  // 47
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 11);  // 4744444444445/10^11 = 47.44444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000101111";  // 47
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 13);  // 4744444444445/10^13 = 0.4744444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";  // 0
  s21_round(dec1, &res);
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", string_number_res[127 - i] - '0');
  // }
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000101001110010111101110"
      "0100100000111100011101";  // 5744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 13);  // 5744444444445/10^13 = 0.5744444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 1
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000101001110010111101110"
      "0100100000111100011101";  // 5744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 13);  // -5744444444445/10^13 = -0.5744444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // -1
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000101100010";  // 354
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 2);  // -35/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000100";  // -4
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "0000000000000000000"
      "00000000000001000100111011010000010011101000000100100"
      "011";  // 4736548765987
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 11);  // -4736548765987/10^11
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000101111";  // -47
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round8) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 11);  // -4744444444445/10^11 = -47.44444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000101111";  // -47
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, -1);
  set_scale(&dec1, 13);  // -4744444444445/10^13 = -0.4744444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000000";  // 0
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round10) {
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
  s21_round(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-0.4744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round11) {
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
  s21_round(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-47.44444444445);
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", string_number_res[127 - i] - '0');
  // }
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // printf("%d\n", orig_round);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round12) {
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
      "00000000000000000000000000000000000000000000000000001000";  // -8
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round13) {
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
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&dec1, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_round15) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000100"
      "010101110001011001111011";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(7281625.1);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round16) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000101100"
      "001111100101000110011000";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(74228162.4);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round17) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000101100"
      "001111100101000110011001";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 1);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-74228162.5);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round18) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 2);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-742281625.14);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round19) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 3);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-74228162.514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round20) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 3);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(74228162.514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round21) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 7);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(7422.8162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round22) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 7);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-7422.8162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round23) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 6);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(-74228.162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round24) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000001000101001000"
      "010101111101111111010010";  // 74228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec1, i, string_number1[95 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 6);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_round(dec1, &res);
  int s21_res = convert_to_int(res);
  int orig_round = round(74228.162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_round25) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 6);
  s21_decimal *res = NULL;
  int code = s21_round(dec, res);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_s21_round(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_round");
  tc = tcase_create("case_s21_round");

  tcase_add_test(tc, test_round0);
  tcase_add_test(tc, test_round1);
  tcase_add_test(tc, test_round2);
  tcase_add_test(tc, test_round3);
  tcase_add_test(tc, test_round4);
  tcase_add_test(tc, test_round5);
  tcase_add_test(tc, test_round6);
  tcase_add_test(tc, test_round7);
  tcase_add_test(tc, test_round8);
  tcase_add_test(tc, test_round9);
  tcase_add_test(tc, test_round10);
  tcase_add_test(tc, test_round11);
  tcase_add_test(tc, test_round12);
  tcase_add_test(tc, test_round13);
  tcase_add_test(tc, test_round14);
  tcase_add_test(tc, test_round15);
  tcase_add_test(tc, test_round16);
  tcase_add_test(tc, test_round17);
  tcase_add_test(tc, test_round18);
  tcase_add_test(tc, test_round19);
  tcase_add_test(tc, test_round20);
  tcase_add_test(tc, test_round21);
  tcase_add_test(tc, test_round22);
  tcase_add_test(tc, test_round23);
  tcase_add_test(tc, test_round24);
  tcase_add_test(tc, test_round25);

  suite_add_tcase(s, tc);
  return s;
}
