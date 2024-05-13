#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(dc_to_fl_1) {
  float number = 1.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_2) {
  float number = 0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_3) {
  float number = -0.1;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-1);
}
END_TEST
START_TEST(dc_to_fl_4) {
  float number = 0.0;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST
START_TEST(dc_to_fl_5) {
  float number = 0.0123456789;
  float float_check = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  s21_from_decimal_to_float(decimal_check, &float_check);
  ck_assert_float_eq_tol(number, float_check, 1e-7);
}
END_TEST

Suite *suite_s21_from_decimal_to_float() {
  Suite *s = suite_create("s21_from_decimal_to_float");
  TCase *tc = tcase_create("s21_from_decimal_to_float");
  tcase_add_test(tc, dc_to_fl_1);
  tcase_add_test(tc, dc_to_fl_2);
  tcase_add_test(tc, dc_to_fl_3);
  tcase_add_test(tc, dc_to_fl_4);
  tcase_add_test(tc, dc_to_fl_5);

  suite_add_tcase(s, tc);
  return s;
}
