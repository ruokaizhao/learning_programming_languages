#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance) : Account{name, balance}
{
}

bool Checking_Account::deposit(double amount)
{
  return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount)
{
  amount += def_fee;
  return Account::withdraw(amount);
}

double Checking_Account::get_balance() const
{
  return Account::get_balance();
}

void Checking_Account::print(std::ostream &os) const
{
  os << "[Checking_Account: " << name << ": " << balance;
}
