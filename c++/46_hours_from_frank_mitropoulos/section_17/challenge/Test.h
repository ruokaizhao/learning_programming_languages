#ifndef _TEST_H_
#define _TEST_H_
#include <iostream>

class Test
{
  private:
  int data;

  public:
  Test(int data_val = 0);
  ~Test();

  int get_data();
};

#endif
