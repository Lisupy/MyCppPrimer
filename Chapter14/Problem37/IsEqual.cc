#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class IsEqual{
  T val;
public:
  IsEqual(T v): val(v) {}
  bool operator()(T item){
    return item == val;
  }
};


int main(){
  std::vector<int> vec = {3, 2, 1, 4, 3, 7, 8, 6};
  std::replace_if(vec.begin(), vec.end(), IsEqual<int>(3), 5);
  for(const int &i: vec)
    std::cout << i << " ";
  std::cout << std::endl;
}
