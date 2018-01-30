#ifndef BANK_DEPOSIT_H
#define BANK_DEPOSIT_H

#include "asset.h"

class BankDeposit : public Asset{

private:
    string bank;
    double interest;
public:
    string getBank();
    void setBank(string bank);
    double getInterest();
    void setInterest(double interest);
    void showInfo();
    void edit();
    string getType();
    double simulate(int);

};

#endif
