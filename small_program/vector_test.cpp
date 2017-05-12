#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    set<string> list;
    list.insert("asdfsadfasasdf");
    list.insert("sdfasdfsaf");
    list.insert("123");
    list.insert("123");
    if(list.find("22") == list.end())
            list.insert("22");
    else
            cout<<"not exist"<<endl;

    if(list.find("22") != list.end())
            cout<<"exist"<<endl;
    else
            cout<<"not exist"<<endl;
    return 1;
}
