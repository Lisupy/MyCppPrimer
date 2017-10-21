#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class StringLen{
public:
  StringLen(size_t lb, size_t up): lwbound(lb), upbound(up) {}

  bool operator()(string &s){
    return s.length() >= lwbound && s.length() < upbound;
  }

private:
  size_t lwbound;
  size_t upbound;
};

int main(int argc, char* argv[]){
  if(argc != 2){
    cerr << "usage: " << argv[0] << " <infile>" << endl;
    exit(1);
  }

  vector<string> wrdvec;
  ifstream ifs(argv[1], ios::in);
  string buf;
  while(ifs >> buf){
    wrdvec.push_back(buf);
  }
  cout << count_if(wrdvec.begin(), wrdvec.end(), StringLen(1, 10)) << endl;
  cout << count_if(wrdvec.begin(), wrdvec.end(), StringLen(10, 0x7fffffff)) << endl;
}
