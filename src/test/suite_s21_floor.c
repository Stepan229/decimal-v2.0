
#include "../decimal_suitecases.h"
#include "../s21_decimal.h"

START_TEST(test_floor0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000101100010";  // 354
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 0);
  set_scale(&dec1, 2);  // 354/10^1
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "000000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000011";  // 3
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor1) {
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
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor2) {
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
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor3) {
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
  s21_floor(dec1, &res);
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

START_TEST(test_floor4) {
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
      "00000000000000000000000000000000000000000000000000000000";  // 1
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor5) {
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
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor6) {
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
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor7) {
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
      "00000000000000000000000000000000000000000000000000110000";  // -48
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor8) {
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
      "00000000000000000000000000000000000000000000000000110000";  // -48
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor9) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  char *string_number1 =
      "00000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000100010100001010011011"
      "1011001111111100011101";  // 4744444444445
  for (int i = 0; i < 128; i++) {
    set_bit(&dec1, i, string_number1[127 - i] - '0');
  }
  set_sign(&dec1, 1);
  set_scale(&dec1, 13);  // -4744444444445/10^13 = -0.4744444444445
  s21_decimal res = {{0, 0, 0, 0}};
  char *string_number_res =
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 0
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor10) {
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
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-0.4744444444445);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor11) {
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
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-47.44444444445);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // printf("%d\n", orig_round);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor12) {
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
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor13) {
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
  s21_floor(dec1, &res);
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

START_TEST(test_floor14) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(get_bit(&dec1, i), get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor15) {
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
      "00000000000000000000000000000000000000000000000000001000";  // -8
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor16) {
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
      "100000000000000000000000000000000000000000000000000000000000000000000000"
      "00000000000000000000000000000000000000000000000000000001";  // 0
  s21_floor(dec1, &res);
  for (int i = 0; i < 128; i++) {
    ck_assert_int_eq(string_number_res[127 - i] - '0', get_bit(&res, i));
  }
}
END_TEST

START_TEST(test_floor17) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000001010100111"
      "01001000111000011001";  // 71228162514
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 28);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-0.00000000771228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor18) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000"
      "000000000000000000000000000000000000000000001010100111"
      "01001000111000011001";  // 71228162514
  for (int i = 0; i < 128; i++) {
    set_bit(&dec, i, string_number[127 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 28);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(0.00000000771228162514);
  // printf("\n");
  // for (int i = 127; i >= 0; i--) {
  //   printf("%d", get_bit(&res, i));
  // }
  // printf("\n");
  // printf("%d\n", orig_round);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor19) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 10);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-7.1228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor20) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 11);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-0.71228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor21) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 9);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-71.228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor22) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 11);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-0.71228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor23) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 8);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-712.28162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor24) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 7);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-7122.8162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor25) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 5);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-712281.62514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor26) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 5);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(712281.62514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor27) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 6);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(71228.162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor28) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 7);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(7122.8162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor29) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 8);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(712.28162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor30) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 0);
  set_scale(&dec, 9);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(71.228162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor31) {
  s21_decimal dec = {{0, 0, 0, 0}};
  char *string_number =
      "000000000000000000000000000000000000000000000000000000000001000010010101"
      "100001111000000111010010";  // 71228162514
  for (int i = 0; i < 96; i++) {
    set_bit(&dec, i, string_number[95 - i] - '0');
  }
  set_sign(&dec, 1);
  set_scale(&dec, 6);
  s21_decimal res = {{0, 0, 0, 0}};
  s21_floor(dec, &res);
  int s21_res = convert_to_int(res);
  int orig_round = floor(-71228.162514);
  ck_assert_int_eq(s21_res, orig_round);
}
END_TEST

START_TEST(test_floor32) {
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
  int code = s21_floor(dec, res);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s;
  TCase *tc;

  s = suite_create("s21_floor");
  tc = tcase_create("case_s21_floor");

  tcase_add_test(tc, test_floor0);
  tcase_add_test(tc, test_floor1);
  tcase_add_test(tc, test_floor2);
  tcase_add_test(tc, test_floor3);
  tcase_add_test(tc, test_floor4);
  tcase_add_test(tc, test_floor5);
  tcase_add_test(tc, test_floor6);
  tcase_add_test(tc, test_floor7);
  tcase_add_test(tc, test_floor8);
  tcase_add_test(tc, test_floor9);
  tcase_add_test(tc, test_floor10);
  tcase_add_test(tc, test_floor11);
  tcase_add_test(tc, test_floor12);
  tcase_add_test(tc, test_floor13);
  tcase_add_test(tc, test_floor14);
  tcase_add_test(tc, test_floor15);
  tcase_add_test(tc, test_floor16);
  tcase_add_test(tc, test_floor17);
  tcase_add_test(tc, test_floor18);
  tcase_add_test(tc, test_floor19);
  tcase_add_test(tc, test_floor20);
  tcase_add_test(tc, test_floor21);
  tcase_add_test(tc, test_floor22);
  tcase_add_test(tc, test_floor23);
  tcase_add_test(tc, test_floor24);
  tcase_add_test(tc, test_floor25);
  tcase_add_test(tc, test_floor26);
  tcase_add_test(tc, test_floor27);
  tcase_add_test(tc, test_floor28);
  tcase_add_test(tc, test_floor29);
  tcase_add_test(tc, test_floor30);
  tcase_add_test(tc, test_floor31);
  tcase_add_test(tc, test_floor32);

  suite_add_tcase(s, tc);
  return s;
}
