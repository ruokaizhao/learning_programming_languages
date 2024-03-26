// Section 18
// Challenge
#include "Account.cpp"
#include "Checking_Account.cpp"
#include "I_Printable.cpp"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"
#include "Savings_Account.cpp"
#include "Trust_Account.cpp"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
  cout.precision(2);
  cout << fixed;

  std::unique_ptr<Account> savings_ptr = std::make_unique<Savings_Account>("Superman", 1000.00, 5);
  Checking_Account checking{"Batman", 1000.00};

  try
  {
    std::unique_ptr<Account> trust_ptr = std::make_unique<Trust_Account>("Superman", -1000.00, 5);
    std::cout << *trust_ptr << std::endl;
  }
  catch (IllegalBalanceException &ex)
  {
    std::cout << ex.what() << std::endl;
  }
  catch (InsufficientFundsException &ex)
  {
    std::cout << ex.what() << std::endl;
  }

  try
  {
    savings_ptr->withdraw(2000.00);
    std::cout << *savings_ptr << std::endl;
  }
  catch (IllegalBalanceException &ex)
  {
    std::cout << ex.what() << std::endl;
  }
  catch (InsufficientFundsException &ex)
  {
    std::cout << ex.what() << std::endl;
  }

  try
  {
    checking.withdraw(2000.00);
    std::cout << checking << std::endl;
  }
  catch (IllegalBalanceException &ex)
  {
    std::cout << ex.what() << std::endl;
  }
  catch (InsufficientFundsException &ex)
  {
    std::cout << ex.what() << std::endl;
  }

  std::cout << "Completed normally" << std::endl;

  return 0;
}
