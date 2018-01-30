#ifndef UNITS_H
#define UNITS_H

#include "Asset.h"

class UnitsOfInvestmentFund : public Asset{

private:
    bool withDividend;
    double dividend;
public:
    bool isWithDividend();
    void setWithDividend(bool);
    double getDividend();
    void setDividend(double);
    void edit();
    void showInfo();
    string getType();
    double simulate(int);

};

#endif
