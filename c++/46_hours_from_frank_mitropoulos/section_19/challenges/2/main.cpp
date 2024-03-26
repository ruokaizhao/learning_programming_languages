#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

const int first_column_width{20};
const int second_column_width{20};

int get_score(const std::string &answer, const std::string &response)
{
  // Get the size of the shorter vector from answer and response, so that
  // besides responding with the wrong answer, not reponding to a question
  // also results in losing a point.
  int size_to_compare = response.size() < response.size() ? response.size() : answer.size();
  int score{0};

  for (size_t i = 0; i < size_to_compare; ++i)
  {
    if (response.at(i) == answer.at(i))
    {
      ++score;
    }
  }

  return score;
}

int main()
{
  std::ifstream in_file{};
  in_file.open("responses.txt");

  if (!in_file)
  {
    std::cerr << "Failed opening the file." << std::endl;

    return 1;
  }

  std::vector<std::string> vec{};
  std::string line;

  while (!in_file.eof())
  {
    in_file >> line;
    vec.push_back(line);
  }

  std::string answer = vec.at(0);
  int number_of_students = (vec.size() - 1) / 2;
  int total_points{0};

  std::cout << std::setprecision(1) << std::fixed;

  std::cout << std::setw(first_column_width) << std::left << "Student" << std::setw(second_column_width) << std::right
            << "Score" << std::endl;
  std::cout << std::setw(first_column_width + second_column_width) << std::setfill('-') << "" << std::setfill(' ')
            << std::endl;

  for (size_t i = 1; i < vec.size(); i += 2)
  {
    int score = get_score(answer, vec.at(i + 1));
    std::cout << std::setw(first_column_width) << std::left << vec.at(i);
    std::cout << std::setw(second_column_width) << std::right << score << std::endl;
    total_points += score;
  }

  std::cout << std::setw(first_column_width + second_column_width) << std::setfill('-') << "" << std::setfill(' ')
            << std::endl;
  std::cout << std::setw(first_column_width) << std::left << "Average score";
  std::cout << std::setw(second_column_width) << std::right << (static_cast<double>(total_points) / number_of_students)
            << std::endl
            << std::endl;

  return 0;
}
