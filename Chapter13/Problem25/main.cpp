#include"StrBlob.h"
#include"StrBlobPtr.h"
#include"ConstStrBlobPtr.h"
#include<iostream>
#include<fstream>

using namespace std;

int main() {
	StrBlob b1;

	std::ifstream in("news.txt", std::ios::in);
	std::string line;
	while (std::getline(in, line)) {
	    b1.push_back(line);
	}
	const StrBlob b2 = b1;
	auto it = b1.begin();

	try {
    	while (1){
            it.deref() = "Hello";
	        std::cout << it.deref() << std::endl;
	        it = it.incr();
    	}
	}
	catch (const exception &e) {
	    std::cerr << e.what() << std::endl;
	}

    std::cout << "============================" << std::endl;
    auto itb2 = b2.begin();

    try{
        while(1){
            std::cout << itb2.deref() << std::endl;
            itb2  = itb2.incr();
        }
    }
    catch (const exception &e){
        std::cerr << e.what() <<std::endl;
    }
}
