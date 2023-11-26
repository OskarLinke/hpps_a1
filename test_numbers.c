#include "numbers.h"

//Inkluderer det bibliotek vi benytter
int main() {
    

    struct bits8 x = bits8_from_int(8);
    struct bits8 y = bits8_from_int(7);
    bits8_print(x);
    bits8_print(bits8_negate(x));
    bits8_print(y);
    bits8_print(bits8_negate(y));
    // bits8_print(bits8_add(x,y));
    bits8_print(bits8_negate(bits8_from_int(255)));
        
}