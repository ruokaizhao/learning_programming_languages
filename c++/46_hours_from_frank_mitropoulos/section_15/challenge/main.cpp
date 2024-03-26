// Section 15
// Challenge
#include "Account.cpp"
#include "Account_Util.cpp"
#include "Checking_Account.cpp"
#include "Savings_Account.cpp"
#include "Trust_Account.cpp"
#include "Trust_Account.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout.precision(2);
  cout << fixed;

  // Accounts
  vector<Account> accounts;
  accounts.push_back(Account{});
  accounts.push_back(Account{"Larry"});
  accounts.push_back(Account{"Moe", 2000});
  accounts.push_back(Account{"Curly", 5000});

  display(accounts);
  deposit(accounts, 1000);
  withdraw(accounts, 2000);

  // Savings

  vector<Savings_Account> savings_accounts;
  savings_accounts.push_back(Savings_Account{});
  savings_accounts.push_back(Savings_Account{"Superman"});
  savings_accounts.push_back(Savings_Account{"Batman", 2000});
  savings_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

  display(savings_accounts);
  deposit(savings_accounts, 1000);
  withdraw(savings_accounts, 2000);

  // Checking

  vector<Checking_Account> checking_accounts;
  checking_accounts.push_back(Checking_Account{});
  checking_accounts.push_back(Checking_Account{"Superman"});
  checking_accounts.push_back(Checking_Account{"Batman", 2000});
  checking_accounts.push_back(Checking_Account{"Wonderwoman", 5000});

  display(checking_accounts);
  deposit(checking_accounts, 1000);
  withdraw(checking_accounts, 2000);

  // Trust

  vector<Trust_Account> trust_accounts;
  trust_accounts.push_back(Trust_Account{});
  trust_accounts.push_back(Trust_Account{"Superman"});
  trust_accounts.push_back(Trust_Account{"Batman", 2000});
  trust_accounts.push_back(Trust_Account{"Wonderwoman", 5000, 5.0});

  display(trust_accounts);
  deposit(trust_accounts, 1000);
  withdraw(trust_accounts, 1000);
  deposit(trust_accounts, 5000);
  withdraw(trust_accounts, 1000);
  withdraw(trust_accounts, 1010);
  withdraw(trust_accounts, 1000);

  Trust_Account trust_account = Trust_Account{"Wonderwoman", 5000, 5.0};

  trust_account += 1000;
  trust_account -= 1000;
  trust_account -= 1010;
  trust_account -= 1000;
  trust_account -= 100;
  trust_account -= 100;

  return 0;
}
