#include "QueryResult.h"
#include "TextQuery.h"
#include <ostream>

using std::ostream;
using std::endl;
using std::string;
using std::size_t;

string make_plural(size_t num, string word, string s){
    if(num >= 2)
        return word + s;
    return word;
}

ostream& print(ostream &os, const QueryResult& ret){
    os << ret.sought << " occurs " << ret.lines->size() << " "
       << make_plural(ret.lines->size(), "time", "s") << endl;

    for(auto num: *ret.lines)
        os << "\t (line " << num + 1 << ")" << *(ret.file->begin()+num) << endl;
    return os;
}
