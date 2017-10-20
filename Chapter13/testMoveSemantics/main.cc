#include "HasPtr2.h"
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

int main(){
    vector<HasPtr> cpy(2, HasPtr("abcefghijklmn"));

    int index = 0;
    
    auto t0 = high_resolution_clock::now();
    for(int i=0; i<1e7; ++i){
        cpy[index] = cpy[1-index];
        index = 1 - index;
    }
    auto t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1-t0).count() << "ms\n";

    vector<HasPtr> mov(2, HasPtr("abcefghijklmn"));
    index = 0;
    t0 = high_resolution_clock::now();
    for(int i=0; i<1e7; ++i){
        mov[index] = std::move(mov[1-index]);
        index = 1 - index;
    }
    t1 = high_resolution_clock::now();
    cout << duration_cast<milliseconds>(t1-t0).count() << "ms\n";
}
