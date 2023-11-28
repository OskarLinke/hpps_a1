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
    printf("<%d,%d,%d,%d,%d,%d,%d,%d> \n", bit_to_int(v.b7), bit_to_int(v.b6), bit_to_int(v.b5), bit_to_int(v.b4), bit_to_int(v.b3), bit_to_int(v.b2), bit_to_int(v.b1), bit_to_int(v.b0));
};


struct bits8 bits8_from_int(unsigned int x) {
    // Converts an integer x to a bits8
    assert(x <= 255u); // Check for max allowed value of integer
    
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
};

struct add_result {
    struct bit s;
    struct bit c;
};

struct add_result bit_add (struct bit x, struct bit y, struct bit c) {
    struct add_result result;
    result.s = bit_xor(bit_xor(x, y) , c);
    result.c = 
        bit_or(
            bit_and(x,y), 
            bit_or(
                bit_and(x,c), 
                bit_and(y,c)));
    return result;
}
//returns x if b.v = true, and returns <00000000> if b.v = false
struct bits8 bits8_and_bit(struct bits8 x, struct bit b){
    struct bits8 result; 
    result.b0 = bit_and(x.b0, b);
    result.b1 = bit_and(x.b1, b);
    result.b2 = bit_and(x.b2, b);
    result.b3 = bit_and(x.b3, b);
    result.b4 = bit_and(x.b4, b);
    result.b5 = bit_and(x.b5, b);
    result.b6 = bit_and(x.b6, b);
    result.b7 = bit_and(x.b7, b);
    return result; 
}

//Leftshifts the bits8 by however much a is
//Skal ændres så den altid leftshifter med 1, og skal ikke regne om til integers. 
struct bits8 bits8_leftshit(struct bits8 b, unsigned int a){
    assert(a < 8); 
    
    struct bits8 result = bits8_from_int(bits8_to_int(b) << a); 
    return result; 

}

struct bits8 bits8_add (struct bits8 x, struct bits8 y) {
    struct bits8 result;
    struct bit c;
    c.v = false;
    
    //første iteration
    result.b0 = bit_add(x.b0,y.b0,c).s; 
    c = bit_add(x.b0,y.b0,c).c;

    result.b1 = bit_add(x.b1, y.b1, c).s;
    c = bit_add(x.b1,y.b1,c).c;

    result.b2 = bit_add(x.b2, y.b2, c).s;
    c = bit_add(x.b2,y.b2,c).c;

    result.b3 = bit_add(x.b3, y.b3, c).s;
    c = bit_add(x.b3,y.b3,c).c;

    result.b4 = bit_add(x.b4, y.b4, c).s;
    c = bit_add(x.b4,y.b4,c).c;

    result.b5 = bit_add(x.b5, y.b5, c).s;
    c = bit_add(x.b5,y.b5,c).c;

    result.b6 = bit_add(x.b6, y.b6, c).s;
    c = bit_add(x.b6,y.b6,c).c;

    result.b7 = bit_add(x.b7, y.b7, c).s;
    c = bit_add(x.b7,y.b7,c).c;
    assert(c.v == bit_from_int(0).v);

    return result;
}

struct bits8 bits8_negate(struct bits8 x) {
    
    struct bits8 result;        // instantiate result bits8
    result.b0 = bit_not(x.b0);  // negate each bit in bits8
    result.b1 = bit_not(x.b1);
    result.b2 = bit_not(x.b2);
    result.b3 = bit_not(x.b3);
    result.b4 = bit_not(x.b4);
    result.b5 = bit_not(x.b5);
    result.b6 = bit_not(x.b6);
    result.b7 = bit_not(x.b7);

    result = bits8_add(result, bits8_from_int(1u)); // add 1 to result

    return result;
}

struct bits8 bits8_mul(struct bits8 x, struct bits8 y) {
    struct bits8 result; // instantiate result bits8
    //Der skal være en formatering som ca. ligner: 
    //result = bits8_and_bit(x,y.b0);
    //x1 = bits8_leftshift(x);
    //result = bits8_add(result, bits8_and_bit( x1 ,y.b1));
    //x2 = bits8_leftshift(x1);
    //result = bits8_add(result, bits8_and_bit( x2 ,y.b2));
    //osv. dernedaf


    result = bits8_and_bit(x,y.b0);
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,1) ,y.b1));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,2) ,y.b2));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,3) ,y.b3));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,4) ,y.b4));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,5) ,y.b5));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,6) ,y.b6));
    result = bits8_add(result, bits8_and_bit( bits8_leftshit(x,7) ,y.b7));
    return result;
}

