#include "asset.h"
#include "NegativeValueException.hpp"



string Asset::getName(){
    return name;
}

double Asset::getValue(){
    return value;
}

void Asset::setName(string name){
    this->name = name;
}

void Asset::setValue(double value){
    this->value = value;
}

void Asset::operator+=(double value){
    this->value = this->value + value;
}

void Asset::operator-=(double value){
    if(this->value < value) throw NegativeValueException();
    else{
        this->value = this->value - value;
    }

}

void Asset::edit(){

}

