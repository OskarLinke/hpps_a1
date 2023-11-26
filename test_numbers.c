#include "numbers.h"

//Inkluderer det bibliotek vi benytter
int main() {
    struct bits8 bit; 
    bit.b0.v = false; 
    bit.b1.v = true; 
    bit.b7.v = true; 
    bit.b5.v = true;
    bits8_print(bit); 
    printf("%d \n", bits8_to_int(bit)); 
    
}