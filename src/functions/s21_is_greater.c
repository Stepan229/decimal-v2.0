#include "../s21_decimal.h"

// int s21_is_greater(s21_decimal value_1, s21_decimal value_2){
//     int result = 0;
//     // int flag_null = 0;
//     s21_decimal_big val1;
//     s21_decimal_big val2;

//     convert_big_decima(value_1, &val1);
//     convert_big_decima(value_2, &val2);

//     normalize(&val1, &val2);
//     is_equal_null(&val1, &val1);
//     int sign_1 = get_bit_big(val1, 255), sign_2 = get_bit_big(val1, 255);
//     if (sign_1 != sign_2){
//         if (sign_2 == 1)
//             result = 1;

//     else if (is_equal_big(val1, val2)){
//         result = 0;
//     }
//     }else{
//         for(int i = 0; i <= 32*7; i++){
//             if(get_bit_big(val1, i) != get_bit_big(val2, i)){
//                 if (get_bit_big(val2, i) == 0)
//                     result = 1;
//                 break;
//             }
//         }
//         if (sign_1 == 1 && sign_2 == 1)
//             result = (result == 1) ?  0: 1;
//     }

//     return result;

// }

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  // int flag_null = 0;
  s21_decimal_big val1;
  s21_decimal_big val2;

  convert_big_decima(value_1, &val1);
  convert_big_decima(value_2, &val2);

  if (!is_less_big(val1, val2) && !is_equal_big(val1, val2))
    result = 1;
  else
    result = 0;
  return result;
}