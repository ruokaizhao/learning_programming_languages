#ifndef TEACHER_H

#include "user.h"

class Teacher : public User
{
  public:
  std::vector<std::string> classes_teaching;
  void output();
};

#endif
