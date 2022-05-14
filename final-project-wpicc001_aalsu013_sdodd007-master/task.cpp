
#include "task.hpp"

#include <iostream>
#include <string>
#include <cstring>

#define BLUE    "\033[34m"      /* Blue */
#define GREEN   "\033[32m"      /* Green */
#define RESET   "\033[0m"

using namespace std;


Task::Task(){
	string task_name = "";
	string task_category = "";
	string task_description = "";
	int day = 0;
 	int month = 0;
	int year = 0;
	int priority = 0;
}


Task::Task(string category, string name, string description, int thePrio){
	string task_name = name;
        string task_category = category;
        string task_description = description;
	priority = thePrio;
} 

void Task::setDescription(string d) {
	task_description = d;
}
void Task::setName(string n){
	task_name = n;
}
void Task::setDay(int d){
	day = d;
}
void Task::setCategory(string c) {
	task_category = c;
}	
void Task::setMonth(int m){
	month = m;
}
void Task::setYear(int y){
	year = y;
}
void Task::setPriority(int p){
	priority = p;
}
string Task::getDescription(){	
	return task_description;
}
string Task::getName(){
	return task_name; 
}
string Task::getCategory(){
	return task_category;
}
int Task::getDay(){
	return day;
}
int Task::getMonth(){
	return month;
}
int Task::getYear(){
	return year;
}
int Task::getPriority(){
	return priority;
}


 
void Task::EditTask(){

	if (task_category == "School"){
		string edit_input;
                string temp;
	
                cout << "Which of the following would you like to edit? Select the corresponding number followed by [ENTER]." << endl;
                cout << "1. Task name" << endl;
                cout << "2. Task description" << endl;
                cout << "3. Task due date" << endl;
                cout << "4. Task priority" << endl;
		cout << "5. Return to Main Menu." << endl;
	
                cin.ignore();
		cin >> edit_input;
		while(edit_input != "1" && edit_input!= "2" && edit_input!= "3" && edit_input != "4" && edit_input != "5"){
                                cout << "Invalid input. Please try again." << endl;
                		cin >> edit_input;
		}
		if(edit_input == "1") {
			task_name = "";
			cout << "Type your new task name followed by [ENTER]." << endl;
			cin.ignore();
			getline(cin, task_name);
                	
			cout << "You entered: " << BLUE << getName() << RESET << endl; 	
			cout << "Your task name has been changed." << endl;
		
			cout << "Would you like to further edit " << BLUE << getName() << RESET << "? y/n" << endl;
			
                        cin >> edit_input;
                        while((edit_input != "y" && edit_input != "n") && (edit_input != "Y" && edit_input != "N")){
                                cout << "Invalid input. Please try again." << endl;
				cin >> edit_input;
                        }
                        if(edit_input == "y" || edit_input == "Y"){
                                EditTask();
                        }

		}
		else if(edit_input == "2") {
			task_description = "";
			cout << "Type your new task description for " << BLUE << getName() << RESET << " followed by [ENTER]." << endl;
			cin.ignore();
			getline(cin, task_description);

			cout << "You entered: " << GREEN << getDescription() << RESET << endl;
			cout << "Your task description has been changed." << endl;
		}
		else if(edit_input == "3"){
			day = 0;
			month = 0;
			year = 0;
			cout << "You are changing your due date. Answer the following as integers and hit [ENTER] to save." << endl;

			cout << "What day is " << BLUE << getName() << RESET << " due?" << endl;
				string temp;
               		        cin.ignore();
				getline(cin, temp);
               			day = stoi(temp);
                		while (day < 1 || day > 31){
                        		cout << "Invalid input. Please enter a valid day of the month followed by [ENTER]." << endl;
                        		getline(cin, temp);
                        		day = stoi(temp);
                		}

		                cout << "What month is " << BLUE << getName() << RESET << " due?" << endl;

                		getline(cin, temp);
                		month = std::stoi(temp);
                		while(month < 1 || month > 12) {
                        		cout << "Invalid input. Please enter a valid month of the year as an integer followed by [ENTER]." << endl;
                        		getline(cin, temp);
                        		month = stoi(temp);
                		}		

	                cout << "What year is " << BLUE << getName() << RESET << " due?" << endl;

                	getline(cin, temp);
                	year = stoi(temp);
                	while (year < 2021 || year > 3000){
                        	cout << "Invalid input. Please enter a valid year as an integer followed by [ENTER]." << endl;
                        	getline(cin, temp);
                        	year = stoi(temp);
       		       }
			cout << "The new set due date for " << BLUE <<  getName() << RESET << " is: " << GREEN << getMonth() << "/" << getDay() << "/" << getYear() << RESET << endl;
	
		}	
	
		else if (edit_input == "4"){
			cout << "You are setting a new priority for " << BLUE << getName() << RESET << ". Select one of the following corresponding numbers followed by [ENTER]." << endl;
                	cout << "1. Priority is relaxed." << endl;
                	cout << "2. Priority is medium." << endl;
                	cout << "3. Priority is high." << endl;

                	getline(cin, temp);
                	priority = stoi(temp);

                	while(priority < 1 && priority > 3){
                        	cout << "Invalid input. Please enter a valid number corresponding to the level of priority of " << BLUE << getName() << RESET << " follwed by [ENTER]" << endl;
                        	getline(cin, temp);
                        	priority = stoi(temp);
                	}

                	if(priority == 1) {
                        	cout << "The new priority of " << BLUE << getName() << RESET << " is " << GREEN << "relaxed." << RESET << endl;
                	}
			else if(priority == 2) {
               			cout << "The new priority of " << BLUE << getName() << RESET << " is " << GREEN << "medium." << RESET << endl;
                	}
                	else {
				cout << "The new priority of " << BLUE << getName() << RESET << " is " << GREEN << "high." << RESET << endl;
                	}	
		}
		
	}
	
	else if (task_category == "Personal"){
		string edit_input;
                string temp;
	
                cout << "Which of the following would you like to edit? Select the corresponding number followed by [ENTER]." << endl;
                cout << "1. Task name" << endl;
                cout << "2. Task description" << endl;
                cout << "3. Task date" << endl;
		cout << "4. Return to Main Menu." << endl;

                cin.ignore();
		cin >> edit_input;
		while(edit_input != "1" && edit_input!= "2" && edit_input!= "3" && edit_input != "4"){
                                cout << "Invalid input. Please try again." << endl;
                		cin >> edit_input;
		}
		if(edit_input == "1") {
			task_name = "";
			cout << "Type your new task name followed by [ENTER]." << endl;
			cin.ignore();
			getline(cin, task_name);
                	
			cout << "You entered: " << BLUE << getName() << RESET << endl;
                        cout << "Your task name has been changed." << endl;

			cout << "Would you like to further edit " << BLUE << getName() << RESET << "? y/n" << endl;
			
			cin >> edit_input;
                        while((edit_input != "y" && edit_input != "n") && (edit_input != "Y" && edit_input != "N")){
                                cout << "Invalid input. Please try again." << endl;
				cin >> edit_input;
                        }
                        if(edit_input == "y" || edit_input == "Y"){
                                EditTask();
                        }
	
		}
		else if(edit_input == "2") {
			task_description = "";
			cout << "Type your new task description for " << BLUE << getName() << RESET << " followed by [ENTER]." << endl;
			cin.ignore();
			getline(cin, task_description);

			cout << "You entered: " << GREEN << getDescription() << RESET << endl;
			cout << "Your task description has been changed." << endl;
		}
		else if (edit_input == "3"){
			day = 0;
			month = 0;
			year = 0;
			cout << "You are changing the date for " << BLUE << getName() << RESET << ". Please answer the following questions with valid inputs." << endl;
			cout << endl;
			cout << "What day of the month would you like to complete " << BLUE << getName() << RESET << "? Enter a valid day as an integer." << endl;

			cin.ignore();       
        		getline(cin, temp);
			day = stoi(temp);
                	while (day < 1 || day > 31){
                        	cout << "Invalid input. Please enter a valid day of the month followed by [ENTER]." << endl;
                        	getline(cin, temp);
                        	day = stoi(temp);
                	}

		        cout << "What month would you like to complete " << BLUE << getName() << RESET << "? Enter a valid month as an integer." << endl;

                	getline(cin, temp);
                	month = stoi(temp);
                	while(month < 1 || month > 12) {
                        	cout << "Invalid input. Please enter a valid month of the year as an integer followed by [ENTER]." << endl;
                        	getline(cin, temp);
                        	month = stoi(temp);
                	}		

	                cout << "What year would you like to complete " << BLUE << getName() << RESET << "? Enter a valid year as an integer." << endl;

                	getline(cin, temp);
                	year = stoi(temp);
                	while (year < 2021 || year > 3000){
                        	cout << "Invalid input. Please enter a valid year as an integer followed by [ENTER]." << endl;
                        	getline(cin, temp);
                        	year = stoi(temp);
       		       }
			cout << "You have saved the following date for " << BLUE << getName() << RESET << ": " << GREEN << getMonth() << "/" << getDay() << "/" << getYear() << RESET << endl;
	
		}
	
	}




}

