#include "PhysicalNumber.h"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;

PhysicalNumber::PhysicalNumber(double value, Unit U){
}

PhysicalNumber::~PhysicalNumber(){
    
}


//const PhysicalNumber a(2, this->u);
//PhysicalNumber b(2, this->u);
const PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& Pn) const{
    return  PhysicalNumber (2, this->u);
}
const PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& Pn) const{
    return  PhysicalNumber (2, this->u);
}

PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& Pn){
   return *this;
}

PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& Pn){
     return *this;
}
PhysicalNumber& PhysicalNumber::operator= (const PhysicalNumber& Pn){
    return *this;
}

//פעולות אונריות
const PhysicalNumber PhysicalNumber::operator+ () const{
    return  PhysicalNumber (2, this->u);
}
const PhysicalNumber PhysicalNumber::operator- () const{
      return PhysicalNumber (2, this->u);
}

//true or fulse operators
const bool PhysicalNumber::operator== (const PhysicalNumber& Pn) const{
    return true;
}
const bool PhysicalNumber::operator> (const PhysicalNumber& Pn) const{
     return true;
}
const bool PhysicalNumber::operator< (const PhysicalNumber& Pn) const{
     return true;
}
const bool PhysicalNumber::operator<= (const PhysicalNumber& Pn) const{
     return true;
}
const bool PhysicalNumber::operator>= (const PhysicalNumber& Pn) const{
     return true;
}
const bool PhysicalNumber::operator!= (const PhysicalNumber& Pn) const{
     return true;
}

//prefix
PhysicalNumber& PhysicalNumber::operator++ (){
    return *this;
}
PhysicalNumber& PhysicalNumber::operator-- (){
      return *this;
}

//friends functions
 ostream& ariel::operator<< (ostream& os, const PhysicalNumber& Pn){
    return os;
}
 istream& ariel::operator>> (istream& is, PhysicalNumber& Pn){
    return is;
}