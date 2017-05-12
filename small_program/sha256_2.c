#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    unsigned char md[33] = {0};
        SHA256((const unsigned char *)"hello", strlen("hello"), md);
              printf("%d\n%s\n", (int)strlen(md), md);
            int i = 0;
                char buf[65] = {0};
                    char tmp[3] = {0};
                        for(i = 0; i < 32; i++ )
                                {
                                        sprintf(tmp,"%02X", md[i]);
                                        strcat(buf, tmp);
                                    }

                        printf("%s\n", buf);
                      //      cout << buf << endl;

                                return 0;
}
