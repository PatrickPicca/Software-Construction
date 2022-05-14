#ifndef __MULT_HPP__
#define __MULT_HPP__
#include "base.hpp"
#include <string>
#include "iostream"
#include "sstream"
#include <iomanip>

using namespace std;

class Mult : public Base {
    private:
         Base* Base1;
         Base* Base2;
    public:
	Mult(): Base1(0), Base2(0) {}
	Mult(Base* theBase1) : Base1(theBase1), Base2(0) {}
	Mult(Base* theBase1, Base* theBase2) : Base1(theBase1), Base2(theBase2) {}

    double evaluate(){
	if (!Base1 && !Base2) 
	{
		return 0.00;
	}
	else if (Base1 && !Base2)
	{
		return Base1->evaluate();
	}
	else
	{
		return Base1->evaluate() * Base2->evaluate();
	}
    }

    string stringify() {
	string answer;
	ostringstream ss;
	ostringstream ss2;
	ss << setprecision(3)<< showpoint << 1.00;
	ss2 << setprecision(3)<< showpoint << 0.00;
	if(!Base1 && !Base2)
	{
		answer =  "(" + ss2.str() + " * " + ss.str() + ")";
	}
	else if(Base1 && !Base2) 
	{
		answer =  "(" + Base1->stringify() + " * " + ss.str() + ")";
	}
	else 
	{
		answer =  "(" + Base1->stringify() + " * " + Base2->stringify() + ")";
	}
	return answer;
    }
};
#endif

