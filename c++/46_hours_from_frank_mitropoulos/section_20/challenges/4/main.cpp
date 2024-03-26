// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <string>

bool is_palindrome(const std::string &s)
{
  std::stack<char, std::deque<char>> stack{};
  std::queue<char, std::deque<char>> queue{};

  for (auto &c : s)
  {
    if (std::isalpha(c))
    {
      stack.push(std::toupper(c));
      queue.push(std::toupper(c));
    }
  }

  if (stack.size() != queue.size())
  {
    return false;
  }

  while (!stack.empty())
  {
    if (stack.top() != queue.front())
    {
      return false;
    }
    stack.pop();
    queue.pop();
  }

  return true;
}

int main()
{
  std::vector<std::string> test_strings{"a",
                                        "aa",
                                        "aba",
                                        "abba",
                                        "abbcbba",
                                        "ab",
                                        "abc",
                                        "radar",
                                        "bob",
                                        "ana",
                                        "avid diva",
                                        "Amore, Roma",
                                        "A Toyota's a toyota",
                                        "A Santa at NASA",
                                        "C++",
                                        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                                        "This is a palindrome",
                                        "palindrome"};

  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result"
            << "String" << std::endl;
  for (const auto &s : test_strings)
  {
    std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
  }
  std::cout << std::endl;
  return 0;
}
