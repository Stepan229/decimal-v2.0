#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

//одинаковые входные данные
START_TEST(test_equal0) {
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
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//одинаковые, но второе отрицательное
START_TEST(test_equal1) {
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
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);  // -35/10^1
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//одинаковые, со степенями
START_TEST(test_equal2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 25);  // 35/10^25
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^25
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//одинаковые с виду, но с разные степени
START_TEST(test_equal3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000110011";  // 99
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 24);  // 99/10^24
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000110011";  // 99
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 99/10^25
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//разные, с одинаковыми степенями
START_TEST(test_equal4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000001100011";  // 99
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 25);  // 99/10^25
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^25
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//одинаковые со степенью, с разными знаками
START_TEST(test_equal5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 25);  // -35/10^1
  s21_decimal dec2 = {{0, 0, 0, 0}};
  char *string_number2 =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000100011";  // 35
  for (int i = 0; i < 128; i++) {
    set_bit(&dec2, i, string_number2[127 - i] - '0');
  }
  set_sign(&dec2, 0);
  set_scale(&dec2, 25);  // 35/10^1
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//самые большие отрицательные, с разными степенями
START_TEST(test_equal6) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//разные, с разными степенями
START_TEST(test_equal7) {
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 26);  // 35/10^26
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//разные с офигеть какой большой степенью
START_TEST(test_equal8) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 1);  // 35/10^1
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//разные с офигеть какой большой степенью
START_TEST(test_equal9) {
  // самое большое положительное
  s21_decimal dec1 = {{0x1, 0x0, 0x0, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 1);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 1);
  set_scale(&dec2, 109);  // 35/10^109
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}
END_TEST

//одинаковые с офигеть какой большой степенью
START_TEST(test_equal10) {
  // самое большое положительное
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // самое большое положительное
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//нули с офигеть какой большой степенью
START_TEST(test_equal11) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 56);  // 35/10^56
  set_sign(&dec2, 0);
  set_scale(&dec2, 56);  // 35/10^109
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//нули отрицательный и положительный
START_TEST(test_equal12) {
  // самое большое положительное
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // самое большое положительное
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 0);
  set_sign(&dec2, 1);
  set_scale(&dec2, 0);
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

//нули положительный и отрицательный (первое больше)
START_TEST(test_equal13) {
  // отрицательный ноль
  s21_decimal dec1 = {{0, 0, 0, 0}};
  // положительный ноль
  s21_decimal dec2 = {{0, 0, 0, 0}};
  set_sign(&dec1, 0);
  set_scale(&dec1, 16);
  set_sign(&dec2, 1);
  set_scale(&dec2, 16);
  int code = s21_is_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_s21_is_equal(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_is_equal");
  tc = tcase_create("case_s21_equal");

  tcase_add_test(tc, test_equal0);
  tcase_add_test(tc, test_equal1);
  tcase_add_test(tc, test_equal2);
  tcase_add_test(tc, test_equal3);
  tcase_add_test(tc, test_equal4);
  tcase_add_test(tc, test_equal5);
  tcase_add_test(tc, test_equal6);
  tcase_add_test(tc, test_equal7);
  tcase_add_test(tc, test_equal8);
  tcase_add_test(tc, test_equal9);
  tcase_add_test(tc, test_equal10);
  tcase_add_test(tc, test_equal11);
  tcase_add_test(tc, test_equal12);
  tcase_add_test(tc, test_equal13);

  suite_add_tcase(s, tc);
  return s;
}
