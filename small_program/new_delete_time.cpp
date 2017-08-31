#include <iostream>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <stdint.h>
#include <unistd.h>

struct cache_list{
    std::string code;
    struct cache_list *next;
    struct cache_list *prev;

};

struct Code_chunk{
    uint8_t chunk[4096];
    struct Code_chunk *next; //point to the next same ecc code or hash code, but the chunk reference are different

};

double get_time(void){
    struct timeval mytime;
    gettimeofday(&mytime,NULL);
    return (mytime.tv_sec*1.0+mytime.tv_usec/1000000.0);
}

int main(){
    struct cache_list *add_member = NULL;
    struct Code_chunk *new_code_chunk = NULL;
    double stat_time = 0.0, end_time = 0.0;
    char buf[4097], buf2[4097];
    int i = 0;
    for(; i < 4096; i++){
        buf[i] = 'a' + i%26;
    }
    buf[4096] = '/0';



    stat_time = get_time();
    add_member = new cache_list;
    add_member -> code = buf;
    end_time = get_time();

    std::cout<< "new cache_list time " << (end_time - stat_time) * 1000 <<std::endl;

    stat_time = get_time();
    delete add_member;
    end_time = get_time();
    std::cout<< "delete cache_list time " << (end_time - stat_time) * 1000 <<std::endl;

    stat_time = get_time();
    new_code_chunk = new Code_chunk;
    memcpy(new_code_chunk -> chunk, buf, 4096);
    end_time = get_time();
    std::cout<< "new code_chunk time " << (end_time - stat_time) * 1000 <<std::endl;

    stat_time = get_time();
    delete new_code_chunk;
    end_time = get_time();
    std::cout<< "delete Code_chunk time " << (end_time - stat_time) * 1000 <<std::endl;

    return 0;




}
