#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

int main()
{
    DIR *dir;
    struct dirent *ptr;
    if((dir=opendir("/dev")) == NULL)
    {
        perror("open dir error");
        exit(1);
    }
    while((ptr = readdir(dir)) != NULL)
    {
        printf("%s\n", ptr->d_name);
    }
    closedir(dir);
    return 0;
}
