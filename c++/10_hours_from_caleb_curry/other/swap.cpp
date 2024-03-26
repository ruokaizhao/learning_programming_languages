#include <iostream>
#include <string>

template <typename T>
void swap(T &, T &);

template <typename T>
void swap(T[], T[], int);

int main()
{
  int a = 5;
  int b = 10;
  std::cout << "a is: " << a << std::endl;
  std::cout << "b is: " << b << std::endl;
  swap(a, b);
  std::cout << "a is: " << a << std::endl;
  std::cout << "b is: " << b << std::endl;

  std::string first_name = "Ruokai";
  std::string last_name = "Zhao";
  std::cout << first_name << last_name << std::endl;
  swap(first_name, last_name);
  std::cout << first_name << last_name << std::endl;

  char nines[] = {'9', '9', '9', '9', '9', '9'};
  char ones[] = {'1', '1', '1', '1', '1', '1'};

  for (int i = 0; i < 6; i++)
  {
    std::cout << nines[i] << " " << ones[i] << "\t";
  }
  std::cout << "\n\n";

  swap(nines, ones, 6);

  for (int i = 0; i < 6; i++)
  {
    std::cout << nines[i] << " " << ones[i] << "\t";
  }
  std::cout << "\n\n";

  return 0;
}

template <typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void swap(T a[], T b[], int size)
{
  for (int i = 0; i < size; i++)
  {
    T temp = *(a + i);
    *(a + i) = *(b + i);
    *(b + i) = temp;
  }
}
