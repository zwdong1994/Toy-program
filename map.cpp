//
// Created by victor on 5/28/17.
//

#include "map.h"
#include <aio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BLOCK_SIZE 4096

map::map() {
    ssd_capacity = 64;
    max_size_addr = ssd_capacity * 1024 * 1024 / 4;
    alloc_addr_point = 0;
    dev_name = new char[30];
    strcpy(dev_name, "/dev/sdc1");
    fd = open(dev_name, O_RDWR|O_LARGEFILE);
    if(fd == -1){
        std::cout<<"open "<< dev_name <<" error!"<<std::endl;
        exit(-1);
    }
}

map::~map() {

}

map* map::map_instance = NULL;

map* map::Get_map(){
    static pthread_mutex_t mu = PTHREAD_MUTEX_INITIALIZER;
    if(map_instance == NULL){
        pthread_mutex_lock(&mu);
        if(map_instance == NULL)
            map_instance = new map();
        pthread_mutex_unlock(&mu);
    }
    return map_instance;
}

struct addr* map::Get_addr(char *ecc_code, int length_ecc) {
    std::string str;
    ecc_code[length_ecc] = '\0';
    str = ecc_code;
    if(map_container[str] != NULL){ //exist
        return map_container[str];
    }
    else
        return NULL;

}

int map::insert_map(char *ecc_code, char chunk_reference[], int length_ecc) {
    struct addr *p = new addr;

    if(alloc_addr_point < max_size_addr){
        std::string str;
        ecc_code[length_ecc] = '\0';
        str = ecc_code;
        p -> offset = alloc_addr_point;
        p -> next = NULL;
        alloc_addr_point++; //allocate succeed
        if(map_container[str] != NULL){
            p -> next = (struct addr*)map_container[str];
            map_container[str] = p;
            write_block(p, chunk_reference);
            return 1;
        }
        else{
            map_container[str] = p;
            write_block(p, chunk_reference);
            return 1;
        }

    }
    return 0;
}

int map::write_block(struct addr *write_addr, char *chunk_reference) {
    struct aiocb64 aio;
    bzero((char *)&aio, sizeof(struct aiocb64));
    aio.aio_buf = malloc(4097);
    if(!aio.aio_buf)
        perror("malloc\n");
    aio.aio_fildes = fd;
    aio.aio_nbytes = BLOCK_SIZE;
    aio.aio_offset = write_addr->offset * BLOCK_SIZE;
    memcpy((void *)aio.aio_buf, (void *)chunk_reference, BLOCK_SIZE);
    aio_write64(&aio);
    while(EINPROGRESS == aio_error64(&aio));

    return 1;
}

int map::read_block(struct addr *write_addr, char *chunk_reference) {
    struct aiocb64 aio;
    bzero((char *)&aio, sizeof(struct aiocb64));
    aio.aio_buf = malloc(BLOCK_SIZE+1);
    if(!aio.aio_buf)
        perror("malloc\n");
    aio.aio_fildes = fd;
    aio.aio_nbytes = BLOCK_SIZE;
    aio.aio_offset = write_addr->offset * BLOCK_SIZE;

    aio_read64(&aio);
    while(EINPROGRESS == aio_error64(&aio));
    memset(chunk_reference, 0, BLOCK_SIZE+1);
    memcpy((void *)chunk_reference, (void *)aio.aio_buf, BLOCK_SIZE);

    return 1;
}
