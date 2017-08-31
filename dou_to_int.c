#include <stdio.h>
#include <stdlib.h>

int main(){
    double d_num = 0.02345;
    int integer;
    integer = (int)(d_num / 0.001);
    printf("%d\n", integer);
    return 0;
}
