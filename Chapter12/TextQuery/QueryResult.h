#ifndef CHAP12_QUERYRESULT_H
#define CHAP12_QUERYRESULT_H

#include <ostream>
#include <memory>
#include <set>
#include <vector>

using line_no = std::vector<std::string>::size_type;

class QueryResult{
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    
    QueryResult(std::string s, 
                std::shared_ptr<std::set<line_no>> p, 
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) {}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif
