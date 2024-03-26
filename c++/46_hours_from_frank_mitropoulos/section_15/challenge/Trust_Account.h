#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
  friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

  private:
  static constexpr const char *def_name = "Unnamed Trust Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_int_rate = 0.0;
  static constexpr double def_bonus_threshold = 5000.00;
  static constexpr double def_bonus = 50.0;
  static constexpr int def_withdraw_annual_limit = 3;
  static constexpr double def_withdraw_percentage_limit = 0.2;

  protected:
  int withdraw_times;

  public:
  Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
  bool deposit(double amount);
  bool withdraw(double amount);
  Trust_Account &operator+=(double amount);
  Trust_Account &operator-=(double amount);
};

#endif
