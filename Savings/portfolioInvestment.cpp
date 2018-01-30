#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "asset.h"
#include "BankDeposit.hpp"
#include "realEstate.hpp"
#include "UnitsOfInvestmentFund.hpp"
#include "IKE.hpp"
#include "contract.hpp"


using namespace std;
template <class T> class PortfolioInvestment{

private:
    vector<T> assets;

public:

    int getNumberOfAssets(){return assets.size();}

    void addAsset(T asset){
        assets.push_back(asset);
        save();
    }


    void removeAsset(int idx){
        if(idx > getNumberOfAssets() - 1 || idx < 0){
            cout<<"Nie ma aktywa o tym numerze!"<<endl;
            system("pause");
            return;
        }
        assets.erase(assets.begin() + idx);
        save();
    }


    void displayAssets(){
        cout<<"Laczna wartosc aktyw: "<<getTotalValue()<<"zl"<<endl;
        for(int i = 0; i < getNumberOfAssets(); i++){
            cout<<i + 1<<"."<<assets[i]->getName()<<endl;
        }
    }


    void editAsset(int idx){
        if(idx > (getNumberOfAssets() - 1) || idx < 0){
            cout<<"Nie ma aktywa o tym numerze!"<<endl;
            system("pause");
            return;
        }
        assets[idx]->edit();
        save();
    }

    double getTotalValue(){
        double value = 0;
        for(int i = 0; i < getNumberOfAssets(); i++){
            value += assets[i]->getValue();
        }
        return value;
    }

    void showInfo(int idx){
        if(idx > (getNumberOfAssets() - 1) || idx < 0){
            cout<<"Nie ma aktywa o tym numerze!"<<endl;
            system("pause");
            return;
        }
        else{
            assets[idx]->showInfo();
        }
    }



    void load(){

        ifstream save;
        string line;
        save.open ("save.txt", ios::out);
        if (save.is_open()){
            while ( getline (save,line) )
            {
                if(line.compare("bankDeposit") == 0){
                    BankDeposit* bankDeposit = new BankDeposit();;

                    getline (save,line);
                    bankDeposit->setName(line);

                    getline (save,line);
                    bankDeposit->setValue(stod(line));

                    getline(save, line);
                    bankDeposit->setBank(line);

                    getline(save, line);
                    bankDeposit->setInterest(stod(line));

                    addAsset(bankDeposit);
                }
                else if(line.compare("contract") == 0){
                    Contract* contract = new Contract();

                    getline(save, line);
                    contract->setName(line);

                    getline(save, line);
                    contract->setValue(stod(line));

                    getline(save, line);
                    contract->setMultiplier(stod(line));

                    addAsset(contract);
                }
                else if(line.compare("IKE") == 0){
                    IKE* ike = new IKE();

                    getline(save, line);
                    ike->setName(line);

                    getline(save, line);
                    ike->setValue(stod(line));

                    getline(save, line);
                    ike->setAnnualPayment(stod(line));

                    getline(save, line);
                    ike->setInterest(stod(line));

                    addAsset(ike);
                }

                else if(line.compare("realEstate") == 0){
                    RealEstate* realEstate = new RealEstate();

                    getline(save, line);
                    realEstate->setName(line);

                    getline(save, line);
                    realEstate->setValue(stod(line));

                    getline(save, line);
                    realEstate->setArea(stod(line));

                    getline(save, line);
                    realEstate->setAddress(line);

                    addAsset(realEstate);
                }

                else if(line.compare("units") == 0){
                    UnitsOfInvestmentFund* units = new UnitsOfInvestmentFund();

                    getline(save, line);
                    units->setName(line);

                    getline(save, line);
                    units->setValue(stod(line));

                    getline(save, line);
                    if(line.compare("1") == 0){
                        units->setWithDividend(true);
                        getline(save, line);
                        units->setDividend(stod(line));
                    }
                    else {
                        units->setWithDividend(false);
                        getline(save, line);
                    }

                    addAsset(units);
                }


            }
            save.close();
          }
    }



    void save(){

        ofstream save;
        save.open ("save.txt", ios::in | ios::trunc);


        if (save.is_open()){
            for(int i = 0; i < getNumberOfAssets(); i++){
                string type = assets[i]->getType();
                save<<type<<endl;
                save<<assets[i]->getName()<<endl;
                save<<std::fixed<<std::setprecision(2)<<assets[i]->getValue()<<endl;
                if(type.compare("bankDeposit")==0){
                    BankDeposit* bankDeposit = (BankDeposit*)assets[i];
                    save<<bankDeposit->getBank()<<endl;
                    save<<std::fixed<<std::setprecision(2)<<bankDeposit->getInterest()<<endl;
                }
                else if(type.compare("contract")==0){
                    Contract* contract = (Contract*)assets[i];
                    save<<std::fixed<<std::setprecision(2)<<contract->getMultiplier()<<endl;
                }
                else if(type.compare("IKE")==0){
                    IKE* ike = (IKE*)assets[i];
                    save<<std::fixed<<std::setprecision(2)<<ike->getAnnualPayment()<<endl;
                    save<<std::fixed<<std::setprecision(2)<<ike->getInterest()<<endl;
                }
                else if(type.compare("realEstate")==0){
                    RealEstate* realEstate = (RealEstate*)assets[i];
                    save<<std::fixed<<std::setprecision(2)<<realEstate->getArea()<<endl;
                    save<<realEstate->getAddress()<<endl;

                }
                else if(type.compare("units")==0){
                    UnitsOfInvestmentFund* units = (UnitsOfInvestmentFund*)assets[i];
                    save<<units->isWithDividend()<<endl;
                    save<<std::fixed<<std::setprecision(2)<<units->getDividend()<<endl;
                }
            }
            save.close();
        }
    }

    void simulate(int years){
        system("cls");
        double total = 0;
        double value;
        for(int i = 0; i < getNumberOfAssets(); i++){
            value = assets[i]->simulate(years);
            total+=value;
            cout<<"Wartosc "<<assets[i]->getName()<<" za "<<years<<" lat bedzie wynosila "<<fixed<<setprecision(2)<<value<<"PLN"<<endl;
        }
        cout<<endl<<"Laczna wartosc portfela za "<<years<<" lat: "<<total<<"PLN"<<endl;

        system("pause");

    }


};

#endif // PORTFOLIO_H



