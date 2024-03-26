#include "Test.h"

Test::Test(int data_val) : data{data_val}
{
  std::cout << "\tConstructor called for " << data << std::endl;
}

Test::~Test()
{
  std::cout << "\tDestructor called for " << data << std::endl;
}

int Test::get_data()
{
  return data;
}
