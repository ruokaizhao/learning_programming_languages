#include <iostream>
#include <string>

int main()
{
  std::cout << "Enter a word: ";
  std::string word;
  std::cin >> word;

  for (int i = 0; i < word.size(); ++i)
  {
    for (int j = 1; j < word.size() - i; ++j)
    {
      std::cout << " ";
    }
    for (int k = 0; k < i; ++k)
    {
      std::cout << word.at(k);
    }
    for (int l = i; l >= 0; --l)
    {
      std::cout << word.at(l);
    }
    std::cout << std::endl;
  }
}
