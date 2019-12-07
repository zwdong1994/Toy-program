#include <stdio.h>
#include <aio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

double get_time(void) {
        struct timeval mytime;
        gettimeofday(&mytime,NULL);
        return (mytime.tv_sec*1.0+mytime.tv_usec/1000000.0);
}


int main(int argc, char **argv){
    char *buf_write;
    char *buf_read;
    char dev_name[30];
    char length_str[20];
    char address_str[20];
    char command_str[10];

    posix_memalign((void**)&buf_write, getpagesize(), 10240);
    posix_memalign((void**)&buf_read, getpagesize(), 10240);


    struct aiocb64 read_aio;
    struct aiocb64 write_aio;
    struct aiocb64 *cblist[1];

    double stat_t = 0.0, end_t = 0.0;
    
    unsigned long length;
    unsigned long address;

    strcpy(length_str,argv[2]);
    strcpy(address_str, argv[3]);

    sscanf(length_str, "%lu", &length);
    sscanf(address_str, "%lu", &address);

    strcpy(dev_name, argv[1]);
    int fd = open(dev_name, O_RDWR | O_DIRECT | O_LARGEFILE, 0755);
    if(fd == -1){
        printf("Open device error!\n");
        return -1;
    }
    for(int i=0; i < 8193; i++){
        buf_write[i] = ('a'+ (i % 26));
    }
//    printf("%s\n", buf_write);
    write_aio.aio_buf = buf_write;
    read_aio.aio_buf = buf_read;

    read_aio.aio_fildes = fd;
    read_aio.aio_nbytes = length;
    read_aio.aio_offset = address;


    write_aio.aio_fildes = fd;
    write_aio.aio_nbytes = length;
    write_aio.aio_offset = address;

/*    aio_read64(&read_aio);
    while(EINPROGRESS == aio_error64(&read_aio));
    int len = aio_return64(&read_aio);
*/
    int len = pread(fd, buf_read, length, address);
    if(len != 4096) {
	memcpy(command_str, buf_read, 10);
	printf("%s\n", command_str);
	if(strcmp(command_str, "Nothing!") == 0)
		printf("Nothing happened!\n");
	else {
		uint16_t id;
		uint8_t type;
		uint16_t length;
		int m;
		memcpy(&id, buf_read, sizeof(uint16_t));
		memcpy(&type, buf_read + sizeof(uint16_t), sizeof(uint8_t));
		memcpy(&length, buf_read + sizeof(uint16_t) + sizeof(uint8_t), sizeof(uint16_t));
		m = type;
		printf("id is %u, type is %d, length is %u\n", id, m, length);
	}
    	printf("Error write! The len is: %d\n", len);
	if(len == -1){
		printf("%s   %d\n", strerror(errno), errno);
	}
	printf("read string: \n %s \n", buf_read);
	exit(0);
    } else {
    	printf("Write successfully!\n");
    }

    return 0;

}
