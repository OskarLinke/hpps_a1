#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

struct bit {
  bool v;
};

struct bit bit_from_int(unsigned int input){ 
    struct bit b;
    if(input == 0 || input  == 1){
    if(input == 0){ 
        b.v = false;
        
    } else if(input == 1){ 
        b.v = true;
    }
    return b;
    } else {
        fprintf(stderr, "Error! Please enter either 0 or 1. You entered %d \n" , input);
    }
}

unsigned int bit_to_int(struct bit b){ 
    unsigned int val; 
    if(b.v == true){ 
        val = 1; 
    } else if (b.v == false){
        val = 0;
    }
    return val;

}

void bit_print(struct bit b){ 
    if(b.v == true){ 
        printf("1");
    } else { 
        printf("0");
    }
}

struct bit bit_not(struct bit b){
    struct bit x; 
    if(b.v == true){ 
        x.v = false;
    } else { 
        x.v = true;
    }
    return x;
}

struct bit bit_and(struct bit a, struct bit b){
    struct bit x; 
    if(a.v == true && b.v == true){
        x.v = true;
    }else { 
        x.v = false;
    }
    return x;
}

struct bit bit_or(struct bit a, struct bit b){
    struct bit x; 
    if(a.v == true || b.v == true){
        x.v = true;
    } else { 
        x.v = false;
    }
    return x;
}
struct bit bit_xor(struct bit a, struct bit b){ 
    struct bit x; 
    if(a.v == true && b.v == false){ 
        x.v = true; 
    } else if( a.v == false && b.v == true){ 
        x.v = true;
    }else { 
        x.v = false; 
    }
    return x;
}