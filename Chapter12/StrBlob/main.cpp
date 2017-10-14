#include"StrBlob.h"
#include"StrBlobPtr.h"
#include"ConstStrBlobPtr.h"
#include<iostream>
#include<fstream>

int main() {
	StrBlob b1;

	std::ifstream in("news.txt", std::ios::in);
	std::string line;
	while (std::getline(in, line)) {
		b1.push_back(line);
	}
	const StrBlob b2 = b1;
	auto it = b2.begin();

	try {
		while (1){
			std::cout << it.deref() << std::endl;
			it = it.incr();
		}
	}
	catch (std::exception e) {
		std::cerr << e.what() << std::endl;
	}
}