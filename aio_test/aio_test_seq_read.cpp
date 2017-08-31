#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <aio.h>
#include <sys/stat.h>
#include <unistd.h>

double get_time(void) {
        struct timeval mytime;
        gettimeofday(&mytime,NULL);
        return (mytime.tv_sec*1.0+mytime.tv_usec/1000000.0);
}

int main(int argc, char **argv){
    struct aiocb64 read_aio;
    struct aiocb64 write_aio;
    char buf_write[4097];
    char buf_read[4097 * 5];
    char dev_name[30];
    double stat_time = 0.0;
    double end_time = 0.0;
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
    write_aio.aio_offset = 8;
    memcpy((void *)write_aio.aio_buf, (void *)buf_write, 4096);
//    aio_write64(&write_aio);
//    while(EINPROGRESS == aio_error64(&write_aio));
    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = 4096 * 5;
    read_aio.aio_offset = 0;
    stat_time= get_time();
    aio_read64(&read_aio);
    while(EINPROGRESS == aio_error64(&read_aio));
    end_time = get_time();
    printf("5 chunk:%.6lf\navertime:%.6lf", (end_time - stat_time) * 1000, (end_time - stat_time) * 1000.0 / 5);
    sleep(1);
    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = 4096;
    read_aio.aio_offset = 0;
    stat_time= get_time();
    aio_read64(&read_aio);
    while(EINPROGRESS == aio_error64(&read_aio));
    end_time = get_time();
    printf("5 chunk:%.6lf\navertime:%.6lf", (end_time - stat_time) * 1000 * 5, (end_time - stat_time) * 1000.0);

//    printf("%s\n", buf_write);
//    printf("%s\n", buf_read);
    return 1;
}
