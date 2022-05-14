#ifndef _SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"
#include <string>
#include <cstring>

using namespace std;


class Select_Or : public Select {

        protected:

                Select* select1;
                Select* select2;


        public:
                Select_Or(Select* s1, Select* s2){
                        select1 = s1;
                        select2 = s2;
                }
		~Select_Or()
		{
			delete select1;
			delete select2;
		}



                virtual bool select(const Spreadsheet* sheet, int row) const {
                        return select1->select(sheet, row) || select2->select(sheet, row);
        }

                
		//return select(sheet->cell_data(row, column)); 
                
};
               

 
                
#endif












































