#include <array>
#include <iostream>
#include <vector>

namespace utilz
{
void print_vector(std::vector<std::vector<int>>);
}

using namespace utilz;

int main()
{
  std::vector<std::vector<int>> grades = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  print_vector(grades);
}

namespace utilz
{
void print_vector(std::vector<std::vector<int>> arrays)
{
  for (std::vector<int> array : arrays)
  {
    for (int element : array)
    {
      std::cout << element << "\t";
    }
    std::cout << std::endl;
  }
}
} // namespace utilz
