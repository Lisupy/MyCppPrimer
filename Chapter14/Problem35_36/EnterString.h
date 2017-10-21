#ifndef ENTER_STRING_H
#define ENTER_STRING_H

#include <istream>
#include <string>

class EnterString{
public:
  explicit EnterString(std::istream& i): is(i) {}
  
  std::string operator()();

private:
  std::istream& is;
};

#endif
