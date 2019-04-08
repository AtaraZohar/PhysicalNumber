#include "Unit.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace ariel{

class PhysicalNumber{
  
 private:
 double value;
 Unit u;

 public:
 //constractor
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

//friends functions
friend ostream& operator<< (ostream& os, const PhysicalNumber& Pn);
friend istream& operator>> (istream& is, PhysicalNumber& Pn);

};
}