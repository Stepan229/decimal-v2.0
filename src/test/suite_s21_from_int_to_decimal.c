#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(from_int_to_decimal_1) {
  int number = 2147483647;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(number, &decimal_check);
  ck_assert_int_eq(number, decimal_check.bits[0]);
  ck_assert_int_eq(0, decimal_check.bits[1]);
  ck_assert_int_eq(0, decimal_check.bits[2]);
  ck_assert_int_eq(0, get_sign_decimal(decimal_check));
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  int number = -2147483647;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(number, &decimal_check);
  ck_assert_int_eq(-number, decimal_check.bits[0]);
  ck_assert_int_eq(0, decimal_check.bits[1]);
  ck_assert_int_eq(0, decimal_check.bits[2]);
  ck_assert_int_eq(1, get_sign_decimal(decimal_check));
}
END_TEST

START_TEST(from_int_to_decimal_3) {
  int number = 214748364;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(number, &decimal_check);
  ck_assert_int_eq(number, decimal_check.bits[0]);
  ck_assert_int_eq(0, decimal_check.bits[1]);
  ck_assert_int_eq(0, decimal_check.bits[2]);
  ck_assert_int_eq(0, get_sign_decimal(decimal_check));
}
END_TEST

START_TEST(from_int_to_decimal_4) {
  int number = 0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(number, &decimal_check);
  ck_assert_int_eq(number, decimal_check.bits[0]);
  ck_assert_int_eq(0, decimal_check.bits[1]);
  ck_assert_int_eq(0, decimal_check.bits[2]);
  ck_assert_int_eq(0, get_sign_decimal(decimal_check));
}
END_TEST

START_TEST(from_int_to_decimal_5) {
  int number = -0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(number, &decimal_check);
  ck_assert_int_eq(number, decimal_check.bits[0]);
  ck_assert_int_eq(0, decimal_check.bits[1]);
  ck_assert_int_eq(0, decimal_check.bits[2]);
  ck_assert_int_eq(0, get_sign_decimal(decimal_check));
}
END_TEST

START_TEST(from_int_to_decimal_6) {
  int number = -0;
  s21_decimal *decimal_check = NULL;
  int response = s21_from_int_to_decimal(number, decimal_check);
  ck_assert_int_eq(1, response);
}
END_TEST

Suite *suite_s21_from_int_to_decimal() {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *tc = tcase_create("s21_from_int_to_decimal");
  tcase_add_test(tc, from_int_to_decimal_1);
  tcase_add_test(tc, from_int_to_decimal_2);
  tcase_add_test(tc, from_int_to_decimal_3);
  tcase_add_test(tc, from_int_to_decimal_4);
  tcase_add_test(tc, from_int_to_decimal_5);
  tcase_add_test(tc, from_int_to_decimal_6);

  suite_add_tcase(s, tc);
  return s;
}