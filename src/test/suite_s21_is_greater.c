#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_greater0) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater1) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater2) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater3) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater4) {
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);  // 35/10^1
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec2, 0);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater5) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater6) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater7) {
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
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater8) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater9) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_greater10) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 1);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 1);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater11) {
  s21_decimal dec1 = {{2, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{1, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_greater12) {
  s21_decimal dec1 = {{1, 0, 0, 0}};
  set_sign(&dec1, 0);
  s21_decimal dec2 = {{2, 0, 0, 0}};
  set_sign(&dec2, 0);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//самые большие отрицательные, с разными степенями
START_TEST(test_greater13) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//первое больше
START_TEST(test_greater14) {
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//первое больше
START_TEST(test_greater15) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//второе больше
START_TEST(test_greater16) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);
  set_sign(&dec2, 1);
  set_scale(&dec2, 56);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//одинаковые
START_TEST(test_greater17) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^56
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//нули с офигеть какой большой степенью (Одинаковые)
START_TEST(test_greater18) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//нули положительный и отрицательный (первое больше)
START_TEST(test_greater19) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 16);
  set_sign(&dec2, 1);
  set_scale(&dec2, 16);
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

Suite *suite_s21_is_greater(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_is_greater");
  tc = tcase_create("case_s21_is_greater");

  tcase_add_test(tc, test_greater0);
  tcase_add_test(tc, test_greater1);
  tcase_add_test(tc, test_greater2);
  tcase_add_test(tc, test_greater3);
  tcase_add_test(tc, test_greater4);
  tcase_add_test(tc, test_greater5);
  tcase_add_test(tc, test_greater6);
  tcase_add_test(tc, test_greater7);
  tcase_add_test(tc, test_greater8);
  tcase_add_test(tc, test_greater9);
  tcase_add_test(tc, test_greater10);
  tcase_add_test(tc, test_greater11);
  tcase_add_test(tc, test_greater12);
  tcase_add_test(tc, test_greater13);
  tcase_add_test(tc, test_greater14);
  tcase_add_test(tc, test_greater15);
  tcase_add_test(tc, test_greater16);
  tcase_add_test(tc, test_greater17);
  tcase_add_test(tc, test_greater18);
  tcase_add_test(tc, test_greater19);

  suite_add_tcase(s, tc);
  return s;
}
