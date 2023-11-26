#include "bits.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

struct bits8{
    struct bit b0; 
    struct bit b1; 
    struct bit b2; 
    struct bit b3; 
    struct bit b4; 
    struct bit b5; 
    struct bit b6; 
    struct bit b7;
}; 

struct bits8 bits8_from_int(unsigned int x) {
    struct bits8 bits;
    bits.b7 = bit_from_int(x / 128);
    x = x % 128;
    bits.b6 = bit_from_int(x / 64);
    x = x % 64;
    bits.b5 = bit_from_int(x / 32);
    x = x % 32;
    bits.b4 = bit_from_int(x / 16);
    x = x % 16;
    bits.b3 = bit_from_int(x / 8);
    x = x % 8;
    bits.b2 = bit_from_int(x / 4);
    x = x % 4;
    bits.b1 = bit_from_int(x / 2);
    x = x % 2;
    bits.b0 = bit_from_int(x / 1);
    return bits;
}