#pragma once
#include"StrBlob.h"

// StrBlob指针伴随类
class StrBlobPtr {
private:
	// private function member
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	
	// private variable member
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, std::size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr(); // 前缀递增。
};