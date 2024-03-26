#include <cstdlib>
#include <iostream>

int main()
{
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int *p = new int[n];

  for (int i = 0; i < n; i++)
  {
    p[i] = i + 1;
  }

  for (int i = 0; i < n; i++)
  {
    std::cout << p[i] << std::endl;
  }

  delete[] p;

  std::cout << *p << std::endl;

  return 0;
}
