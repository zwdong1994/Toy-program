#include <iostream>
#include <map>
#include <string>

typedef struct info{
    std::string str;
}inform;

int main(){
    std::map<std::string, inform *> test_map;
    inform test_info;
    test_info.str = "sdfafd";
    std::string id = "123";
    test_map[id] = &test_info;
    if(test_map[id] == NULL){
        std::cout<<id<<" not exist"<<std::endl;
    }
    else{
        inform *mid = NULL;
        mid = test_map[id];
        std::cout<<"test string is: "<< mid->str <<std::endl;

    }
    if(test_map["345"] == NULL){
        std::cout<<"345 not exist"<<std::endl;
    }
    return 0;
}
