#include "Unit.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace ariel{

class PhysicalNumber{
  
 private:
 double value;
 Unit u;

 //helping function
 const bool ifMatch( const Unit u1, const Unit u2)const;
 double unitCast( Unit u1, const PhysicalNumber Pn)const;
 double timeConvert( Unit u1,const PhysicalNumber Pn)const;
 double weightConvert( Unit u1,const PhysicalNumber Pn) const;
 double lengthConvert( Unit u1,const PhysicalNumber Pn)const;

 public:
 //settrs
void setValue (double v){
    this->value=v;
}
void setUnit (int u){
     this->u=(Unit)u;
}


 //constractorenum class Unit{
 PhysicalNumber(double value, Unit u);

//distractor
~ PhysicalNumber();


const PhysicalNumber operator+ (const PhysicalNumber& Pn) const;
const PhysicalNumber operator- (const PhysicalNumber& Pn) const;

PhysicalNumber& operator+= (const PhysicalNumber& Pn);
PhysicalNumber& operator-= (const PhysicalNumber& Pn);
PhysicalNumber& operator= (const PhysicalNumber& Pn);

//פעולות אונריות
const PhysicalNumber operator+ () const;
const PhysicalNumber operator- () const;

//true or fulse operators
const bool operator== (const PhysicalNumber& Pn) const;
const bool operator> (const PhysicalNumber& Pn) const;
const bool operator< (const PhysicalNumber& Pn) const;
const bool operator<= (const PhysicalNumber& Pn) const;
const bool operator>= (const PhysicalNumber& Pn) const;
const bool operator!= (const PhysicalNumber& Pn) const;

//prefix
PhysicalNumber& operator++ ();
PhysicalNumber& operator-- ();
PhysicalNumber operator++(int i);
PhysicalNumber operator--(int i);

//friends functions
friend ostream& operator<< (ostream& os, const PhysicalNumber& Pn);
friend istream& operator>> (istream& is, PhysicalNumber& Pn);

};
ostream& operator<< (ostream& os, const PhysicalNumber& Pn);
istream& operator>> (istream& is, PhysicalNumber& Pn);
}