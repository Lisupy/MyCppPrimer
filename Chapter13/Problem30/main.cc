#include "HasPtr.h"
#include <iostream>

using namespace std;

int main(){
    HasPtr p1("Hello P1");
    HasPtr p2("Hello P2");

    HasPtr p3 = p1;
    HasPtr p4(p2);

    swap(p1, p2);
    print(cout<<"p1 content: ", p1)<<endl;
    print(cout<<"p2 content: ", p3)<<endl;
    print(cout<<"p3 content: ", p2)<<endl;
    print(cout<<"p4 content: ", p4)<<endl;
}
