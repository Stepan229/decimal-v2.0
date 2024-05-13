#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_greater_or_equal0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 0);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater_or_equal3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec2, i));
                        //   }
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 5);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 20);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 20);  //
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater_or_equal6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 1);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  //
                        //   printf("\n");
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec1, i));
                        //   }
                        //   printf("\n");
                        //   for (int i = 127; i >= 0; i--) {
                        //     printf("%d", get_bit(dec2, i));
                        //   }
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal8) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater_or_equal9) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater_or_equal10) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal11) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater_or_equal12) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater_or_equal13) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 28);  //
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "000000000000000000000000000000001111111111111111111111111111111111111111"
      "11111111111111111111111111111111111111111111111111111111";  //
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 1);
  set_scale(&dec2, 28);
  //  printf("\n");
  //  for (int i = 127; i >= 0; i--) {
  //    printf("%d", get_bit(&dec1, i));
  //  }
  //  printf("\n");
  //  for (int i = 127; i >= 0; i--) {
  //    printf("%d", get_bit(&dec2, i));
  //  }
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//первое больше
START_TEST(test_greater_or_equal14) {
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//первое больше
START_TEST(test_greater_or_equal15) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//второе больше
START_TEST(test_greater_or_equal16) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//одинаковые
START_TEST(test_greater_or_equal17) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^56
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//нули с офигеть какой большой степенью (Одинаковые)
START_TEST(test_greater_or_equal18) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//нули положительный и отрицательный (первое больше)
START_TEST(test_greater_or_equal19) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//самые большие отрицательные, с разными степенями
START_TEST(test_greater_or_equal20) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_s21_is_greater_or_equal(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_is_greater_or_equal");
  tc = tcase_create("case_s21_is_greater_or_equal");

  tcase_add_test(tc, test_greater_or_equal0);
  tcase_add_test(tc, test_greater_or_equal1);
  tcase_add_test(tc, test_greater_or_equal2);
  tcase_add_test(tc, test_greater_or_equal3);
  tcase_add_test(tc, test_greater_or_equal4);
  tcase_add_test(tc, test_greater_or_equal5);
  tcase_add_test(tc, test_greater_or_equal6);
  tcase_add_test(tc, test_greater_or_equal7);
  tcase_add_test(tc, test_greater_or_equal8);
  tcase_add_test(tc, test_greater_or_equal9);
  tcase_add_test(tc, test_greater_or_equal10);
  tcase_add_test(tc, test_greater_or_equal11);
  tcase_add_test(tc, test_greater_or_equal12);
  tcase_add_test(tc, test_greater_or_equal13);
  tcase_add_test(tc, test_greater_or_equal14);
  tcase_add_test(tc, test_greater_or_equal15);
  tcase_add_test(tc, test_greater_or_equal16);
  tcase_add_test(tc, test_greater_or_equal17);
  tcase_add_test(tc, test_greater_or_equal18);
  tcase_add_test(tc, test_greater_or_equal19);
  tcase_add_test(tc, test_greater_or_equal20);

  suite_add_tcase(s, tc);
  return s;
}
