#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::placeholders;


int main(){
  // (a)
  vector<int> vec = {1026, 4, 10343,123, 33};
  cout << count_if(vec.cbegin(), vec.cend(), bind(greater<int>(), _1, 1024)) << endl;
  // (b)
  vector<string> str_vec = {"pooh", "pooh", "polish"};
  cout << *find_if_not(str_vec.cbegin(), str_vec.cend(), bind(equal_to<string>(), _1, "pooh")) << endl;
  // (c)
  vec = {1, 2, 3, 4, 5, 6};
  transform(vec.begin(), vec.end(), vec.begin(),  bind(multiplies<int>(), 2, _1));
  for_each(vec.cbegin(), vec.cend(), [](const int &a){cout << a << " ";});
  cout<<endl;

  int n = 5;
  vector<int> divide_vec = {5, 10, 15, 20, 25, 30};
}
