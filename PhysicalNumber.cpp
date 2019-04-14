#include "PhysicalNumber.h"
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace ariel;
using namespace std;

PhysicalNumber::PhysicalNumber(double value, Unit u){
 this->value=value;
 this->u=u;
}

PhysicalNumber::~PhysicalNumber(){
    
}

//help function
const bool  PhysicalNumber::ifMatch(const Unit u1,const Unit u2) const{
    if (u1 == Unit::KM || u1 == Unit::CM || u1 == Unit::M){
        if (u2 == Unit::KM || u2 == Unit::CM || u2== Unit::M){
            return true;
        }
    }
    if (u1 == Unit::TON || u1 == Unit::KG || u1== Unit::G){
        if (u2 == Unit::TON || u2 == Unit::KG || u2== Unit::G){
            return true;
        }
    }
     if (u1 == Unit::HOUR || u1 == Unit::MIN || u1== Unit::SEC){
        if (u2 == Unit::HOUR || u2 == Unit::MIN || u2== Unit::SEC){
            return true;
        }
    } 
    return false; 
}//end ifMatch

//help function
double PhysicalNumber::unitCast( Unit u1, const PhysicalNumber Pn)const{
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

double PhysicalNumber::timeConvert( Unit u1,const PhysicalNumber Pn)const{
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

double PhysicalNumber::weightConvert( Unit u1, const PhysicalNumber Pn)const {
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

 double PhysicalNumber::lengthConvert( Unit u1,const PhysicalNumber Pn) const{
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

const PhysicalNumber PhysicalNumber::operator+ (const PhysicalNumber& Pn) const{
    if( ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) !=(int)( Pn.u)) {
             return PhysicalNumber(this->value + (double)unitCast(this->u, Pn),this->u);
         }
           else{
             return PhysicalNumber(this->value +Pn.value,this->u);
           } 
    }
         std::__throw_bad_exception();
   
}

const PhysicalNumber PhysicalNumber::operator- (const PhysicalNumber& Pn) const{
    if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
             return PhysicalNumber(this->value - (double)unitCast(this->u, Pn),this->u);
         }
         else{
             return PhysicalNumber(this->value -Pn.value,this->u);
         } 
    }
         std::__throw_bad_exception();
}

PhysicalNumber& PhysicalNumber::operator += (const PhysicalNumber& Pn){
    if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
             this->setValue(this->value + (double) unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(this->value + Pn.value);
             return *this;
             
         } 
    }
         std::__throw_bad_exception();
}

PhysicalNumber& PhysicalNumber::operator-= (const PhysicalNumber& Pn){
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
             this->setValue(this->value - (double)unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(this->value- Pn.value);
             return *this;
         } 
    }
         std::__throw_bad_exception();
}

PhysicalNumber& PhysicalNumber::operator= (const PhysicalNumber& Pn){
         if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
             this->setValue((double)unitCast(this->u, Pn));
             return *this;
             
         }
         else{
              this->setValue(this->u);
             return *this;
         } 
    }
         std::__throw_bad_exception();
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
    if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) == comper)
             return true; 
         }
         else{
              if((double)(this->value) == Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}  

const bool PhysicalNumber::operator> (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) > comper)
             return true; 
         }
         else{
              if((double)(this->value) > Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}
const bool PhysicalNumber::operator< (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) < comper)
             return true; 
         }
         else{
              if((double)(this->value) < Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}
const bool PhysicalNumber::operator<= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) <= comper)
             return true; 
         }
         else{
              if((double)(this->value) <= Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}
const bool PhysicalNumber::operator>= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) >= comper)
             return true; 
         }
         else{
              if((double)(this->value) >= Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}
const bool PhysicalNumber::operator!= (const PhysicalNumber& Pn) const{
     if(ifMatch(this->u, Pn.u) == true){
         if((int)(this->u) != (int)(Pn.u)) {
              double comper=(double)unitCast(this->u, Pn);
             if((double)(this->value) != comper)
             return true; 
         }
         else{
              if((double)(this->value) != Pn.value)
             return true; 
         }
         return false; 
    }
         std::__throw_bad_exception();
}

//prefix
PhysicalNumber& PhysicalNumber::operator++ (){
    this->setValue(this->value+1);
    return *this;
}
PhysicalNumber& PhysicalNumber::operator-- (){
    this->setValue(this->value-1);
      return *this;
}

PhysicalNumber PhysicalNumber::operator++(int i) {
        PhysicalNumber copy = *this;
        value++;
        return copy;
}

PhysicalNumber PhysicalNumber::operator--(int i) {
        PhysicalNumber copy = *this;
        value--;
        return copy;
}


//friends functions
 ostream& ariel::operator<< (ostream& os, const PhysicalNumber& Pn){
     string ans="";
     if(Pn.u== Unit::HOUR){
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

    string unitname [9]={"[km]","[m]","[cm]","[ton]","[kg]","[g]","[hour]","[sec]","[min]"};
    for(int i=0;i<9&&(!ans);i++){
        if(unitValue.compare(unitname[i])==0){
          ans=true;
          unit_number=i;
        }
    }
    if(ans==true){
        Pn.setValue(new_value);
        Pn.setUnit(unit_number);
     
        return is;
    }
    else{
        is.setstate(std::ios::badbit);
          return is;
    }
}