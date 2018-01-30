#include "IKE.hpp"
#include <iostream>
#include <stdlib.h>
#include "NegativeValueException.hpp"

string IKE::getType(){return "IKE";}

double IKE::getAnnualPayment(){
    return this->annualPayment;
}

double IKE::getInterest(){
    return this->interest;
};

void IKE::setAnnualPayment(double annualPayment){
    this->annualPayment = annualPayment;
}

void IKE::setInterest(double interest){
    this->interest = interest;
}

void IKE::edit(){

    double value;
    double interest;
    string name;
    double annualPayment;

    cout<<"Aktualna nazwa konta: "<<getName()<<endl;
    cout<<"Nowa nazwa konta: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, name);
    this->setName(name);

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


    cout<<"Aktualna roczna wplata: "<<getAnnualPayment()<<"PLN"<<endl;
    cout<<"Nowa roczna wplata(PLN): ";
    cin>>annualPayment;
    this->setAnnualPayment(annualPayment);


    cout<<"Aktualne procentowanie: "<<getInterest()<<"%"<<endl;
    cout<<"Nowe oprocentowanie(%): ";
    cin>>interest;
    this->setInterest(interest);
}

void IKE::showInfo(){
    cout<<"Indywidualne konto emerytalne"<<endl;
    cout<<"Nazwa konta: "<<getName()<<endl;
    cout<<"Wartosc: "<<getValue()<<"PLN"<<endl;
    cout<<"Roczna wplata: "<<getAnnualPayment()<<"PLN"<<endl;
    cout<<"Oprocentowanie: "<<getInterest()<<"%"<<endl;
    system("pause");
}

double IKE::simulate(int years){
    if(years == 0) return getValue();
    else{
        return (simulate(years-1)+getAnnualPayment())*(1 + getInterest()/100);
    }
}
