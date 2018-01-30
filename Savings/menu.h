#ifndef MENU_H
#define MENU_H

#include "portfolioInvestment.cpp"

class Menu{

private:
    PortfolioInvestment<Asset*>* portfolioInvestment;

public:
    void setPortfolioInvestment(PortfolioInvestment<Asset*>* wallet);
    void mainMenu();
    void displayOptions();
    void editMenu();
    void addMenu();
    void deleteMenu();
    void addBankDeposit();
    void addRealEstate();
    void addInvestmentFundUnits();
    void addContract();
    void addIKE();
    void infoMenu();

};


#endif
