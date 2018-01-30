#include <iostream>
#include "portfolioInvestment.cpp"
#include "menu.h"
using namespace std;



int main()
{

    PortfolioInvestment<Asset*>* portfolioInvestment = new PortfolioInvestment<Asset*>();
    portfolioInvestment->load();
    Menu menu;
    menu.setPortfolioInvestment(portfolioInvestment);

    menu.mainMenu();

    return 0;
}
