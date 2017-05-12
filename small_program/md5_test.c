#include <stdio.h>
#include <stdlib.h>
#include "md5.h"
#include <string.h>

int main(void)
{
    char input[4096], output[100];
    memset(input, 1, 4096);
    memset(output, 0, 100);
    md5(input, 4096, output);
    printf("%d\n%s\n", strlen(output), output);
    return 0;
}

