#pragma once
#include<vector>
#include<string>
#include<memory>

// 友元前置声明
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob {
public:
	typedef std::vector<std::string>::size_type size_type;
	
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend StrBlobPtr begin(StrBlob &blobItem);
	friend StrBlobPtr end(StrBlob &blobItem);
	friend ConstStrBlobPtr begin(const StrBlob &blobItem);
	friend ConstStrBlobPtr end(const StrBlob &blobItem);

	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
    
    // copy ctor
    StrBlob(const StrBlob&);
    // asigned operator
    StrBlob& operator=(const StrBlob&);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	
	// add and delete elem
	void push_back(const std::string &t) { data->push_back(t); }
	void pop_back();

	// visit elem
	std::string& front();
	std::string& back();

	const std::string& front() const;
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr begin() const;
	ConstStrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg) const;
};
