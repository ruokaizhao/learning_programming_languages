#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, withdraw_times{0}
{
}

bool Trust_Account::deposit(double amount)
{
  if (!Savings_Account::deposit(amount))
  {
    return false;
  }
  if (amount >= def_bonus_threshold)
  {
    if (!Account::deposit(def_bonus))
    {
      return false;
    }
  }
  return true;
}

bool Trust_Account::withdraw(double amount)
{
  if (withdraw_times + 1 > def_withdraw_annual_limit)
  {
    std::cout << "You have reached your annual limit of 3 withdraws." << std::endl;
    return false;
  }
  if (amount > balance * def_withdraw_percentage_limit)
  {
    std::cout << "You cannot withdraw more than 20% of your current balance." << std::endl;
    return false;
  }

  if (Savings_Account::withdraw(amount))
  {
    withdraw_times++;
    return true;
  }
  return false;
}

double Trust_Account::get_balance() const
{
  return Account::get_balance();
}

void Trust_Account::print(std::ostream &os) const
{
  os << "[Trust_Account: " << this->name << ": " << this->balance << ", " << this->int_rate << "%"
     << ", "
     << "Withdraw times: " << this->withdraw_times << "]";
}

Trust_Account &Trust_Account::operator+=(double amount)
{
  if (deposit(amount))
  {
    std::cout << "Deposited " << amount << " to " << *this << std::endl;
  }
  else
  {
    std::cout << "Failed Deposit of " << amount << " to " << *this << std::endl;
  }
  return *this;
}

Trust_Account &Trust_Account::operator-=(double amount)
{
  if (withdraw(amount))
  {
    std::cout << "Withdrew " << amount << " from " << *this << std::endl;
  }
  else
  {
    std::cout << "Failed Withdrawal of " << amount << " from " << *this << std::endl;
  }
  return *this;
}
