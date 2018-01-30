#ifndef IKE_H
#define IKE_H

#include "Asset.h"

class IKE : public Asset{

private:
    double annualPayment;
    double interest;
public:
    double getAnnualPayment();
    double getInterest();
    void setAnnualPayment(double);
    void setInterest(double);
    void edit();
    void showInfo();
    string getType();
    double simulate(int);

};


#endif
