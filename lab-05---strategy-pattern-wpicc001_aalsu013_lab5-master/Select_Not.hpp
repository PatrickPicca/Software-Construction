#ifndef SELECT_NOT_HPP
#define SELECT_NOT_HPP

#include "select.hpp"


using namespace std;

class Select_Not : public Select
{
private:
    Select* select1;

public:
    	Select_Not(Select* select)
    	{
        	select1 = select;
    	}
	~Select_Not()
	{
		delete select1;
	}

    	virtual bool select(const Spreadsheet* spreadsheet, int row)  const 
    	{
       		return !(select1->select(spreadsheet, row));

    	}
};




#endif //SELECT_NOT
