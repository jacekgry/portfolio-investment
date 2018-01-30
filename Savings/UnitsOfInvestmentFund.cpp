#include "UnitsOfInvestmentFund.hpp"
#include "NegativeValueException.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>

string UnitsOfInvestmentFund::getType(){return "units";}

bool UnitsOfInvestmentFund::isWithDividend(){
    return this->withDividend;
}
void UnitsOfInvestmentFund::setWithDividend(bool withDividend){
    this->withDividend = withDividend;
}
double UnitsOfInvestmentFund::getDividend(){
    if(!isWithDividend()) return 0;
    return this->dividend;
}
void UnitsOfInvestmentFund::setDividend(double dividend){
    this->dividend = dividend;
}


void UnitsOfInvestmentFund::edit(){

    string name;
    double value;
    string withDividend;
    double dividend;

    cout<<"Aktualna nazwa funduszu: "<<this->getName()<<endl;
    cout<<"Podaj nowa nazwe: ";
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


    cout<<"Aktualna dywidenda: ";
    if(isWithDividend()) {
        cout<<"TAK - ";
        cout<<dividend<<"PLN"<<endl;
    }
    else cout<<"NIE"<<endl;


    while(!withDividend.compare("T")==0 && !withDividend.compare("N")==0){
        cout<<"Czy jest dywidenda? (T/N) : ";
        cin>>withDividend;
    }

    if(withDividend.compare("T")==0){
        cout<<"Podaj dywidende: ";
        cin>>dividend;
    }

    if(withDividend.compare("T") == 0){
        this->setWithDividend(true);
        this->setDividend(dividend);
    }

    else{
        this->setWithDividend(false);
    }


}

void UnitsOfInvestmentFund::showInfo(){
    cout<<"Jednostki uczestnictwa w funduszu inwestycyjnym"<<endl;
    cout<<"Nazwa funduszu: "<<getName()<<endl;
    cout<<"Wartosc: "<<getValue()<<"PLN"<<endl;
    cout<<"Dywidenda: ";
    if(withDividend) {
        cout<<"TAK - ";
        cout<<dividend<<"PLN"<<endl;
    }
    else cout<<"NIE"<<endl;
    system("pause");
}

double UnitsOfInvestmentFund::simulate(int years){
    srand(time(NULL));
    double x = (rand() % 40 - 20) / 100;
    return getValue()*(1+x) + years * getDividend();

}
