#include "student.h"
#include "teacher.h"
#include "user.h"

void do_something(User &user)
{
  user.output();
}

// void do_something(Teacher teacher)
// {
//   teacher.output();
// }
//
// void do_something(Student student)
// {
//   student.output();
// }

int main()
{
  Teacher teacher;
  Student student;
  User &u1 = teacher;
  User &u2 = student;

  do_something(u1);
  do_something(u2);
}
