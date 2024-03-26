#include "Mystring.cpp"
#include <algorithm>
#include <vector>

int main()
{
  // std::vector<Mystring> vec;

  Mystring a;

  Mystring b{"BBB"};

  // Mystring c{b};

  // vec.push_back(Mystring{"ddd"});

  a = b;
  a += b;
  std::cout << a;

  // b = Mystring{"aaa"};
  //
  // std::cout << ++a;
  // std::cout << a;
  // std::cout << --a;
  // std::cout << a;

  // a = a + b;

  // std::cout << a;

  // if (a > b)
  // {
  //   std::cout << "a > b" << std::endl;
  // }
  // if (a < b)
  // {
  //   std::cout << "a < b" << std::endl;
  // }

  // b = a * 3;
  // std::cout << a;
  // std::cout << b;
  // a *= 3;
  // std::cout << a;
  // a = -a;
  // std::cout << a;
  // std::cin >> a;
  // std::cout << a;
}
