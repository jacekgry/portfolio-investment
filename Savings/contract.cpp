#include "contract.hpp"
#include "NegativeValueException.hpp"
#include <iostream>
#include <stdlib.h>


string Contract::getType(){return "contract";}


double Contract::getMultiplier(){
    return this->multiplier;
}
void Contract::setMultiplier(double multiplier){
    this->multiplier = multiplier;
}
void Contract::edit(){

    double value;
    double multiplier;
    string name;

    cout<<"Aktualna nazwa: "<<this->getName()<<endl;
    cout<<"Nowa nazwa: ";
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

    cout<<"Aktualny mnoznik: "<<this->getMultiplier()<<endl;
    cout<<"Nowy noznik: ";
    cin>>multiplier;
    this->setMultiplier(multiplier);



}
void Contract::showInfo(){
    cout<<"Kontrakt"<<endl;
    cout<<"Nazwa: "<<this->getName()<<endl;
    cout<<"Wartosc: "<<this->getValue()<<"PLN"<<endl;
    cout<<"Mnoznik: "<<this->getMultiplier()<<endl;
    system("pause");
}

double Contract::simulate(int years){
    return getValue();

}
