#include "Utils.cpp"
#include <iostream>

int main()
{
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec;
  vec = make();

  int number{};
  std::cout << "Enter the number of elements you want to have in the vector: ";
  std::cin >> number;

  fill(*vec, number);
  display(*vec);

  return 0;
}
