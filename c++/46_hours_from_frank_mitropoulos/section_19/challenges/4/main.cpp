#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::ifstream in_file{};
  std::ofstream out_file{};

  in_file.open("romeoandjuliet.txt");
  out_file.open("romeoandjuliet_out.txt");

  if (!in_file)
  {
    std::cerr << "Failed opening file." << std::endl;
    return 1;
  }
  if (!out_file)
  {
    std::cerr << "Failed creating file." << std::endl;
    return 1;
  }

  std::string line{};
  int line_number{1};

  while (std::getline(in_file, line))
  {
    out_file << std::setw(7) << std::left << line_number << line << std::endl;
    ++line_number;
  }

  std::cout << "Completed" << std::endl;

  in_file.close();
  out_file.close();

  return 0;
}
