#ifndef __ASSET_H_INCLUDED__
#define __ASSET_H_INCLUDED__

#include <string>
#include <math.h>
using namespace std;

class Asset{
 private:
    string name;
    double value;
 public:
    Asset():value(0){}
    virtual string getType() = 0;
    string getName();
    void setName(string name);
    double getValue();
    void setValue(double value);
    void operator+=(double value);
    void operator-=(double value);
    virtual void showInfo() = 0;
    virtual void edit()=0;
    virtual double simulate(int)=0;

};
#endif // __ASSET_H_INCLUDED__
