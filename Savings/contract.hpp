#ifndef CONTRACT_H
#define CONTRACT_H

#include "asset.h"


class Contract : public Asset{
private:
    double multiplier;
public:
    double getMultiplier();
    void setMultiplier(double);
    void edit();
    void showInfo();
    string getType();
    double simulate(int);

};


#endif // CONTRACT_H
