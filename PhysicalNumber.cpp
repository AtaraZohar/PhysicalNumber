#include "PhysicalNumber.h"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;


PhysicalNumber::PhysicalNumber(double value, Unit u){//the constructor unction
 this->value=value;
 this->u=u;
}

PhysicalNumber::~PhysicalNumber(){//distructor
    
}

//help function
const bool  PhysicalNumber::ifMatch(const Unit u1,const Unit u2) const{//this function check if two physical numbers is from the same sub unit so we can so some operators on them.
    if (u1 == Unit::KM || u1 == Unit::CM || u1 == Unit::M){//the sub unit distance
        if (u2 == Unit::KM || u2 == Unit::CM || u2== Unit::M){
            return true;
        }
    }
    if (u1 == Unit::TON || u1 == Unit::KG || u1== Unit::G){//the sub unit weigth
        if (u2 == Unit::TON || u2 == Unit::KG || u2== Unit::G){
            return true;
        }
    }
     if (u1 == Unit::HOUR || u1 == Unit::MIN || u1== Unit::SEC){//the sub unit time
        if (u2 == Unit::HOUR || u2 == Unit::MIN || u2== Unit::SEC){
            return true;
        }
    } 
    return false; //not match
}

//help function
double PhysicalNumber::unitCast( Unit u1, const PhysicalNumber Pn)const{//this function send to another function that convert a physical numbers from the same sub unit
  if(Pn.u== Unit::HOUR || Pn.u == Unit::MIN || Pn.u== Unit::SEC){
      return timeConvert(u1, Pn);
  }
  if(Pn.u== Unit::TON || Pn.u == Unit::KG || Pn.u== Unit::G){
      return weightConvert(u1, Pn);
  }
  if(Pn.u== Unit::KM || Pn.u == Unit::M || Pn.u== Unit::CM){
      return lengthConvert(u1, Pn);
  }
  return 0;
}

double PhysicalNumber::timeConvert( Unit u1,const PhysicalNumber Pn)const{//this function convert physical numbers from the time sub unit
    if(u1 == Unit::HOUR){
        if(Pn.u == Unit::MIN)
        return Pn.value/60; 
        if(Pn.u == Unit::SEC)
        return Pn.value/3600; 
    }
    if(u1 == Unit::MIN){
        if(Pn.u == Unit::HOUR)
        return Pn.value*60; 
        if(Pn.u == Unit::SEC)
        return Pn.value/60; 
    }
    if(u1 == Unit::SEC){
        if(Pn.u == Unit::HOUR)
        return Pn.value*3600; 
        if(Pn.u == Unit::MIN)
        return Pn.value*60; 
    }
    return 0;
}

double PhysicalNumber::weightConvert( Unit u1, const PhysicalNumber Pn)const {//this function convert physical numbers from the weight sub unit
    if(u1 == Unit::TON){
        if(Pn.u == Unit::KG)
        return Pn.value/1000; 
        if(Pn.u == Unit::G)
        return Pn.value/1000000; 
    }
    if(u1 == Unit::KG){
        if(Pn.u == Unit::TON)
        return Pn.value*1000; 
        if(Pn.u == Unit::G)
        return Pn.value/1000; 
    }
    if(u1 == Unit::G){
        if(Pn.u == Unit::TON)
        return Pn.value*1000000; 
        if(Pn.u == Unit::KG)
        return Pn.value*1000; 
    }
    return 0;
}

 double PhysicalNumber::lengthConvert( Unit u1,const PhysicalNumber Pn) const{//this function convert physical numbers from the distance sub unit
    if(u1 == Unit::KM){
        if(Pn.u == Unit::M)
        return Pn.value/1000; 
        if(Pn.u == Unit::CM)
        return Pn.value/100000; 
    }
    if(u1 == Unit::M){
        if(Pn.u == Unit::KM)
        return Pn.value*1000; 
        if(Pn.u == Unit::CM)
        return Pn.value/100; 
     } 
    if(u1 == Unit::CM){
        if(Pn.u == Unit::KM)
        return Pn.value*100000; 
        if(Pn.u == Unit::M)
        return Pn.value*100; 
    } 
    return 0;
}

const PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& Pn) const{//+ operator
    if( ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) !=(int)( Pn.u)) {//if we need to convert
             return PhysicalNumber(this->value + unitCast(this->u, Pn),this->u);
         }
           else{
             return PhysicalNumber(this->value +Pn.value,this->u);
           } 
    }
         std::__throw_bad_exception();//not the same unit
   
}

const PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& Pn) const{//- operator
    if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
             return PhysicalNumber(this->value - unitCast(this->u, Pn),this->u);
         }
         else{
             return PhysicalNumber(this->value -Pn.value,this->u);
         } 
    }
         std::__throw_bad_exception();//not the same unit
}

PhysicalNumber& PhysicalNumber::operator+= (const PhysicalNumber& Pn){
    if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
             this->setValue(this->value + unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(this->value + Pn.value);
             return *this;
             
         } 
    }
         std::__throw_bad_exception();//not the same unit
}

PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& Pn){
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
             this->setValue(this->value - unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(this->value-Pn.value);
             return *this;
         } 
    }
         std::__throw_bad_exception();//not the same unit
}

PhysicalNumber& PhysicalNumber::operator= (const PhysicalNumber& Pn){
         if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
             this->setValue(unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(Pn.value);
             return *this;
         } 
    }
         std::__throw_bad_exception();//not the same unit
}

//פעולות אונריות
const PhysicalNumber PhysicalNumber::operator+ () const{
    return  PhysicalNumber (this->value, this->u);
}
const PhysicalNumber PhysicalNumber::operator- () const{
      return PhysicalNumber ((this->value)*-1, this->u);
}

//true or fulse operators
const bool PhysicalNumber::operator== (const PhysicalNumber& Pn) const{
    if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) == comper)
             return true; 
         }
         else{
              if((double)(this->value) == Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}  

const bool PhysicalNumber::operator> (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) > comper)
             return true; 
         }
         else{
              if((double)(this->value) > Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}
const bool PhysicalNumber::operator< (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) < comper)
             return true; 
         }
         else{
              if((double)(this->value) < Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}
const bool PhysicalNumber::operator<= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) <= comper)
             return true; 
         }
         else{
              if((double)(this->value) <= Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}
const bool PhysicalNumber::operator>= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) >= comper)
             return true; 
         }
         else{
              if((double)(this->value) >= Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}
const bool PhysicalNumber::operator!= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){//if its from the same unit
         if((int)(this->u) != (int)(Pn.u)) {//if we need to convert
              double comper=unitCast(this->u, Pn);
             if((double)(this->value) != comper)
             return true; 
         }
         else{
              if((double)(this->value) != Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();//not the same unit
}

//prefix
PhysicalNumber& PhysicalNumber::operator++ (){//add 1 to the physical number
    this->setValue(this->value+1);
    return *this;
}
PhysicalNumber& PhysicalNumber::operator-- (){//sub 1 to the physical number
    this->setValue(this->value-1);
      return *this;
}

PhysicalNumber PhysicalNumber::operator++(int i) {//add 1 to the physical number
        PhysicalNumber copy = *this;
        value++;
        return copy;
}

PhysicalNumber PhysicalNumber::operator--(int i) {//sub 1 to the physical number
        PhysicalNumber copy = *this;
        value--;
        return copy;
}


//friends functions
 ostream& ariel::operator<< (ostream& os, const PhysicalNumber& Pn){//print on the screen the physical number
     string ans="";
  if(Pn.u== Unit::HOUR){//we need to print hour
      ans="hour";
  }
  if(Pn.u== Unit::MIN){
      ans="min";
  }
  if(Pn.u== Unit::SEC){
      ans="sec";
  }
  if(Pn.u== Unit::TON){
      ans="ton";
  }
  if(Pn.u== Unit::KG){
      ans="kg";
  }
  if(Pn.u== Unit::G){
      ans="g";
  }
  if(Pn.u== Unit::KM){
      ans="km";
  }
  if(Pn.u== Unit::M){
      ans="m";
  }
  if(Pn.u== Unit::CM){
      ans="cm";
  }
    return (os << Pn.value << '[' << ans << ']') ;
}

 istream& ariel::operator>> (istream& is, PhysicalNumber& Pn){
    double new_value;
    string unitValue;
    int unit_number=-1;
    bool ans=false;
    is>>new_value>>unitValue;  

// check if the input is valid
    string unitname [9]={"[km]","[m]","[cm]","[ton]","[kg]","[g]","[hour]","[sec]","[min]"};
    for(int i=0;i<9&&(!ans);i++){
        if(unitValue.compare(unitname[i])==0){
          ans=true;
          unit_number=i;
        }
    }
    if(ans==true){//insert the input
        Pn.setValue(new_value);
        Pn.setUnit(unit_number);
     
        return is;
    }
    else{//return the old value
        is.setstate(std::ios::badbit);
          return is;
    }
}