#include "Mystring.h"

// Overloaded global functions
// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
  os << rhs.str << std::endl;
  return os;
}

// Overloaded extraction operator
std::istream &operator>>(std::istream &is, Mystring &rhs)
{
  char *temp = new char[1000];
  is >> temp;
  rhs = Mystring{temp};
  delete[] temp;
  return is;
}

// // Overloaded negation operator
// Mystring operator-(const Mystring &rhs)
// {
//   char *temp = new char[std::strlen(rhs.str) + 1];
//   std::strcpy(temp, rhs.str);

//   for (size_t i = 0; i < std::strlen(temp); ++i)
//   {
//     temp[i] = std::tolower(temp[i]);
//   }

//   Mystring newString{temp};
//   delete[] temp;
//   return newString;
// }

// // Overloaded pre increment operator
// Mystring &operator++(Mystring &rhs)
// {
//   std::cout << "Pre increment operator called." << std::endl;
//   char *temp = new char[std::strlen(rhs.str) + 1];
//   std::strcpy(temp, rhs.str);

//   for (size_t i = 0; i < std::strlen(rhs.str); ++i)
//   {
//     temp[i] = std::toupper(temp[i]);
//   }

//   rhs = Mystring{temp};
//   return rhs;
// }

// // Overloaded post increment operator
// Mystring operator++(Mystring &rhs, int)
// {
//   std::cout << "Post increment operator called." << std::endl;
//   Mystring temp = rhs;
//   ++rhs;
//   return temp;
// }

// // Overloaded pre decrement operator
// Mystring &operator--(Mystring &rhs)
// {
//   std::cout << "Pre decrement operator called." << std::endl;
//   char *temp = new char[std::strlen(rhs.str) + 1];
//   std::strcpy(temp, rhs.str);

//   for (size_t i = 0; i < std::strlen(rhs.str); ++i)
//   {
//     temp[i] = std::tolower(temp[i]);
//   }

//   rhs = Mystring{temp};
//   return rhs;
// }

// // Overloaded post decrement operator
// Mystring operator--(Mystring &rhs, int)
// {
//   std::cout << "Post decrement operator called." << std::endl;
//   Mystring temp = rhs;
//   --rhs;
//   return temp;
// }

// Constructors
// No args constructor
Mystring::Mystring() : str{nullptr}
{
  str = new char[1];
  *str = '\0';
  std::cout << "No args constructor called" << std::endl;
}

// One arg constructor
Mystring::Mystring(const char *str_val) : str{nullptr}
{
  if (str_val == nullptr)
  {
    str = new char[1];
    *str = '\0';
  }
  else
  {
    str = new char[std::strlen(str_val) + 1];
    std::strcpy(str, str_val);
  }
  std::cout << "One arg constructor called." << std::endl;
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr}
{
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  std::cout << "Copy constructor called" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) : str{source.str}
{
  source.str = nullptr;
  std::cout << "Move constructor called" << std::endl;
}

// Destructor
Mystring::~Mystring()
{
  if (str == nullptr)
  {
    std::cout << "Destructor for nullptr called" << std::endl;
  }
  else
  {

    std::cout << "Destructor for " << str << " called" << std::endl;
  }
  delete[] str;
}

// Assignment operators
// Overloaded copy assignment operator
Mystring &Mystring::operator=(const Mystring &source)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &source)
  {
    return *this;
  }
  delete[] str;
  str = new char[std::strlen(source.str) + 1];
  std::strcpy(str, source.str);
  return *this;
}

// Overloaded move assignment operator
Mystring &Mystring::operator=(Mystring &&source)
{
  std::cout << "Move assignment operator called" << std::endl;
  if (this == &source)
  {
    return *this;
  }
  delete[] str;
  str = source.str;
  source.str = nullptr;
  return *this;
}

// Getter
char *Mystring::get_str() const
{
  return str;
}

// Overloaded negation operator
Mystring Mystring::operator-() const
{
  char *temp = new char[std::strlen(str) + 1];
  std::strcpy(temp, str);

  for (size_t i = 0; i < std::strlen(temp); ++i)
  {
    temp[i] = std::tolower(temp[i]);
  }

  Mystring newString{temp};
  delete[] temp;
  return newString;
}

// Overloaded plus operator
Mystring Mystring::operator+(const Mystring &rhs) const
{
  char *temp = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
  std::strcpy(temp, str);
  std::strcat(temp, rhs.str);

  Mystring newString{temp};
  delete[] temp;
  return newString;
}

// Overloaded plus equal operator
Mystring &Mystring::operator+=(const Mystring &rhs)
{
  *this = *this + rhs;
  return *this;
}

// // Overloaded pre increment operator
Mystring &Mystring::operator++()
{
  std::cout << "Pre increment operator called." << std::endl;
  char *temp = new char[std::strlen(str) + 1];
  std::strcpy(temp, str);

  for (size_t i = 0; i < std::strlen(temp); ++i)
  {
    temp[i] = std::toupper(temp[i]);
  }
  *this = Mystring{temp};
  delete[] temp;
  return *this;
}

// Overloaded post increment operator
Mystring Mystring::operator++(int)
{
  std::cout << "Post increment operator called." << std::endl;
  Mystring temp = *this;
  ++(*this);
  return temp;
}

// Overload pre decrement operator
Mystring &Mystring::operator--()
{
  std::cout << "Pre decrement operator called." << std::endl;
  char *temp = new char[std::strlen(str) + 1];
  std::strcpy(temp, str);

  for (size_t i = 0; i < std::strlen(str); ++i)
  {
    temp[i] = std::tolower(temp[i]);
  }

  *this = Mystring{temp};
  delete[] temp;
  return *this;
}

// Overloaded post decrement operator
Mystring Mystring::operator--(int)
{
  std::cout << "Post decrement operator called." << std::endl;
  Mystring temp = *this;
  --(*this);
  return temp;
}

// Overloaded equality operator
bool Mystring::operator==(const Mystring &rhs) const
{
  if (std::strcmp(str, rhs.str) == 0)
  {
    return true;
  }
  return false;
}

// Overloaded inequality operator
bool Mystring::operator!=(const Mystring &rhs) const
{
  if (std::strcmp(str, rhs.str) == 0)
  {
    return false;
  }
  return true;
}

// Overloaded greater than operator
bool Mystring::operator>(const Mystring &rhs) const
{
  if (std::strcmp(str, rhs.str) > 0)
  {
    return true;
  }
  return false;
}

// Overloaded less than operator
bool Mystring::operator<(const Mystring &rhs) const
{
  if (std::strcmp(str, rhs.str) < 0)
  {
    return true;
  }
  return false;
}

// Overloaded multiple operator
Mystring Mystring::operator*(int multiple) const
{
  if (multiple <= 0)
  {
    std::cout << "Please use a positive number." << std::endl;
    return Mystring();
  }
  else
  {
    char *temp = new char[std::strlen(str) * multiple + 1];
    std::strcpy(temp, str);

    for (size_t i = 1; i < multiple; ++i)
    {
      std::strcat(temp, str);
    }

    Mystring newString{temp};
    delete[] temp;
    return newString;
  }
}

// Overloaded multiple equal operator
Mystring &Mystring::operator*=(int multiple)
{
  *this = (*this) * multiple;
  return *this;
}
