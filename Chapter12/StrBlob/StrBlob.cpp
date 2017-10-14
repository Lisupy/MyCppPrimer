#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include <exception>

using std::vector;
using std::string;
using std::make_shared;
using std::initializer_list;
using std::out_of_range;


/* *************** StrBlob 的定义 ****************/
StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) :
	data(make_shared<vector<string>>(il)) {}


void 
StrBlob::check(size_type i, const string &msg) const {
	if (i >= data->size())
		throw out_of_range(msg);
}

string& 
StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}

string& 
StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}

void 
StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

const string& 
StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& 
StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr 
StrBlob::begin() {
	return StrBlobPtr(*this); 
}

StrBlobPtr 
StrBlob::end() {
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr
StrBlob::begin() const{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr
StrBlob::end() const {
	return ConstStrBlobPtr(*this, data->size());
}

StrBlobPtr begin(StrBlob &blobItem) {
	return StrBlobPtr(blobItem);
}

StrBlobPtr end(StrBlob &blobItem) {
	return StrBlobPtr(blobItem, blobItem.size());
}

ConstStrBlobPtr begin(const StrBlob &blobItem) {
	return ConstStrBlobPtr(blobItem);
}

ConstStrBlobPtr end(const StrBlob &blobItem) {
	return ConstStrBlobPtr(blobItem, blobItem.size());
}