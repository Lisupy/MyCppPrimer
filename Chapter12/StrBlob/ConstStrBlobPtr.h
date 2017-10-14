#pragma once
#include "StrBlob.h"

class ConstStrBlobPtr{
private:
	// variable member
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;

	// variable function
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, std::string msg) const;

public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob&a, std::size_t sz = 0) :wptr(a.data), curr(sz) {}

	ConstStrBlobPtr incr();
	const std::string deref() const;
};

