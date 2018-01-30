#include "menu.h"
#include "BankDeposit.hpp"
#include "realEstate.hpp"
#include "UnitsOfInvestmentFund.hpp"
#include "IKE.hpp"
#include "contract.hpp"

#include <string>
#include <stdlib.h>

using namespace std;

void Menu::setPortfolioInvestment(PortfolioInvestment<Asset*>* wallet){
    this->portfolioInvestment = wallet;

}

void Menu::mainMenu(){
    system("cls");
    bool volatile exit =false;
    while(!exit){
        string option;
        bool properOptionChosen = false;
        displayOptions();
        while(!properOptionChosen){
            cout<<"Wybieram opcje nr: ";\
            cin.clear();
            cin>>option;

            if(option.compare("1") == 0){
                cout<<"Wyswietlam"<<endl;
                properOptionChosen = true;
                infoMenu();

            }
            else if(option.compare("2") == 0){
                properOptionChosen = true;
                addMenu();

            }
            else if(option.compare("3") == 0){
                properOptionChosen = true;
                deleteMenu();
            }
            else if(option.compare("4") == 0){
                properOptionChosen = true;
                editMenu();

            }
            else if(option.compare("5") == 0){
                properOptionChosen = true;
                system("cls");
                int period;
                cout<<"Okres w latach: ";
                cin>>period;
                portfolioInvestment->simulate(period);
            }
            else if(option.compare("6") == 0){
                properOptionChosen = true;
                exit = true;
            }
            else{
                cout<<"Nie ma takiej opcji!"<<endl;
            }
        }
    }
}

void Menu::displayOptions(){
    system("cls");
    cout<<"1. Wyswietl zawartosc portfela."<<endl;
    cout<<"2. Dodaj aktywo."<<endl;
    cout<<"3. Usun aktywo."<<endl;
    cout<<"4. Edytuj aktywo."<<endl;
    cout<<"5. Symulacja."<<endl;
    cout<<"6. Wyjdz z programu."<<endl;
}

void Menu::addMenu(){

    system("cls");

    string option;

    cout<<"1. Lokata bankowa"<<endl;
    cout<<"2. Nieruchomosc."<<endl;
    cout<<"3. Jednostki funduszu inwestycyjnego."<<endl;
    cout<<"4. Kontrakt."<<endl;
    cout<<"5. Indywidualne konto emerytalne."<<endl;
    cout<<"6. Wroc do glownego menu."<<endl;

    cout<<"Wybieram opcje nr: ";
    cin.clear();
    cin>>option;

    if(option.compare("1") == 0) addBankDeposit();
    else if(option.compare("2") == 0) addRealEstate();
    else if(option.compare("3") == 0) addInvestmentFundUnits();
    else if(option.compare("4") == 0) addContract();
    else if(option.compare("5") == 0) addIKE();
    else if(option.compare("6") == 0) mainMenu();
    else{
        cout<<"Nie ma takiej opcji!"<<endl;
        addMenu();
    }

}

void Menu::deleteMenu(){


    system("cls");

    int idx;
    portfolioInvestment->displayAssets();
    cout<<endl;
    cout<<portfolioInvestment->getNumberOfAssets() + 1<<". Wroc do menu glownego"<<endl;

    cout<<"Ktore aktywo usunac?"<<endl;
    cout<<"Chce usunac aktywo nr: ";
    cin>>idx;

    if(idx == portfolioInvestment->getNumberOfAssets() + 1){
        mainMenu();
    }
    else{
        system("cls");
        portfolioInvestment->removeAsset(idx - 1);
    }


}

void Menu::infoMenu(){
    system("cls");
    int idx;
    portfolioInvestment->displayAssets();
    cout<<endl;
    cout<<portfolioInvestment->getNumberOfAssets() + 1<<". Wroc do menu glownego"<<endl;
    cout<<"Wiecej informacji o aktywie nr: ";
    cin>>idx;
    if(idx == (portfolioInvestment->getNumberOfAssets() + 1)){
        mainMenu();
    }
    else{
        system("cls");
        portfolioInvestment->showInfo(idx - 1);
    }
}

void Menu::editMenu(){

    system("cls");

    int idx;


    cout<<"Ktore aktywo chcesz edytowac?"<<endl;
    cout<<endl;

    portfolioInvestment->displayAssets();
    cout<<endl;
    cout<<portfolioInvestment->getNumberOfAssets() + 1<<". Wroc do menu glownego"<<endl;

    cout<<"Chce edytowac aktywo nr: ";
    cin>>idx;

    if(idx == portfolioInvestment->getNumberOfAssets() + 1){
        mainMenu();
    }
    else{
        system("cls");
        portfolioInvestment->editAsset(idx-1);
    }
}


void Menu::addBankDeposit(){

    system("cls");

    BankDeposit* bankDeposit = new BankDeposit();

    double value;
    double interest;
    string name;
    string bank;

    string line;

    cout<<"Nazwa lokaty: ";
    std::cin.ignore( 1024, '\n' ) ;
    std::getline(std::cin, name);

    cout<<"Bank: ";
    std::getline(std::cin, bank);

    cout<<"Wartosc: ";
    cin >> value;

    cout<<"Oprocentowanie: ";
    cin>>interest;


    bankDeposit->setName(name);
    bankDeposit->setValue(value);
    bankDeposit->setInterest(interest);
    bankDeposit->setBank(bank);

    (this->portfolioInvestment)->addAsset(bankDeposit);

}

void Menu::addRealEstate(){

    system("cls");

    RealEstate* realEstate = new RealEstate();

    string name;
    double value;
    string address;
    double area;

    cout<<"Podaj nazwe: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);

    cout<<"Podaj wartosc: ";
    cin>>value;

    cout<<"Podaj adres: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, address);

    cout<<"Podaj powierzchnie: ";
    cin>>area;

    realEstate->setName(name);
    *realEstate+=value;
    realEstate->setAddress(address);
    realEstate->setArea(area);

    portfolioInvestment->addAsset(realEstate);

}

void Menu::addInvestmentFundUnits(){

    system("cls");

    UnitsOfInvestmentFund* unitsOfInvestmentFund = new UnitsOfInvestmentFund();

    string name;
    double value;
    double dividend;
    string withDividend;

    cout<<"Podaj nazwe: ";

    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);

    cout<<"Podaj wartosc: ";
    cin>>value;

    while(!withDividend.compare("T")==0 && !withDividend.compare("N")==0){
        cout<<"Czy jest dywidenda? (T/N) : ";
        cin>>withDividend;
    }

    if(withDividend.compare("T")==0){
        cout<<"Podaj dywidende: ";
        cin>>dividend;
    }

    unitsOfInvestmentFund->setName(name);
    *unitsOfInvestmentFund+=value;
    if(withDividend.compare("T") == 0){
        unitsOfInvestmentFund->setWithDividend(true);
        unitsOfInvestmentFund->setDividend(dividend);
    }
    else{
        unitsOfInvestmentFund->setDividend(false);
    }

    portfolioInvestment->addAsset(unitsOfInvestmentFund);


}

void Menu::addContract(){


    system("cls");

    Contract* contract = new Contract();

    double value;
    double multiplier;
    string name;

    cout<<"Nazwa: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);

    cout<<"Wartosc: ";
    cin>>value;

    cout<<"Mnoznik: ";
    cin>>multiplier;

    contract->setName(name);
    contract->setValue(value);
    contract->setMultiplier(multiplier);

    (this->portfolioInvestment)->addAsset(contract);


}
void Menu::addIKE(){

    system("cls");

    IKE* ike = new IKE();

    double value;
    double interest;
    string name;
    double annualPayment;

    cout<<"Nazwa konta: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);

    cout<<"Wartosc: ";
    cin>>value;

    cout<<"Oprocentowanie: ";
    cin>>interest;

    cout<<"Roczna wplata: ";
    cin>>annualPayment;


    ike->setName(name);
    ike->setValue(value);
    ike->setInterest(interest);
    ike->setAnnualPayment(annualPayment);

    (this->portfolioInvestment)->addAsset(ike);
}
