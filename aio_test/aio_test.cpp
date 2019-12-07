#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
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
    struct aiocb64 *cblist[1];
    char buf_write[4097];
    char buf_read[4097];
    char dev_name[30];
    double stat_t = 0.0, end_t = 0.0;
    strcpy(dev_name, argv[1]);
    int fd = open(dev_name, O_RDWR|O_LARGEFILE);
    if(fd == -1){
        printf("Open device error!\n");
        return -1;
    }
    bzero((char *)&read_aio, sizeof(struct aiocb64));
    bzero((char *)&write_aio, sizeof(struct aiocb64));
    bzero( (char *)cblist, sizeof(cblist) );
    for(int i=0; i < 4096; i++){
        buf_write[i] = ('a'+ (i % 26));
    }
    write_aio.aio_buf = malloc(4096);
    read_aio.aio_buf = malloc(4097);
    if(!write_aio.aio_buf)
        perror("malloc\n");

    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = 4096;
    read_aio.aio_offset = 8192;
 

    write_aio.aio_fildes = fd;
    write_aio.aio_nbytes = 81920;
    write_aio.aio_offset = 4095;
//    memcpy((void *)write_aio.aio_buf, (void *)buf_write, 4096);
    stat_t = get_time();
    aio_write64(&write_aio);
    while(EINPROGRESS == aio_error64(&write_aio));
    end_t = get_time();

/*    aio_read64(&read_aio);
    while(EINPROGRESS == aio_error64(&read_aio));
    end_t = get_time();*/
    std::cout<< "1 WRITE "<<(end_t - stat_t) * 1000<<std::endl;
sleep(1);
/*stat_t = get_time();

//   write_aio.aio_offset = 4096 * 1024;
   memcpy((void *)write_aio.aio_buf, (void *)buf_write, 4096);

    aio_write64(&write_aio);
    while(EINPROGRESS == aio_error64(&write_aio));
     end_t = get_time();
std::cout<<"2 WRITE "<<(end_t - stat_t) * 1000<<std::endl;
    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = 4096;
    read_aio.aio_offset = 0;
    sleep(1);
//    stat_t = get_time();
    cblist[0] = &read_aio;
//    sleep(3);
    stat_t = get_time();
    aio_read64(&read_aio);
//    aio_suspend64(cblist, 1, NULL);
    while(EINPROGRESS == aio_error64(&read_aio));
    end_t = get_time();
    std::cout<<"1 READ "<<(end_t - stat_t) * 1000<<std::endl;
stat_t = get_time();
    aio_read64(&read_aio);
//    aio_suspend64(cblist, 1, NULL);
    while(EINPROGRESS == aio_error64(&read_aio));
    end_t = get_time();
    std::cout<<"2 READ "<<(end_t - stat_t) * 1000<<std::endl;

    sleep(1);
    memset(buf_read, 0, 4097);
    memcpy((void *)buf_read, (void *)read_aio.aio_buf, 4096);
//    printf("%s\n", buf_write);
//    printf("%s\n", buf_read);
*/    return 1;
}
