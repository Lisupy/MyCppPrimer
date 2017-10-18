#include "StrVec.h"
#include <iostream>

int main(){
    StrVec vec;
    for(int i=0; i< 10; ++i){
        vec.push_back("Hello World");
        std::cout<<vec.capacity()<<std::endl;
    }
    vec.resize(20, "you");
    for(auto it=vec.begin(); it!=vec.end(); ++it){
        std::cout<<*it<<std::endl;
    }
    std::cout<<vec.capacity()<<std::endl;
    vec.push_back("Done");
    std::cout<<vec.capacity()<<std::endl;
    
    StrVec ilVec= {"Hello", "hello", "hello world", "hey", "god"};
    for(auto it=ilVec.begin(); it!=ilVec.end(); ++it)
        std::cout<<*it<<std::endl;
    std::cout<<ilVec.capacity()<<std::endl;

}
