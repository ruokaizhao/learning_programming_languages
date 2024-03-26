#include "Test.cpp"
#include <iostream>
#include <memory>
#include <vector>

auto make();

void fill(std::vector<std::shared_ptr<Test>> &vec, int number);

void display(const std::vector<std::shared_ptr<Test>> &vec);
