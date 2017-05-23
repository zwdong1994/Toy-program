#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <aio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
    struct aiocb64 read_aio;
    struct aiocb64 write_aio;
    char buf_write[4097];
    char buf_read[4097];
    char dev_name[30];
    strcpy(dev_name, argv[1]);
    int fd = open(dev_name, O_RDWR|O_LARGEFILE);
    if(fd == -1){
        printf("Open device error!\n");
        return -1;
    }
    bzero((char *)&read_aio, sizeof(struct aiocb64));
    bzero((char *)&write_aio, sizeof(struct aiocb64));
    for(int i=0; i < 4096; i++){
        buf_write[i] = ('a'+ (i % 26));
    }
    write_aio.aio_buf = malloc(4097);
    read_aio.aio_buf = malloc(4097);
    if(!write_aio.aio_buf)
        perror("malloc\n");
    write_aio.aio_fildes = fd;
    write_aio.aio_nbytes = 4096;
    write_aio.aio_offset = 0;
    memcpy((void *)write_aio.aio_buf, (void *)buf_write, 4096);
    aio_write64(&write_aio);
    while(EINPROGRESS == aio_error64(&write_aio));
    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = 4096;
    read_aio.aio_offset = 0;
    aio_read64(&read_aio);
    while(EINPROGRESS == aio_error64(&read_aio));
    sleep(1);
    memset(buf_read, 0, 4097);
    memcpy((void *)buf_read, (void *)read_aio.aio_buf, 4096);
    printf("%s\n", buf_write);
    printf("%s\n", buf_read);
    return 1;
}
