#include "BankDeposit.hpp"
#include "asset.h"
#include "NegativeValueException.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;


string BankDeposit::getType(){return "bankDeposit";}


string BankDeposit::getBank(){
    return this->bank;
}

void BankDeposit::setBank(string bankName) {
    this->bank = bankName;
}

double BankDeposit::getInterest(){
    return this->interest;
}

void BankDeposit::setInterest(double interest){
    this->interest = interest;
}

void BankDeposit::showInfo(){
    cout<<"Lokata"<<endl;
    cout<<"Nazwa lokaty: "<<this->getName()<<endl;
    cout<<"Bank: " << this->getBank()<<endl;
    cout<<"Wartosc: "<<this->getValue()<<"PLN"<<endl;
    cout<<"Oprocentowanie: "<<this->getInterest()<<"%"<<endl;
    system("pause");
}

void BankDeposit::edit(){
    double value;
    double interest;
    string name;
    string bank;

    cout<<"Aktualna nazwa lokaty: "<<this->getName()<<endl;
    cout<<"Nowa nazwa lokaty: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);
    this->setName(name);

    cout<<"Aktualny bank: " << this->getBank()<<endl;
    cout<<"Nowy bank: ";
    std::getline(std::cin, bank);
    this->setBank(bank);

    cout<<"Aktualna wartosc: "<<this->getValue()<<"PLN"<<endl;
    cout<<"Zwieksz wartosc o: ";
    cin>>value;
    *this+=value;

    cout<<"Aktualna wartosc: "<<this->getValue()<<"PLN"<<endl;
    cout<<"Zmniejsz wartosc o: ";
    cin>>value;
    try{
        *this-=value;
    }
    catch(NegativeValueException& e){
        cout<<"Wartosc nie moze byc ujemna!"<<endl;
    }


    cout<<"Aktualne oprocentowanie: "<<this->getInterest()<<endl;
    cout<<"Nowe oprocentowanie: ";
    cin>>interest;
    this->setInterest(interest);
}

double BankDeposit::simulate(int years){
    return getValue()*pow((1+getInterest()/100), years);

}
