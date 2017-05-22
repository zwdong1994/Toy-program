#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bch.h"

int main(){
    struct bch_control *bc;
    int m = 13, t = 18;
    unsigned int prim_poly = 32;
    bc = init_bch(m, t, 0);
    char data[4096] = "dsfajsdklfjas";
    char data2[4096] = "sdfwersdfsdfsdfsdf";
    unsigned char result[200];
    for(int i = 0; i < 10; i++){
        memset(result, 0, 200);
        if(i % 2 == 0)
            encode_bch(bc, data, 4096, result);
        else
            encode_bch(bc, data2, 4096, result);
        printf("%d\n%s\n", (int)strlen(result), result);

    }
    return 0;

}
