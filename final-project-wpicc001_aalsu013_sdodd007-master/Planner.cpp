#ifndef __PLANNER_CPP__
#define __PLANNER_CPP__

#include "task.hpp"
#include "school_task.hpp"
#include "personal_task.hpp"
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include "SortClass.hpp"
#include "SortCategory.cpp"
#include "SortPriority.cpp"
#include "SortName.cpp"

#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define RESET   "\033[0m"
#define BLUE    "\033[34m"      /* Blue */
#define RED     "\033[31m"      /* Red */

using namespace std;

class Planner
{

	private: 
		vector<Task> SortSet;
		vector<Task> FilterSet;
		bool CurrentSet;
		bool firstread;	
	public:

	
	Planner()
	{
		CurrentSet = true;
		firstread = false;
	}
	Planner(vector<Task> vect)
	{
		SortSet = vect;
		FilterSet = vect;
		CurrentSet = true;
		firstread = false;
	}
	
	void Filter_Tasks(){
		CurrentSet = false;
		cout << "How do you want to filter your tasks?" << endl;
		cout << "1. By priority." << endl;
	//	cout << "2. By date." << endl;
		cout << "2. By name." << endl;
		cout << "3. By category." << endl;
		cout << "4. Cancel." << endl;

		string theinput;
		cin >> theinput;

		if (theinput == "1")
		{
			SortPriority theSort;
			theSort.Filter(FilterSet);
		}	
		//else if (theinput == "2")
		//{
		//	SortDate theSort;
		//	theSort.Filter(FilterSet);
		//}
		else if (theinput == "2")
		{
			SortName theSort;
			theSort.Filter(FilterSet);
		}
		else if (theinput == "3")
		{	
			SortCategory theSort;
			theSort.Filter(FilterSet);
		}
		else if (theinput == "4")
		{
			DisplayMenu();
		}
		else 
		{
			cout << "Invalid Input!" << endl;
			Filter_Tasks();
		}
	}
	void Sort_Tasks(){
		CurrentSet = true;	
		cout << "How do you want to sort your tasks?" << endl;
		cout << "1. By priority." << endl;
		//cout << "2. By date." << endl;
		cout << "2. By name." << endl;
		cout << "3. By category." << endl;
		cout << "4. Cancel." << endl;

		string theinput;
		cin >> theinput;

		if (theinput == "1")
		{
			SortPriority theSort;
			theSort.Sorting(SortSet);
		}	
		//else if (theinput == "2")
		//{
		//	SortDate theSort;
		//	theSort.Sorting(SortSet);
		//}
		else if (theinput == "2")
		{
			SortName theSort;
			theSort.Sorting(SortSet);
		}
		else if (theinput == "3")
		{	
			SortCategory theSort;
			theSort.Sorting(SortSet);
		}
		else if (theinput == "4")
			DisplayMenu();
		else 
		{
			Sort_Tasks();
		}
		
	}
	void ResetFilter(){
		CurrentSet = true;
		FilterSet.clear();
		FilterSet = SortSet;
	}
	void ClosePlanner(){
		cout << "Closing program. Have a good day!" << endl;
	}
	void Display_Planner(){
                if (CurrentSet == true){
                        int i = 0;
                        if (SortSet.size() != 0 ){
                                while (i < SortSet.size()){
                                       if(SortSet.at(i).getCategory() == "School"){

                                               	cout << "Task Name: " << BLUE << SortSet.at(i).getName() << RESET << endl;
                                                cout << "Task Category: " << BOLDMAGENTA << SortSet.at(i).getCategory() << RESET << endl;
                                                cout << "Description: " << GREEN << SortSet.at(i).getDescription() << RESET << endl;
                                                cout << "Due Date: " << YELLOW << SortSet.at(i).getMonth() << "/" << SortSet.at(i).getDay() << "/" << SortSet.at(i).getYear() << RESET << endl;
                                                cout << "Priority: " << RED << SortSet.at(i).getPriority() << RESET << endl;
                                                cout << endl;
                                        }
                                        else {
                                                cout << "Task Category: " << BOLDMAGENTA << SortSet.at(i).getCategory() << RESET << endl;
                                                cout << "Task Name: " << BLUE << SortSet.at(i).getName() << RESET << endl;
                                                cout << "Description: " << GREEN << SortSet.at(i).getDescription() << RESET << endl;
                                                cout << "Date: " << YELLOW << SortSet.at(i).getMonth() << "/" << SortSet.at(i).getDay() << "/" << SortSet.at(i).getYear() << RESET << endl;
                                                cout << endl;
                                        }
                                        i++;
				
                                }
			}
                        else
                                cout << "Planner Empty!" << endl;
                }
                else if (CurrentSet == false){
                        int i = 0;
			if (FilterSet.size() != 0){
                        	while (i < FilterSet.size()){
                                       if(FilterSet.at(i).getCategory() == "School"){

                                                cout << "Task Name: " << BLUE << FilterSet.at(i).getName() << RESET << endl;
                                                cout << "Task Category: " << BOLDMAGENTA <<FilterSet.at(i).getCategory() << RESET << endl;
                                                cout << "Description: " << GREEN << FilterSet.at(i).getDescription() << RESET << endl;
                                                cout << "Due Date: " << YELLOW << FilterSet.at(i).getMonth() << "/" << FilterSet.at(i).getDay() << "/" << FilterSet.at(i).getYear() << RESET << endl;
                                                cout << "Priority: " << RED << FilterSet.at(i).getPriority() << RESET << endl;
                                                cout << endl;
                                        }
                                        else {
                                                cout << "Task Category: " << BOLDMAGENTA << FilterSet.at(i).getCategory() << RESET << endl;
                                                cout << "Task Name: " << BLUE << FilterSet.at(i).getName() << RESET << endl;
                                                cout << "Description: " << GREEN << FilterSet.at(i).getDescription() << RESET << endl;
                                                cout << "Date: " << YELLOW << FilterSet.at(i).getMonth() << "/" << FilterSet.at(i).getDay() << "/" << FilterSet.at(i).getYear() << RESET << endl;
                                                cout << endl;
                                        }
                                        i++;

                                }
                        }
                        else
                                cout << "Planner Empty!" << endl;
                }

        }
	void Save_Task(){
		
	}
	void Read_From_File(){
		ifstream infile;	
		infile.open("Tasks.txt");
		if (!infile){		
			ofstream outFile;
			outFile.open("Tasks.txt");
			outFile.close();
			Read_From_File();
		}
		else{
			int i = 0;
			SortSet.clear();
			while(!infile.eof()) {
				string name, description, category, priority, day, month, year;
				getline(infile, category, '\n');	
				getline(infile, name, '\n');	
				getline(infile, description, '\n');
				
				getline(infile, priority, '\n');
				getline(infile, day, '\n');
				getline(infile, month, '\n');
				getline(infile, year, '\n');

				string skip;
				int theDay, theMonth, theYear, theprio;	
				getline(infile, skip);
				if (priority == "")
					theprio;
				else
					theprio = stoi(priority);
				if (day == "")
					theDay;
				else
					theDay = stoi(day);
				if (month == "")
					theMonth;
				else
					theMonth = stoi(month);
				if (year == "")
					theYear;
				else
					theYear = stoi(year);
	
				if (category == "School")
				{	
					SortSet.push_back(SchoolTask((string)category, (string)name, description, theprio, theDay, theMonth, theYear));
				}
				else if(category == "Personal")
				{					
					SortSet.push_back(PersonalTask(category, name, description, theprio, theDay, theMonth, theYear));					
				}
				else{
					getline(infile, skip);
					getline(infile, skip);
				}
				i++;				
			}
			if (FilterSet.size() == 0 && firstread == false)
			{	
				firstread = true;
				FilterSet = SortSet;
			}
			else{
			}
			infile.close();
		}	
	}
	void Write_To_File(){
		ofstream outFile;
		outFile.open("Tasks.txt");
		int i = 0;
		int size = SortSet.size();
		while (i < SortSet.size()){
			if (i == SortSet.size()-1){
				outFile << SortSet.at(i).getCategory() << "\n" << SortSet.at(i).getName() << "\n" << SortSet.at(i).getDescription() << "\n" << SortSet.at(i).getPriority() << '\n' << SortSet.at(i).getDay() << '\n' << SortSet.at(i).getMonth() << '\n' << SortSet.at(i).getYear() << endl;
				i++;
			}
			else{
			outFile << SortSet.at(i).getCategory() << "\n" << SortSet.at(i).getName() << "\n" << SortSet.at(i).getDescription() << "\n" << SortSet.at(i).getPriority() << '\n' << SortSet.at(i).getDay() << '\n' << SortSet.at(i).getMonth() << '\n' << SortSet.at(i).getYear() << '\n' <<  endl;
			i++;
			}
		}
		//cout << "Finished Saving Tasks!!" << endl;
		outFile.close();
	}
	void DisplayMenu(){
		Read_From_File();
		
		string input;
	
		cout << "Welcome to PlannerPlus. Enter the corresponding number for the following options follwed by [ENTER]." << endl;
		
		cout << "1. Create New Task." << endl;
		cout << "2. Display Existing Task(s)." << endl;
		cout << "3. Sort or Filter Your Tasks." << endl;
		cout << "4. Delete a Task." << endl;
		cout << "5. Edit an Existing Task" << endl;
		cout << "6. Quit." << endl;

		cin >> input;
	
		if (input == "1") {
			cout << "What type of task would you like to create? Enter the corresponding number for the following options follwed by [ENTER]." << endl;
			cout << "1. School Task." << endl;
			cout << "2. Personal Task." << endl;
			cout << "3. Go back to the main menu." << endl;
			cin >> input;
			if (input == "1"){
				SchoolTask theTask;
				theTask.Add_SchoolTask();
				SortSet.push_back(theTask);
				Write_To_File();
						
			}
			else if (input == "2"){
				PersonalTask theTask;
				theTask.Add_PersonalTask();
				SortSet.push_back(theTask);	
				Write_To_File();
			}
			else if (input == "3"){
				DisplayMenu();
			}
			else {
				cout << "Invalid Input! Try again!" << endl;
				DisplayMenu();
			}
			cout << "Returning to main menu..." << endl;
			DisplayMenu();	
		}
		else if (input == "2"){
			Display_Planner();
			DisplayMenu();
		}
		else if (input == "3"){
			cout << "Do you wish to Sort your current tasks or filter out to see tasks of only a certain type?" << endl;
			cout << "1. Sort your list of tasks." <<endl;
			cout << "2. Filter your tasks." << endl;
			cout << "3. Remove your filter." << endl;
			string userinput;
			cin >> userinput;
			
			if (userinput == "1")
				Sort_Tasks();
			else if (userinput == "2")
				Filter_Tasks();
			else if (userinput == "3")
				ResetFilter();
			else{
				cout << "Invalid Input! Restarting Menu!" << endl;
				DisplayMenu();
			}
			Write_To_File();
			DisplayMenu();
		}
		else if (input == "4"){
			cout << "Please enter a number for which task you want to delete: ";
			cin >> input;
			int tasknumber = (stoi(input))-1;
			cout << SortSet.at(tasknumber).getName() << endl;
			vector<Task>::iterator it;
			it = SortSet.begin()+tasknumber;	
			SortSet.erase(it);
	//		cout << "here" << endl;
			Write_To_File();
			DisplayMenu();
		}
		else if (input == "5") {
			
			cout << "Please enter a number for which task you want to edit: ";
			cin >> input;
			cout << endl;
			int tasknumber = stoi(input)-1;
	//		cout << "In edit task of planner!" << endl;
			if (SortSet.at(tasknumber).getCategory() == "School")
			{
		//		cout << "About to call edit for schooltask object" << endl;


			}
			SortSet.at(tasknumber).EditTask();
			Write_To_File();
			DisplayMenu();
		}
		else if (input == "6"){
			exit(0);
		}
		else {
			cout << "Invalid Input! Try again." << endl;
			DisplayMenu();
		}
	}

};

#endif
