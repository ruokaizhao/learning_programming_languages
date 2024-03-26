#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

class User
{
  static int user_count;
  std::string _status = "Gold";

  public:
  std::string first_name;
  std::string last_name;

  static int get_user_count();

  std::string get_status();

  void set_status(std::string status);

  User();

  User(std::string first_name, std::string last_name);

  ~User();

  virtual void output();

  friend std::ostream &operator<<(std::ostream &output, const User user);
  friend std::istream &operator>>(std::istream &input, User &user);
};
#endif
