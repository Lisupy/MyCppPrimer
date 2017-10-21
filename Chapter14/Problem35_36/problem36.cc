#include "EnterString.h"
#include <vector>
#include <fstream>
#include <memory>
#include <iostream>
using namespace std;

int main(){
  ifstream ifs("news.txt", ios::in);
  EnterString fun(ifs);

  vector<string> strvec;
  while(true){
    strvec.push_back(fun());
    if(strvec.back().size() == 0){
      strvec.pop_back();
      break;
    }
  }

  for(const string &s: strvec)
    cout << s << '\n';
  cout << ends;
}
