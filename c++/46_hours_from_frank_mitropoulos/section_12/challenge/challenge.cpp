#include <iostream>

int *apply_all(const int *const array1, int size1, const int *const array2, int size2);
void print(const int *const array, int size);

int main()
{
  int array1[]{1, 2, 3, 4, 5};
  int array2[]{10, 20, 30};

  std::cout << "Array 1: ";
  print(array1, 5);

  std::cout << "Array 2: ";
  print(array2, 3);

  int *result = apply_all(array1, 5, array2, 3);
  std::cout << "Result: ";
  print(result, 15);

  delete[] result;
}

int *apply_all(const int *const array1, int size1, const int *const array2, int size2)
{
  int *result = new int[size1 * size2];

  for (int i = 0; i < size2; ++i)
  {
    for (int j = 0; j < size1; ++j)
    {
      *(result + i * size1 + j) = *(array1 + j) * *(array2 + i);
    }
  }

  return result;
}

void print(const int *const array, int size)
{
  std::cout << "[ ";
  for (int i = 0; i < size; ++i)
  {
    std::cout << *(array + i) << " ";
  }
  std::cout << " ]";
  std::cout << std::endl;
}
