#ifndef CHAP12_TEXTQUERY_H
#define CHAP12_TEXTQUERY_H

#include <istream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include "QueryResult.h"

using line_no = std::vector<std::string>::size_type;

class TextQuery{
public:
    TextQuery(std::istream&);
    QueryResult query(const std::string&) const;


private:
    // share file content between TextQuery and QueryResult;
    std::shared_ptr<std::vector<std::string>> file;
    // share line set between TextQuery and QeuryResult
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // word map;
};


#endif
