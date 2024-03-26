// Section 16
// Challenge
#include "Account.cpp"
#include "Account_Util.cpp"
#include "Checking_Account.cpp"
#include "Savings_Account.cpp"
#include "Trust_Account.cpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout.precision(2);
  cout << fixed;

  // Savings
  Account *savings1 = new Savings_Account{};
  Account *savings2 = new Savings_Account{"Superman"};
  Account *savings3 = new Savings_Account{"Batman", 2000};
  Account *savings4 = new Savings_Account{"Wonderwoman", 5000, 5.0};
  vector<Account *> savings_accounts{savings1, savings2, savings3, savings4};

  display(savings_accounts);
  deposit(savings_accounts, 1000);
  withdraw(savings_accounts, 2000);

  // Checking

  Account *checking1 = new Checking_Account{};
  Account *checking2 = new Checking_Account{"Superman"};
  Account *checking3 = new Checking_Account{"Batman", 2000};
  Account *checking4 = new Checking_Account{"Wonderwoman", 5000};
  vector<Account *> checking_accounts{checking1, checking2, checking3, checking4};

  display(checking_accounts);
  deposit(checking_accounts, 1000);
  withdraw(checking_accounts, 2000);

  // Trust

  Account *trust1 = new Trust_Account{};
  Account *trust2 = new Trust_Account{"Superman"};
  Account *trust3 = new Trust_Account{"Batman", 2000};
  Account *trust4 = new Trust_Account{"Wonderwoman", 5000, 5.0};
  vector<Account *> trust_accounts{trust1, trust2, trust3, trust4};

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

  delete savings1;
  delete savings2;
  delete savings3;
  delete savings4;
  delete checking1;
  delete checking2;
  delete checking3;
  delete checking4;
  delete trust1;
  delete trust2;
  delete trust3;
  delete trust4;

  return 0;
}
