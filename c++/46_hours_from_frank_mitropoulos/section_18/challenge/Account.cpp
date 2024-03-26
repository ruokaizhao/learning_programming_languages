#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

Account::Account(std::string name, double balance) : name{name}, balance{balance}
{
  if (balance < 0.00)
  {
    throw IllegalBalanceException{};
  }
}

bool Account::deposit(double amount)
{
  if (amount < 0.00)
    return false;
  else
  {
    balance += amount;
    return true;
  }
}

bool Account::withdraw(double amount)
{
  if (balance - amount >= 0.00)
  {
    balance -= amount;
    return true;
  }
  throw InsufficientFundsException{};
}

double Account::get_balance() const
{
  return balance;
}
