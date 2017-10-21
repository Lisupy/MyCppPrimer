#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool can_all_devide(vector<int> &vec, int n){
  auto it = find_if(vec.cbegin(), vec.cend(), bind(modulus<int>(), _1, n));
  return it == vec.cend();
}

int main(){
  int n = 5;
  vector<int> divide_vec = {5, 10, 15, 20, 25, 30};
  if(can_all_devide(divide_vec, n))
    cout<< "yes" << endl;
  else
    cout<< "no" << endl;

  divide_vec.push_back(16);
  if(can_all_devide(divide_vec, n))
    cout<< "yes" << endl;
  else
    cout<< "no" << endl;
}
