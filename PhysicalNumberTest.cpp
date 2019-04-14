/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber check1(2, Unit::HOUR);
    PhysicalNumber check2(14, Unit::MIN);
    PhysicalNumber check3(32, Unit::SEC);
    PhysicalNumber check4(43, Unit::MIN);
    PhysicalNumber check5(4, Unit::HOUR);
    PhysicalNumber check6(28, Unit::SEC);
    PhysicalNumber check77(120, Unit::MIN);
    PhysicalNumber check7(120, Unit::SEC);
    PhysicalNumber check8(0, Unit::HOUR);
    PhysicalNumber check9(0, Unit::SEC);
    PhysicalNumber check10(5, Unit::KM);
    PhysicalNumber check11(10, Unit::M);
    PhysicalNumber check12(300, Unit::CM);
    PhysicalNumber check13(25, Unit::KM);
    PhysicalNumber check14(1000, Unit::CM);
    PhysicalNumber check15(4000, Unit::M);
    PhysicalNumber check16(3, Unit::KM);
    PhysicalNumber check17(3000, Unit::M);
    PhysicalNumber check18(300000, Unit::CM);
    PhysicalNumber a1(6, Unit::TON);
    PhysicalNumber a2(6000, Unit::KG);
    PhysicalNumber b1(30, Unit::KG);
    PhysicalNumber b2(3000, Unit::KG);
    PhysicalNumber b3(30000, Unit::KG);
    PhysicalNumber b4(1, Unit::KG);
    PhysicalNumber c1(2, Unit::G);
    PhysicalNumber c2(0.002, Unit::KG);
    PhysicalNumber c3(1000, Unit::G);
    PhysicalNumber d1(30, Unit::MIN);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)



    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
   .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")


    // YOUR TESTS - INSERT AS MANY AS YOU WANT


  //    .setname("check time unit") 
  //   .CHECK_OUTPUT(check6+check3, "60[sec]")
  //   .CHECK_EQUAL(check1==check77,true)
  //   .CHECK_OUTPUT(check77-check1, "0[min]")
  //   .CHECK_OUTPUT((check1+=check2), "2.23333[hour]")
  //   .CHECK_OUTPUT(check1,  "2.23333[hour]")
  //   .CHECK_OUTPUT(check4+check3, "43.5333[min]")
  //   .CHECK_OUTPUT(check1+check5+check77, "8.23333[hour]")
  //   .CHECK_OUTPUT(check6, "28[sec]")
  //   .CHECK_OUTPUT(check8+check77, "2[hour]")
  //   .CHECK_OUTPUT(check7-check8, "120[sec]")
  //   .CHECK_OUTPUT(check5-check8, "4[hour]")
  //   .CHECK_OUTPUT(++check1, "3.23333[hour]")
  //   .CHECK_OUTPUT(check5, "4[hour]")
  //   .CHECK_OUTPUT(--check7, "119[sec]")
  //   .CHECK_OUTPUT(check7, "119[sec]")
  //   .CHECK_EQUAL(check7>check8,true)
  //   .CHECK_EQUAL(check4<check5,true)
  //   .CHECK_EQUAL(check7==check8,false)
  //   .CHECK_EQUAL(check8!=check9,false)
  //   .CHECK_EQUAL(check4>=check3,true)
  //   .CHECK_EQUAL(check7<=check8,false)

  //   .CHECK_THROWS(a+check6)
  //   .CHECK_THROWS(check1+b)
  //   .CHECK_THROWS(a+check8)
  //   .CHECK_THROWS(b+check3)

  // .setname("check length unit")
  //   .CHECK_EQUAL(check16==check17,true)
  //   .CHECK_EQUAL(check18==check16, true)
  //   .CHECK_EQUAL(check17==check18, true)
  //   .CHECK_EQUAL(check11==check14, true)
  //   .CHECK_EQUAL(check11<check10,true)
  //   .CHECK_EQUAL(check18>check10,false)
  //   .CHECK_EQUAL(check10<=check12, false)
  //   .CHECK_EQUAL(check10>=check15, true)
  //   .CHECK_EQUAL(check16!=check17, false)
  //   .CHECK_EQUAL(check13!=check15, true)
  //   .CHECK_EQUAL(check14!=check18, true)
  //   .CHECK_EQUAL(check16>check15, false)
  //   .CHECK_EQUAL(check14<check12, false)
  //   .CHECK_EQUAL(check13>=check14, true)
  //   .CHECK_EQUAL(check16>check14, true)
  //   .CHECK_EQUAL(check17<check18, false)
  //   .CHECK_EQUAL(check17>=check15, false)
  //   .CHECK_EQUAL(check13<=check18, false)
  //    .CHECK_OUTPUT(check10+check11, "5.01[km]")
  //   .CHECK_OUTPUT((check10+=check17), "8[km]")
  //   .CHECK_OUTPUT(check10, "8[km]")
  //   .CHECK_OUTPUT(check11+check10,  "8010[m]")
  //   .CHECK_OUTPUT(check16+check17, "6[km]")
  //   .CHECK_OUTPUT(check13-check18, "22[km]")
  //   .CHECK_OUTPUT(check14, "1000[cm]")
  //   .CHECK_OUTPUT(check17, "3000[m]")
  //   .CHECK_OUTPUT(check12+check14, "1300[cm]")
  //   .CHECK_OUTPUT(check14+check17, "301000[cm]")
  //   .CHECK_OUTPUT(check17+check14, "3010[m]")
  //   .CHECK_OUTPUT(check16+check14, "3.01[km]")
  //   .CHECK_OUTPUT(check11-check14, "0[m]")

  //   .setname("check Weight unit")
  //   .CHECK_OUTPUT(a1, "6[ton]")
  //   .CHECK_OUTPUT(b1, "30[kg]")
  //   .CHECK_OUTPUT(c1, "2[g]")
  //   .CHECK_OUTPUT(d1, "30[min]")
  //   .CHECK_OUTPUT(a1+a1, "12[ton]")
  //   .CHECK_OUTPUT(a1+b1, "6.03[ton]")
  //   .CHECK_OUTPUT(b1+c1, "30.002[kg]")
  //   .CHECK_OUTPUT(c1+b1, "30002[g]")
  //   .CHECK_OUTPUT(b1-c1, "29.998[kg]")
  //   .CHECK_THROWS(d1+c1)
  //   .CHECK_OUTPUT((b1+=c1), "30.002[kg]")
  //   .CHECK_OUTPUT((b1-=b1), "0[kg]")
  //   .CHECK_EQUAL(c1==c2, true)
  //   .CHECK_EQUAL(a1==a2, true)
  //   .CHECK_EQUAL(a1>b2, true)
  //   .CHECK_EQUAL(a1>b3, false)
  //   .CHECK_EQUAL(a1<=b3, true)
  //   .CHECK_EQUAL(b4>=c3, true)
  //   .CHECK_EQUAL(a1!=a2, false)
  //   .CHECK_THROWS(d1+c1)
  //   .CHECK_OUTPUT(++b1, "1[kg]")
  //   .CHECK_OUTPUT(--c3, "999[g]")
  //   .CHECK_OUTPUT((PhysicalNumber(5,Unit::TON)-PhysicalNumber(400,Unit::KG)),"4.6[ton]")
  //   .CHECK_OUTPUT((PhysicalNumber(200,Unit::KG)+PhysicalNumber(6000,Unit::G)),"206[kg]")
  //   .CHECK_THROWS(PhysicalNumber(220,Unit::TON)+PhysicalNumber(2.4,Unit::HOUR))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::TON)-d1)
  //   .CHECK_OK(b2 = PhysicalNumber(3000,Unit::G))
  //   .CHECK_OUTPUT(b2,"3[kg]")
  //  .CHECK_EQUAL(PhysicalNumber(5,Unit::TON)=="PhysicalNk exeptions")
  //   .CHECK_THROWS(PhysicalNumber(220,Unit::TON)+PhysicalNumber(2.4,Unit::HOUR))
  //   .CHECK_THROWS(a+c)
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::TON)+PhysicalNumber(2.4,Unit::KM))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::KM)+PhysicalNumber(2.4,Unit::HOUR))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::CM)+PhysicalNumber(2.4,Unit::TON))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::MIN)+PhysicalNumber(2.4,Unit::CM))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::CM)+PhysicalNumber(2.4,Unit::SEC))
  //   .CHECK_THROWS(a1=d1)
  //   .CHECK_THROWS(a1+d1)
  //   .CHECK_THROWS(d1=PhysicalNumber(2.4,Unit::TON))
  //   .CHECK_THROWS(PhysicalNumber(2,Unit::CM)=PhysicalNumber(2.4,Unit::SEC))
  //   .CHECK_THROWS(c+a2)

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}


