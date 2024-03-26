// Section 20
// Challenge 3
// Maps and Sets

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>

// Used for Part1
// Display the word and count from the
// std::map<std::string, int>

void display_words(const std::map<std::string, int> &words)
{
  std::cout << std::setw(12) << std::left << "\nWord" << std::setw(7) << std::right << "Count" << std::endl;
  std::cout << "===================" << std::endl;
  for (auto pair : words)
    std::cout << std::setw(12) << std::left << pair.first << std::setw(7) << std::right << pair.second << std::endl;
}

// Used for Part2
// Display the word and occurences from the
// std::map<std::string, std::set<int>>

void display_words(const std::map<std::string, std::set<int>> &words)
{
  std::cout << std::setw(12) << std::left << "\nWord"
            << "Occurrences" << std::endl;
  std::cout << "=====================================================================" << std::endl;
  for (auto pair : words)
  {
    std::cout << std::setw(12) << std::left << pair.first << std::left << "[ ";
    for (auto i : pair.second)
      std::cout << i << " ";
    std::cout << "]" << std::endl;
  }
}

// This function removes periods, commas, semicolons and colon in
// a string and returns the clean version
std::string clean_string(const std::string &s)
{
  std::string result;
  for (char c : s)
  {
    if (c == '.' || c == ',' || c == ';' || c == ':')
      continue;
    else
      result += c;
  }
  return result;
}

// Part1 process the file and builds a map of words and the
// number of times they occur in the file

void part1()
{
  std::ifstream in_file{"words.txt"};

  if (in_file)

  {
    std::map<std::string, int> words;
    std::string line;
    while (std::getline(in_file, line))
    {
      std::istringstream ss{line};
      std::string word;
      while (ss >> word)
      {
        word = clean_string(word);
        auto iterator = words.insert(std::pair<std::string, int>{word, 1});
        if (iterator.second == 0)
        {
          ++words[word];
        }
      }
    }

    in_file.close();
    display_words(words);
  }
  else
  {
    std::cerr << "Error opening input file" << std::endl;
  }
}

// Part2 process the file and builds a map of words and a
// set of line numbers in which the word appears
void part2()
{
  std::ifstream in_file{"words.txt"};
  if (in_file)
  {
    std::map<std::string, std::set<int>> words{};
    int line_number{1};
    std::string line{};

    while (std::getline(in_file, line))
    {
      std::istringstream ss{line};
      std::string word;
      while (ss >> word)
      {
        word = clean_string(word);
        auto iterator = words.insert(std::make_pair(word, std::set{line_number}));
        if (iterator.second == 0)
        {
          words[word].insert(line_number);
        }
      }
      ++line_number;
    }

    in_file.close();
    display_words(words);
  }
  else
  {
    std::cerr << "Error opening input file" << std::endl;
  }
}

int main()
{
  part1();
  part2();

  return 0;
}
