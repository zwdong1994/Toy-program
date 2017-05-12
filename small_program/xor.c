#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    unsigned long long a=21242412312, b=1, xor;
    xor = a ^ b;
    printf("%llu\n", xor);
    return 0;
}
