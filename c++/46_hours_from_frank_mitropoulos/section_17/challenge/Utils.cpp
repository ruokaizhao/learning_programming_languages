#include "Utils.h"

auto make()
{
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int number)
{
  for (size_t i = 1; i <= number; ++i)
  {
    int data{};
    std::cout << "Enter the data for vector[" << i << "]: ";
    std::cin >> data;

    std::shared_ptr<Test> test_obj = std::make_shared<Test>(data);
    std::cout << "\t" << data << " added to the vector." << std::endl;
    vec.push_back(test_obj);
  }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
  std::cout << "The elements in the vector are:" << std::endl;

  for (const auto &test_ptr : vec)
  {
    std::cout << test_ptr->get_data() << std::endl;
  }
}
