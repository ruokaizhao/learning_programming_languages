// Simple Account
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "I_Printable.h"
#include <iostream>
#include <string>

class Account : public I_Printable
{
  private:
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;

  protected:
  std::string name;
  double balance;

  public:
  Account(std::string name_val = def_name, double balance_val = def_balance);
  virtual bool deposit(double amount) = 0;
  virtual bool withdraw(double amount) = 0;
  virtual double get_balance() const = 0;
  virtual ~Account() = default;
};
#endif
