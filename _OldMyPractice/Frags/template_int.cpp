#include <cstdio>
#include <iostream>

template <int I>
class foo
{
public:
  void print()
  {
	  std::cout<<I<<std::endl;
  }
};

int main()
{
  foo<"Hi"> f;
  f.print();
  system("pause");
  return 0;
}