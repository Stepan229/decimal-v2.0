#include "../decimal_suitecases.h"
/************************************************
/ так как из флоата только 7 цифр переводим, то
/ используется только нулевой и третий бит
/ первый и второй остаются нулевыми
/ в нулевом бите сравниваем с ожидаемым числом
/ в третьем бите проверяем знак и степень
*************************************************/
START_TEST(fl_to_dc_1) {
  float number = 1.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(0, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_2) {
  float number = 0.1;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(1, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_3) {
  float number = -0.1;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(1, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(1, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_4) {  //тут проверка на слишком малое число
  float number = 1e-29;
  int check_return = 0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  check_return = s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(0, get_scale(decimal_check));
  ck_assert_int_eq(1, check_return);
}
END_TEST
START_TEST(fl_to_dc_5) {
  float number = -0.0000123456789;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(1, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(11, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_6) {
  float number = 0.0000123456789;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(11, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_7) {
  float number = 0.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(0, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_8) {
  float number = 1234567890.0;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(1234568000, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(0, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_9) {
  float number = INFINITY;
  s21_decimal decimal_check = {{0, 0, 0, 0}};
  s21_from_float_to_decimal(number, &decimal_check);
  ck_assert_uint_eq(0, decimal_check.bits[0]);
  ck_assert_uint_eq(0, decimal_check.bits[1]);
  ck_assert_uint_eq(0, decimal_check.bits[2]);
  ck_assert_uint_eq(0, get_sign_decimal(decimal_check));
  ck_assert_uint_eq(0, get_scale(decimal_check));
}
END_TEST
START_TEST(fl_to_dc_10) {
  float number = 7.922816E+28;

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "111111111111111111111111011101111011001110010010101100100001101000100000"
      "000000000000000000000000";  // 79228160000000000000000000000

  int response = s21_from_float_to_decimal(number, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }

  ck_assert_int_eq(0, get_sign_decimal(res));  // 79228160000000000000000000000
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST

START_TEST(fl_to_dc_11) {
  float number = 7.922817E+28;

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000";  // 0

  int response = s21_from_float_to_decimal(number, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }

  ck_assert_int_eq(0, get_sign_decimal(res));  // 0
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(1, response);
}
END_TEST

START_TEST(fl_to_dc_12) {
  float number = -7.922816E+28;

  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "11111111111111111111111101110111101100111001001010"
      "1100100001101000100000000000000000000000000000";

  int response = s21_from_float_to_decimal(number, &res);
  for (int i = 0; i < 96; i++) {
    ck_assert_int_eq(string_number_res[95 - i] - '0', get_bit(&res, i));
  }

  ck_assert_int_eq(1, get_sign_decimal(res));  // 79228160000000000000000000000
  ck_assert_int_eq(0, get_scale(res));
  ck_assert_int_eq(0, response);
}
END_TEST
Suite *suite_s21_from_float_to_decimal() {
  Suite *s = suite_create("s21_from_float_to_decimal");
  TCase *tc = tcase_create("s21_from_float_to_decimal");
  tcase_add_test(tc, fl_to_dc_1);
  tcase_add_test(tc, fl_to_dc_2);
  tcase_add_test(tc, fl_to_dc_3);
  tcase_add_test(tc, fl_to_dc_4);
  tcase_add_test(tc, fl_to_dc_5);
  tcase_add_test(tc, fl_to_dc_6);
  tcase_add_test(tc, fl_to_dc_7);
  tcase_add_test(tc, fl_to_dc_8);
  tcase_add_test(tc, fl_to_dc_9);
  tcase_add_test(tc, fl_to_dc_10);
  tcase_add_test(tc, fl_to_dc_11);
  tcase_add_test(tc, fl_to_dc_12);

  suite_add_tcase(s, tc);
  return s;
}
