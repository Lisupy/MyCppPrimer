#include "ConstStrBlobPtr.h"

using std::shared_ptr;
using std::vector;
using std::string;
using std::size_t;

shared_ptr<vector<string>>
ConstStrBlobPtr::check(size_t i, string msg) const {
	auto p = wptr.lock();
	if (!p) {
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}
	if (i >= p->size())
		throw std::out_of_range(msg);
	return p;
}

ConstStrBlobPtr 
ConstStrBlobPtr::incr() {
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

const string
ConstStrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}