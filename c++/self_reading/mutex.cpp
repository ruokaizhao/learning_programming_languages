#include <iostream>
#include <mutex>
#include <thread>

int number_with_data_racing = 0;
int number_without_data_racing = 0;
std::mutex mtx;

void increment_with_data_racing()
{
  for (int i = 0; i < 1000000; ++i)
  {
    number_with_data_racing++;
  }
}

void increment_without_data_racing()
{
  mtx.lock();
  for (int i = 0; i < 1000000; ++i)
  {
    number_without_data_racing++;
  }
  mtx.unlock();
}

int main()
{
  std::thread t1(increment_with_data_racing);
  std::thread t2(increment_with_data_racing);

  std::thread t3(increment_without_data_racing);
  std::thread t4(increment_without_data_racing);

  t1.join();
  t2.join();
  t3.join();
  t4.join();

  std::cout << "Number with data racing: " << number_with_data_racing << std::endl;
  std::cout << "Number without data racing: " << number_without_data_racing << std::endl;

  return 0;
}
