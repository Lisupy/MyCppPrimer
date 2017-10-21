#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class StringLen{
public:
  StringLen(size_t s): sz(s) {}
  bool operator()(string &s){
    return s.length() == sz;
  }

private:
  size_t sz;  
};

size_t countString(vector<string> &vec, size_t len){
  return count_if(vec.begin(), vec.end(), StringLen(len));
}

int main(int argc, char* argv[]){
  if(argc != 2){
    cerr << "usage: " << argv[0] << " <len>" << endl;
    exit(1);
  }

  vector<string> wrdvec;
  ifstream ifs("news.txt", ios::in);
  string buf;
  while(ifs >> buf){
    wrdvec.push_back(buf);
  }
  cout << countString(wrdvec, stoul(argv[1])) << endl;
}
