#ifndef __SORTPRIORITY_HPP__
#define __SORTPRIORITY_HPP__

#include "SortClass.hpp"
#include "task.hpp"
#include <vector>
#include <string>
#include <cstring>

class SortPriority : public SortClass 
{

	public:
		virtual void Sorting(vector<Task> &vect){

			std::cout << "How do you wish to sort your tasks by?" << endl;
			std::cout << "1. High Priority" << endl;
			std::cout << "2. Low Priority" << endl;
				
			string input;

			std::cin >> input;
			vector<Task> tempList;
	

			if (input == "1"){
				for (int i = 0; i < vect.size(); i++){	
					if (vect[i].getPriority() == 3)  //Highest Priority
						tempList.push_back(vect[i]);
				}
	
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 2)	//Second Priority
						tempList.push_back(vect[i]);
				}
				
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 1)
						tempList.push_back(vect[i]);
				} 

				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 0)
						tempList.push_back(vect[i]);
				}
			}
			if (input == "2"){
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 0)
						tempList.push_back(vect[i]);
				}
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 1)
						tempList.push_back(vect[i]);
				}
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 2)
						tempList.push_back(vect[i]);
				}
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == 3)
						tempList.push_back(vect[i]);
				}
			}
		


			vect.clear();
			vect = tempList;
			tempList.clear();
		}

		virtual void Filter(vector<Task> &vect){
		
			std::cout << "How do you wish to filter your tasks by?" << endl;
			std::cout << "1. No priority" << endl;
			std::cout << "2. Relaxed priority" << endl;
			std::cout << "3. Medium  priority" << endl;
			std::cout << "4. High priority" << endl;
							
			string input;	
			std::cin >> input;
			vector<Task> tempList;
			int filt = std::stoi(input) - 1;

			if (filt < 0 || filt > 4)
			{
				cout << "Invalid Input." << endl;
				
			}
			else{
				for (int i = 0; i < vect.size(); i++){
					if (vect[i].getPriority() == filt)
						tempList.push_back(vect[i]);
				}			
			}				
			vect.clear();
			vect = tempList;
			tempList.clear();
		}



};

#endif



