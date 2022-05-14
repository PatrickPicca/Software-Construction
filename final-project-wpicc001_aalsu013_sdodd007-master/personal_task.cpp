#include "personal_task.hpp"
#include "task.hpp"
#include <iostream>
#include <string>
#include <cstring>

#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"

using namespace std;


PersonalTask::PersonalTask(string category, string name, string description, int thePrio, int theDay, int theMonth, int theYear){
  	         task_name = name;
        	 task_category = category;
       		 task_description = description;
		 priority = thePrio;
		day = theDay;
		month = theMonth;
		year = theYear;
} 
	void PersonalTask::Add_PersonalTask(){
		task_category = "Personal";
		string temp;
		cout << "You are creating a personal task." << endl;
		
		cout << "Create a title for your task follwed by [ENTER]." << endl;
		cin.ignore();		
		getline(cin, task_name);
		cout << "You entered: " << getName() << endl;

		
		cout << "Create a description for " << BLUE <<  getName() << RESET << ". Once completed, hit [ENTER] to save." << endl;
		getline(cin, task_description);
		cout << "You entered: " << GREEN << getDescription() << RESET << endl;

		cout << "Set a date you'd like to complete " << BLUE << getName() << RESET << " by. Answer the following as integers and hit [ENTER] to save." << endl;
		cout << endl;
		cout << "What day of the month would you like to finish " << BLUE << getName() << RESET << " by?" << endl;
		
		getline(cin, temp);
		day = stoi(temp);
		while (day < 1 || day > 31){
			cout << "Invalid input. Please enter a valid day of the month as an integer followed by [ENTER]." << endl;
			getline(cin, temp);
			day = stoi(temp);
		}
		cout << "You entered: " << GREEN << getDay() << RESET << endl;
		cout << endl;
		cout << "What month do you plan on finishing " << BLUE << getName() << RESET << "?" << endl;
		
		getline(cin, temp);
		month = stoi(temp);
		while(month < 1 || month > 12) {
			cout << "Invalid input. Please enter a valid month of the year as an integer followed by [ENTER]." << endl;
			getline(cin, temp);
			month = stoi(temp);
		}
		cout << "You entered: " << GREEN << getMonth() << RESET << endl;
		cout << endl;
		cout << "What year would you like to finish " << BLUE << getName() << RESET << "?" << endl;
		
                getline(cin, temp);
		year = stoi(temp);
		while (year < 2021 || year > 3000){
			cout << "Invalid input. Please enter a valid year as an integer followed by [ENTER]." << endl;
                        getline(cin, temp);
			year = stoi(temp);
		}
		cout << "You entered: " << GREEN << getYear() << RESET << endl;
		cout << endl;
		cout <<  "You wish to complete " << BLUE << getName() << RESET << " by: " << GREEN << getMonth() << "/" << getDay() << "/" << getYear() << RESET << endl;
		cout << endl;
		cout << BLUE << getName() << " is now saved in your Planner." << endl;
		cout << RESET << endl;

	}

	PersonalTask::PersonalTask(){}
