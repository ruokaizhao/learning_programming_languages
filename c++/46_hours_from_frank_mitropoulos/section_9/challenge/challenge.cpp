#include <iostream>
#include <vector>

void Print(const std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    std::cout << "[] - the list is empty" << std::endl;
    return;
  }

  std::cout << "[ ";

  for (int element : vec)
  {
    std::cout << element << " ";
  }

  std::cout << "]";

  std::cout << std::endl;
}

void AddToVector(std::vector<int> &vec, int number)
{
  for (int element : vec)
  {
    if (element == number)
    {
      std::cout << number << " is already in the list, please try a different number" << std::endl;
      return;
    }
  }
  vec.push_back(number);

  std::cout << number << " Added" << std::endl;
}

void CalculateMean(const std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    std::cout << "Unable to calculate the mean - no data" << std::endl;
    return;
  }

  double sum{0};

  for (double element : vec)
  {
    sum += element;
  }

  double mean = sum / vec.size();

  std::cout << "The mean is " << mean << std::endl;
}

void FindMin(const std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    std::cout << "Unable to determine the smallest number - list is empty" << std::endl;

    return;
  }
  int tempMin{vec.at(0)};

  for (int element : vec)
  {
    if (element < tempMin)
    {
      tempMin = element;
    }
  }

  std::cout << "The smallest number is " << tempMin << std::endl;
}

void FindMax(const std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    std::cout << "Unable to determine the largest number - list is empty" << std::endl;

    return;
  }
  int tempMax{vec.at(0)};

  for (int element : vec)
  {
    if (element > tempMax)
    {
      tempMax = element;
    }
  }

  std::cout << "The largest number is " << tempMax << std::endl;
}

void ClearList(std::vector<int> &vec)
{
  if (vec.size() == 0)
  {
    std::cout << "The list is alreay empty" << std::endl;

    return;
  }
  vec.clear();

  std::cout << "The list has been cleared" << std::endl;
}

int main()
{
  char input{0};
  std::vector<int> vec{};

  while (true)
  {
    std::cout << "P - Print numbers" << std::endl;
    std::cout << "A - Add a number" << std::endl;
    std::cout << "M - Display mean of the numbers" << std::endl;
    std::cout << "S - Display the smallest number" << std::endl;
    std::cout << "L - Display the largest number" << std::endl;
    std::cout << "C - Clear the list" << std::endl;
    std::cout << "Q - Quit" << std::endl;

    std::cout << "Enter your choice:" << std::endl;
    std::cin >> input;

    switch (input)
    {
    case 'q':
    case 'Q':
      std::cout << "Goodbye" << std::endl;
      return 0;
    case 'p':
    case 'P':
      Print(vec);
      break;
    case 'a':
    case 'A': {
      int number{0};
      std::cout << "Enter a number:" << std::endl;
      std::cin >> number;
      AddToVector(vec, number);
      break;
    }
    case 'm':
    case 'M':
      CalculateMean(vec);
      break;
    case 's':
    case 'S':
      FindMin(vec);
      break;
    case 'l':
    case 'L':
      FindMax(vec);
      break;
    case 'c':
    case 'C':
      ClearList(vec);
      break;
    default:
      std::cout << "Unknown selection, please try again" << std::endl;
    }
  }

  return 0;
}
