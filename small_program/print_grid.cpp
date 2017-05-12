#include <iostream>
#include <string.h>
#include <iomanip>

int main(void){
    int a[200];
    for( int i = 0; i < 200; i++ ){
        a[i] = 0;
        if(i>50 && i<100)
            a[i] = 1;
        if(i>=100 && i<150)
            a[i] = 2;
        if(i>= 150 )
            a[i] = 3;
    }

    for( int i = 0; i < 200; i++ ){
        if(i % 25 == 0 && i != 0)
            std::cout<<std::endl<<std::endl;
        if( a[i] == 0 ){
            std::cout<<std::left<<std::setw(4)<<"O";
        }
        else if( a[i] == 1 ){
            std::cout<<std::left<<std::setw(4)<<"-";
        }
        else if( a[i] == 2 ){
            std::cout<<std::left<<std::setw(4)<<"X";
        }
        else
            std::cout<<std::left<<std::setw(4)<<"*";
    }
    std::cout<<std::endl;
    return 0;
}
