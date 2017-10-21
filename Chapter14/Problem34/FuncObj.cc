#include <iostream>

template <typename T>
class FuncObj{
public:
  T operator()(bool b, T ta, T tb){
    return b ? ta : tb;
  }
};


int main(){
  FuncObj<int> fun;
  std::cout << fun(true, 1, 2) << std::endl;
}
