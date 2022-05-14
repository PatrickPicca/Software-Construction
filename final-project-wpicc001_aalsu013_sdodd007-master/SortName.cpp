#ifndef __SORTNAME_HPP__
#define __SORTNAME_HPP__


#include "SortClass.hpp"
#include "task.hpp"
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class SortName : public SortClass
{

	public:
		virtual void Sorting(vector<Task> &vect){

			vector<Task> other = vect;

			int n = vect.size();
			int j;
			int i;
			Task temp;
			
			for (i = 0; i < n; i++){
				for (j = i +1; j < n; j++){	
					if (isupper(other.at(i).getName().at(0)) && isupper(other.at(j).getName().at(0))){
						if ((other.at(i).getName().at(0)+32) > (other.at(j).getName().at(0)+32)){
							temp = other.at(i);
						
							other.insert(other.begin()+i,other.at(j));
							other.erase(other.begin()+i+1);
						
							other.insert(other.begin()+j, temp);
							other.erase(other.begin()+j+1);
						} 	
					}
					else if(!isupper(other.at(i).getName().at(0)) && isupper(other.at(i).getName().at(0))){
						if ((other.at(i).getName().at(0)) > (other.at(j).getName().at(0)+32)){
							temp = other.at(i);

							other.insert(other.begin()+i,other.at(j));
							other.erase(other.begin()+i+1);

							other.insert(other.begin()+j, temp);
							other.erase(other.begin()+j+1);
						} 
					}
					else if(isupper(other.at(i).getName().at(0)) && !isupper(other.at(i).getName().at(0))){
						if ((other.at(i).getName().at(0)+32) > (other.at(j).getName().at(0))){
							temp = other.at(i);

							other.insert(other.begin()+i,other.at(j));
							other.erase(other.begin()+i+1);

							other.insert(other.begin()+j, temp);
							other.erase(other.begin()+j+1);
						} 
					}
					else{
						if ((other.at(i).getName().at(0)) > (other.at(j).getName().at(0))){
							temp = other.at(i);

							other.insert(other.begin()+i,other.at(j));
							other.erase(other.begin()+i+1);

							other.insert(other.begin()+j, temp);
							other.erase(other.begin()+j+1);
						} 
					}
				}
			}
			
								
		
			
			vect.clear();
			vect = other;
			other.clear();
		}

		virtual void Filter(vector<Task> &vect){
		
			std::cout << "Please type in the keywords of the titles of the tasks you are looking for, followed by an [ENTER]" << endl;
					
			string input;
			std::cin >> input;
			vector<Task> tempList;

			for (int i = 0; i < vect.size(); i++){	
				if (vect.at(i).getName().find(input) != std::string::npos){
					tempList.push_back(vect[i]);
				}
				else {
					cout << "Keyword not found. Returning to Main Menu." << endl << endl;
					break;
				}
			}			
						
			vect.clear();
			vect = tempList;
			tempList.clear();	
		}


};

#endif
