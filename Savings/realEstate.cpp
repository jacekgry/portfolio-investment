#include "realEstate.hpp"
#include "NegativeValueException.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
string RealEstate::getType(){return "realEstate";}


void RealEstate::setAddress(string address){
    this->address = address;
}

string RealEstate::getAddress(){
    return this->address;
}

double RealEstate::getArea(){
    return this->area;

}
void RealEstate::setArea(double area){
    this->area = area;

}



void RealEstate::edit(){
    string name;
    double value;
    string address;
    double area;

    cout<<"Aktualna nazwa nieruchomosci: "<<this->getName()<<endl;
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


    cout<<"Aktualny adres: " << this->getAddress()<<endl;
    cout<<"Podaj nowy adres: ";
    std::cin.ignore( 1024, '\n' );
    std::getline(std::cin, address);
    this->setAddress(address);

    cout<<"Aktualna powierzchnia: "<<this->getArea()<<"m2"<<endl;
    cout<<"Podaj nowa powierzchnie: ";
    cin>>area;
    this->setArea(area);

}


void RealEstate::showInfo(){
    cout<<"Nieruchomosc"<<endl;
    cout<<"Nazwa nieruchomosci: "<<this->getName()<<endl;
    cout<<"Wartosc: "<<this->getValue()<<"PLN"<<endl;
    cout<<"Adres: " << this->getAddress()<<endl;
    cout<<"Powierzchnia: "<<this->getArea()<<"m2"<<endl;
    system("pause");
}

double RealEstate::simulate(int years){
    srand(time(NULL));
    double x = ((double)(rand() % 100) - 20) / 100;
    return getValue()*(1+x);
}

