#ifndef __TASK_HPP__
#define __TASK_HPP__


#include <string>
#include <cstring>
#include <iostream>

using namespace std;


class Task {

	protected:
		string task_name;
		string task_description;
		string task_category;
		int day;
		int month;
		int year;
		int priority;
	public:
		Task();
		Task(string category, string name, string description, int thePrio);
		//string task_description();
		void DisplayTask();
		void SaveTask();
		//void DisplayMenu();		
		void setName(string n);
		void setDay(int d);
		void setMonth(int m);
		void setYear(int y);
		void setPriority(int p);
		void setDescription(string d);
		void setCategory(string c);
		string getDescription();
		string getCategory();
		string getName();
		int getDay();
		int getMonth();
		int getYear();
		int getPriority();
		void EditTask();


};

#endif //__TASK_HPP__










