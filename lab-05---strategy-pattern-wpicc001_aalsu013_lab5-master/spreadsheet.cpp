#include "spreadsheet.hpp"
#include "select.hpp"

#include <algorithm>
#include <iostream>

Spreadsheet::~Spreadsheet()
{
    delete select;
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}


	//criteria for selecting rows is chosen by the user by setting the select pointer
	//to point to an object that implements that criteria
	//if select pointer is null, all rows should be printed 
	

	//if (select == NULL){
	//print all rows
	//nested for loop, outer loop: columns, inner loop: rows

		
//	else {
//		for(int i = 0; i < data.size(); i++ {
//			for(int j = 0; i < data.at(i).size(); j++){
	





void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}

void Spreadsheet::print_selection(std::ostream& out) const {

        //criteria for selecting rows is chosen by the user by setting the select pointer
                //to point to an object that implements that criteria
                        //if select pointer is null, all rows should be printed 
        
        
         if (select == NULL){ 
             //print all rows
             //nested for loop, outer loop: columns, inner loop: rows
         	for(int i = 0; i < data.size(); i++) {  
                	for (int j = 0; j < data.at(i).size();j++) {
                        	out << data[i].at(j) << " ";
                        }
                   	 out << std::endl;
                }
	}
	else {
		for(int i = 0; i < data.size(); i++) {                    
                        for (int j = 0; j < data.at(i).size();j++) {
                               if(select->select(this, i)){
					out << data[i].at(j) << " ";
				}
			}
				if(select->select(this, i)){
			out << std:: endl;
}
}
	

	}
}












