#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(from_decimal_to_int_1) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000001010";  // 10
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 10
  set_scale(&dec1, 0);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(10, number);
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000111111"
      "111111111111111111111111";  // 1073741823
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1073741823
  set_scale(&dec1, 0);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(1073741823, number);
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000001000000"
      "000000000000000000000000";  // 1073741824
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1073741824
  set_scale(&dec1, 0);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(1073741824, number);
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000001000000"
      "000000000000000000000000";  // 1073741824
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-1073741824
  set_scale(&dec1, 0);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(-1073741824, number);
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000111000000"
      "000000000000000000000001";
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);
  set_scale(&dec1, 0);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(0, number);
  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000001000000"
      "000000000000000000000001";  // 1073741825
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 1);  //-1073741825
  set_scale(&dec1, 0);

  int *number = NULL;

  int response = s21_from_decimal_to_int(dec1, number);

  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(from_decimal_to_int_7) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000111111"
      "111111111111111111111111";  // 1073741823
  set_binary_number(&dec1, string_number1);
  set_sign(&dec1, 0);  // 1073741823
  set_scale(&dec1, 6);

  int number = 0;

  int response = s21_from_decimal_to_int(dec1, &number);

  ck_assert_int_eq(1073, number);
  ck_assert_int_eq(0, response);
}
END_TEST

Suite *suite_s21_from_decimal_to_int() {
  Suite *s = suite_create("s21_from_decimal_to_int");
  TCase *tc = tcase_create("s21_from_decimal_to_int");

  tcase_add_test(tc, from_decimal_to_int_1);
  tcase_add_test(tc, from_decimal_to_int_2);
  tcase_add_test(tc, from_decimal_to_int_3);
  tcase_add_test(tc, from_decimal_to_int_4);
  tcase_add_test(tc, from_decimal_to_int_5);
  tcase_add_test(tc, from_decimal_to_int_6);
  tcase_add_test(tc, from_decimal_to_int_7);

  suite_add_tcase(s, tc);
  return s;
}
