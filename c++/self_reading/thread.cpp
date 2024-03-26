#include <iostream>
#include <thread>
#include <unistd.h>

void wait(int n)
{
  sleep(n);
}

int main()
{
  std::thread t1{wait, 5};

  std::cout << "Does not wait." << '\n';

  t1.join();

  std::cout << "Does wait." << '\n';
}
