#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(){
    char *string = "hello";
    char result[40];
    memset(result, 0, 40);
    SHA256((unsigned char *)string, strlen(string), (unsigned char *)result);
    printf("%d\n%s\n", (int)strlen(result), result);
    return 0;
}
