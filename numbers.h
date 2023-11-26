//importerer de biblioteker vi skal bruge, inklusive bits.h, som indeholder definitionen for struct bit, blandet andet. 
#include "bits.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

//Laver vores nye type struct bits8
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

struct bits8 bits8_from_int(unsigned int x){
    struct bits8 b; 
    //do something 

    return b
};

unsigned int bits8_to_int(struct bits8 x){
    //Opretter vores integer som til sidst skal returneres
    unsigned int eval; 
    //Ganger hver bits værdi, med den værdi den repræsenterer, og lægger det hele til eval 
    //Skriver f.eks. 2u i stedet for bare 2, fordi vi vil bruge unsigned integers
    eval = bit_to_int(x.b0) + (bit_to_int(x.b1) * 2u) + (bit_to_int(x.b2) * 4u) + (bit_to_int(x.b3) * 8u)+ (bit_to_int(x.b4) * 16u)+ (bit_to_int(x.b5) * 32u)   + (bit_to_int(x.b6) * 64u)+ (bit_to_int(x.b7) * 128u);
    return eval;
};

void bits8_print(struct bits8 v){ 
    //Kalder for hver bit i bits8 bit_to_int fra bits.h, som returnerer 1 hvis den er true, og 0 hvis den er false. 
    printf("%d,%d,%d,%d,%d,%d,%d,%d \n", bit_to_int(v.b7), bit_to_int(v.b6), bit_to_int(v.b5), bit_to_int(v.b4), bit_to_int(v.b3), bit_to_int(v.b2), bit_to_int(v.b1), bit_to_int(v.b0));
};

struct bits8 bits8_from_int(unsigned int x) { //Takes the integer 
    assert(x <= 255u);
    
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
