#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include "Account.h"
#include <vector>

// Utility helper functions for Account class

void display(const std::vector<const Account *> &accounts);
void deposit(const std::vector<Account *> &accounts, double amount);
void withdraw(const std::vector<Account *> &accounts, double amount);

#endif
