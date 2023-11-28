#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void bits8_add_test(unsigned int x, unsigned int y){ 
    unsigned int got = bits8_to_int(bits8_add(bits8_from_int(x), bits8_from_int(y)));
    unsigned int expected = x + y;

    if (got != expected) {
    printf("Input:     %u + %u\n", x, y);
    printf("Got:       %u\n", got);
    printf("Expected:  %u\n", expected);
    exit(1);
  }
}

void bits8_mul_test(unsigned int x, unsigned int y){
    unsigned int got = bits8_to_int(bits8_mul(bits8_from_int(x), bits8_from_int(y)));
    unsigned int expected = x * y;
    printf(" got %u \n", got);
    printf(" expected %u \n", expected);

    if (got != expected) {
    printf("Input:     %u * %u\n", x, y);
    printf("Got:       %u\n", got);
    printf("Expected:  %u\n", expected);
    exit(1);
  }
}


int main() {
    //checks if bits8_to_int(bits_from_int(x) == x)
    assert(bits8_to_int(bits8_from_int(42)) == 42);
    //checks if bits8_from_int(2) returns a value with b1 set to true and everything else set to false
    assert(bits8_from_int(2).b1.v == true && bits8_from_int(2).b2.v == false && bits8_from_int(2).b3.v == false && bits8_from_int(2).b4.v == false && bits8_from_int(2).b5.v == false && bits8_from_int(2).b6.v == false&& bits8_from_int(2).b7.v == false  ); 
    assert(bits8_to_int(bits8_negate(bits8_from_int(255)))== 1);
    printf("negation of 255 %u \n", bits8_to_int(bits8_negate(bits8_from_int(255))));
    //bits8_add_test(42,84);
    //bits8_mul_test(42,23);

    printf("-2 + 9 using bits8_add = %d \n ", bits8_to_int(bits8_add(bits8_from_int(254), bits8_from_int(9))));

}



