
#include <iostream>
#include <set>
using namespace std;

struct hillCouple
{
    int x;
    int y;
};


int main(){
    set<struct hillCouple> s;
    struct hillCouple temp, temp1;
    temp.x = 1;
    temp.y = 2;
    temp1.x = 3;
    temp1.y = 4;
    s.insert(temp);
    s.insert(temp1);
}
