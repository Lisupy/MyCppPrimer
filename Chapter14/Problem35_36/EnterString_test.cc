#include "EnterString.h"
#include <sstream>
#include <iostream>
#include <assert.h>

using namespace std;

int main(){
  istringstream iss("test for enter string");
  EnterString enter_str(iss);
  //cout << enter_str() << endl;
  assert(enter_str().length() == 21);

  istringstream iss2("test for enter string");
  iss2.setstate(stringstream::failbit);
  EnterString enter_str2(iss2);
  assert(enter_str2().length() == 0);
}
