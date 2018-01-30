#ifndef __REALESTATE_H_INCLUDED__
#define __REALESTATE_H_INCLUDED__

#include <string>
#include "asset.h"


using namespace std;

class RealEstate : public Asset {
 private:
    double area;
    string address;
 public:
    string getAddress();
    void setAddress(string name);
    double getArea();
    void setArea(double area);
    void edit();
    void showInfo();
    string getType();
    double simulate(int);

};
#endif // __ASSET_H_INCLUDED__
