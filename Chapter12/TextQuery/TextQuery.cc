#include "QueryResult.h"
#include "TextQuery.h"
#include <sstream>

using std::vector;
using std::string;
using std::istringstream;
using std::shared_ptr;
using std::set;

TextQuery::TextQuery(std::istream &is): file(new vector<string>){
    string text;
    while(std::getline(is, text)){
        file->push_back(text);
        line_no n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word){
            // 如果单词不在wm中, 以之为下标在wm中添加一项
            auto &lines = wm[word];  // lines 是一个shared_ptr
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &s) const{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    
    auto loc = wm.find(s);
    if(loc == wm.end())
        return QueryResult(s, nodata, file); // no found
    else
        return QueryResult(s, loc->second, file);
}
