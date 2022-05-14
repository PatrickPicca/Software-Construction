//#ifndef __SORTCATEGORY_HPP__
//#define __SORTCATEGORY_HPP__

#include "SortClass.hpp"
//#include "task.hpp"
#include <vector>
//#include "task.cpp"

class SortCategory : public SortClass
{

	public:
		virtual void Sorting(vector<Task> &vect){
	
			std::cout << "How do you wish to sort your tasks by?" << endl;
			std::cout << "1. School tasks" << endl;
			std::cout << "2. Personal tasks" << endl;
				
			string category;

			std::cin >> category;
			vector<Task> tempList;
			vector<Task> temp2;

			if (category == "1")
			{
				for (int i = 0; i < vect.size(); i++){
					if(vect[i].getCategory() == "School")
						tempList.push_back(vect[i]);
					else  
						temp2.push_back(vect[i]);
				}
				for (int i = 0; i < temp2.size(); i++)
					tempList.push_back(temp2[i]);
			}
			else if (category == "2")
			{
				for (int i = 0; i < vect.size(); i++){
					if(vect[i].getCategory() == "Personal")
						tempList.push_back(vect[i]);
					else
						temp2.push_back(vect[i]);
				}
				for (int i = 0; i < temp2.size(); i++)
					tempList.push_back(temp2[i]);
			}
			else{
				std::cout << "Invalid input!" << endl;
				Filter(vect);
			}	
						
			vect.clear();
			vect = tempList;
			tempList.clear();
			temp2.clear();
		}
		virtual void  Filter(vector<Task> &vect){
		
			std::cout << "How do you wish to filter your tasks by?" << endl;
			std::cout << "1. School tasks" << endl;
			std::cout << "2. Personal tasks" << endl;
			
			//std::cout << "The size of the passed in vect is: " << vect.size() << endl;
	
			string category;

			std::cin >> category;
			vector<Task> tempList;
	
			//std::cout << "About to Filter task objects!" << endl;
			if (category == "1")
			{
				for (int i = 0; i < vect.size(); i++){
					if(vect[i].getCategory() == "School")
						tempList.push_back(vect[i]);					
				}
			}
			else if (category == "2")
			{
				for (int i = 0; i < vect.size(); i++){
					if(vect[i].getCategory() == "Personal")
						tempList.push_back(vect[i]);					
				}
			}
			else{
				std::cout << "Invalid input!" << endl;
				Filter(vect);
			}	
			
			//cout << "At the end of the filter function the size of our set is currently: " << tempList.size() << endl; 
			
			vect.clear();
			vect = tempList;
			tempList.clear();
		}

};

//#endif
