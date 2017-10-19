#include "String.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    // string s("hello i'am ok");
    // cout << s.c_str() << endl;

    // cout << "length: " << s.length() << endl;
    // cout << "capacity: " << s.capacity() <<endl;
    // 
    // string s1;
    // cout << s1.c_str() << endl;
    // cout << "length: " << s1.length() << endl;
    // cout << "capacity: " << s1.capacity() << endl;

    // s1 = s; // copy assignment
    // cout << s1.c_str() << endl;
    // 
    // string s2 = s; // copy constructor
    std::vector<String> vec;
    for(int i=0; i< 16; ++i){
        vec.push_back("Hello");
        cout << "================" << endl;
    }
}
