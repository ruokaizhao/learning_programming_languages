#include <chrono>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>

bool has_substring(const std::string &string, const std::string &substring, int index)
{
  if ((string.size() - index) < substring.size())
  {
    return false;
  }

  for (size_t i = 0; i < substring.size(); ++i)
  {
    if (string.at(index + i) != substring.at(i))
    {
      return has_substring(string, substring, index + 1);
    }
  }

  return true;
}

int main()
{

  std::ifstream in_file{};
  in_file.open("romeoandjuliet.txt");

  std::string word_from_file{};

  if (!in_file)
  {
    std::cerr << "Failed opening the file." << std::endl;
  }

  std::cout << "Enter a word: ";
  std::string word_from_user{};
  std::cin >> word_from_user;
  std::cout << std::endl;

  int total_words{0};
  int occurrence{0};

  auto start = std::chrono::high_resolution_clock::now();

  while (in_file >> word_from_file)
  {
    ++total_words;
    // if (has_substring(word_from_file, word_from_user, 0))
    // {
    //   ++occurrence;
    // }
    if (word_from_file.find(word_from_user) != std::string::npos)
    {
      ++occurrence;
    }
  }

  std::cout << total_words << " words searched, " << word_from_user << " appeared " << occurrence << " times."
            << std::endl
            << std::endl;

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << "The searching took " << duration.count() << " microseconds to finish." << std::endl;

  in_file.close();

  return 0;
}
