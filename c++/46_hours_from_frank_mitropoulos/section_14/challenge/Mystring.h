#ifndef _MYSTRING_H
#define _MYSTRING_H
#include <cstring>
#include <iostream>

class Mystring
{
  // Overloaded global functions
  // Overloaded insertion operator
  friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);

  // Overloaded extraction operator
  friend std::istream &operator>>(std::istream &is, Mystring &rhs);

  // // Overloaded negation operator
  // friend Mystring operator-(const Mystring &rhs);

  // // Overloaded pre increment operator
  // friend Mystring &operator++(Mystring &rhs);

  // // Overloaded post increment operator
  // friend Mystring operator++(Mystring &rhs, int);

  // // Overloaded pre decrement operator
  // friend Mystring &operator--(Mystring &rhs);

  // // Overloaded post decrement operator
  // friend Mystring operator--(Mystring &rhs, int);

  private:
  char *str;

  public:
  // Constructors
  // No args constructor
  Mystring();

  // One arg constructor
  Mystring(const char *str_val);

  // Copy constructor
  Mystring(const Mystring &source);

  // Move constructor
  Mystring(Mystring &&source);

  // Destructor
  ~Mystring();

  // Assignment operators
  // Overloaded copy assignment operator
  Mystring &operator=(const Mystring &rhs);

  // Overloaded move assignment operator
  Mystring &operator=(Mystring &&rhs);

  // Getter
  char *get_str() const;

  // Overloaded negation operator
  Mystring operator-() const;

  // Overloaded plus operator
  Mystring operator+(const Mystring &rhs) const;

  // Overloaded plus equal operator
  Mystring &operator+=(const Mystring &rhs);

  // Overloaded pre increment operator
  Mystring &operator++();

  // Overloaded post increment operator
  Mystring operator++(int);

  // Overload pre decrement operator
  Mystring &operator--();

  // Overloaded post decrement operator
  Mystring operator--(int);

  // Overloaded equality operator
  bool operator==(const Mystring &rhs) const;

  // Overloaded inequality operator
  bool operator!=(const Mystring &rhs) const;

  // Overloaded greater than operator
  bool operator>(const Mystring &rhs) const;

  // Overloaded less than operator
  bool operator<(const Mystring &rhs) const;

  // Overloaded multiple operator
  Mystring operator*(int multiple) const;

  // Overloaded multiple equal operator
  Mystring &operator*=(int multiple);
};

#endif
