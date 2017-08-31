//
// Created by victor on 5/28/17.
//

#ifndef ED_MAP_H
#define ED_MAP_H

#include <cstdint>
#include <iostream>
#include <map>

class map{
private:
    map();
    map(map const&);
    map &operator = (map const&);
    ~map();

    unsigned int ssd_capacity;
    unsigned long max_size_addr; //the maximum block address
    unsigned long alloc_addr_point;
    std::map<std::string, struct addr *> map_container; //save(ECC or hash code, block address)
    char *dev_name;
    int fd;
public:
    static map *Get_map();
    static map *map_instance;
    struct addr* Get_addr(char ecc_code[], int length_ecc);  //get the chunk addr from the map list
    int insert_map(char ecc_code[], char chunk_reference[], int length_ecc); //insert a new ecc-addr pair to the map list and in the mean time write the block
    int write_block(struct addr *write_addr, char chunk_reference[]);
    int read_block(struct addr* write_addr, char chunk_reference[]);
    struct addr{
        unsigned long offset; //block address
        struct addr *next;
    };
};




#endif //ED_MAP_H
