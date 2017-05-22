#include <stdio.h>
#include <stdlib.h>

int main(){
    char data[] = {'a', 'b', 0x00, 'c', 'd'};
    printf("%lu\n", sizeof(data));
    return 0;
}
