#include "math_utils.h"
#include <iostream>

int main()
{
  Rectangle rectangle;
  rectangle.length = 10;
  rectangle.width = 5;

  std::cout << utilz::area(rectangle.length, rectangle.width) << std::endl;
  std::cout << utilz::area(rectangle.length) << std::endl;
  std::cout << utilz::area(rectangle) << std::endl;

  std::cout << utilz::pow(5) << std::endl;

  return 0;
}
