#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_negate1) {
  // 792281625.14264337593543950335
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = s21_negate(decimal, NULL);

  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate2) {
  // степень 154 (показатель степени должен быть от 0 до 28)
  // биты 0-15 не нули
  // биты 24-30 не нули
  s21_decimal decimal = {{0, 0, 0, 1000000000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate3) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate4) {
  // степень 29 (показатель степени должен быть от 0 до 28)
  s21_decimal decimal = {{0, 0, 0, 0x1D0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate5) {
  // степень 28 (что корректно), но биты 0-15 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate6) {
  // степень 28 (что корректно), но биты 0-15 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate7) {
  // степень 28 (что корректно), но биты 24-30 не нули (младший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate8) {
  // степень 28 (что корректно), но биты 24-30 не нули (старший бит)
  s21_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate9) {
  // Просто все единицы
  s21_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_negate10) {
  // 79228162514264337.593543950334
  s21_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  // -79228162514264337.593543950334
  s21_decimal result;

  int code = s21_negate(decimal, &result);

  ck_assert_int_eq(code, 0);
}

Suite *suite_s21_negate(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_negate");
  tc = tcase_create("case_s21_negate");

  tcase_add_test(tc, test_negate1);
  tcase_add_test(tc, test_negate2);
  tcase_add_test(tc, test_negate3);
  tcase_add_test(tc, test_negate4);
  tcase_add_test(tc, test_negate5);
  tcase_add_test(tc, test_negate6);
  tcase_add_test(tc, test_negate7);
  tcase_add_test(tc, test_negate8);
  tcase_add_test(tc, test_negate9);
  tcase_add_test(tc, test_negate10);

  suite_add_tcase(s, tc);
  return s;
}
