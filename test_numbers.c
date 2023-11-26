#include "numbers.h"

//Inkluderer det bibliotek vi benytter
int main() {
    

    struct bits8 x = bits8_from_int(8);
    struct bits8 y = bits8_from_int(5);
    bits8_print(y);
    // struct bits8 xl = bits8_from_int(10 << 1);
    // bits8_print(xl);
    // bits8_print(bits8_negate(x));
    // bits8_print(y);
    // bits8_print(bits8_negate(y));
    // // bits8_print(bits8_add(x,y));
    // bits8_print(bits8_negate(bits8_from_int(255)));
    bits8_print(bits8_mul(y, bits8_from_int(3)));
    
    bits8_print(x);
    bits8_print(bits8_mul(x, bits8_from_int(3)));
    
}