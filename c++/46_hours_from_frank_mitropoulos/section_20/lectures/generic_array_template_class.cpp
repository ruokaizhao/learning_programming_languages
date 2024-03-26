#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
  private:
  int size{N};
  T values[N];

  friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &array)
  {
    os << "[ ";
    for (const auto &value : array.values)
    {
      os << value << " ";
    }
    os << " ]" << std::endl;

    return os;
  }

  public:
  Array() = default;
  Array(T initial_value)
  {
    for (auto &value : values)
    {
      value = initial_value;
    }
  }
  ~Array() = default;

  int get_size() const
  {
    return size;
  }

  T operator[](int index) const
  {
    return values[index];
  }

  void fill(T fill_value)
  {
    for (auto &value : values)
    {
      value = fill_value;
    }
  }
};

int main()
{
  Array<int, 5> array1{100};
  std::cout << array1.get_size() << std::endl;
  std::cout << array1;
  array1.fill(200);
  std::cout << array1;

  Array<std::string, 50> array2{"Hello"};
  std::cout << array2.get_size() << std::endl;
  std::cout << array2;
  array2.fill("Hello World!");
  std::cout << array2;

  return 0;
}
