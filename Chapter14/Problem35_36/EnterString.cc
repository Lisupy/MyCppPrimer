#include "EnterString.h"
#include <istream>
#include <string>

using namespace std;

string EnterString::operator()(){
  string s;
  getline(is, s);
  if(!is)
    s = "";
  return s;
}

