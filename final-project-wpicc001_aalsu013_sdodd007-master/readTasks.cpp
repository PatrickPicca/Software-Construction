#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Tasks {
	public:
		vector<string>taskName;
		vector<string>taskCategory;
		vector<string>taskDescription;
};

int main() {
	Tasks myTask;
	ifstream infile;

	string name;
	string category;
	string description;

//	vector<string>nameV;
//	vector<string>categoryV;
//	vector<string>descriptionV;
	int i = 0;

	infile.open(“Tasks.txt”);

	if (!infile){ 
        	cout << “File cannot be opened“<< endl;
		exit (1); 
	}
	
	else{
	while(!infile.eof()) {
		getline(infile, name, ',');
		myTask.taskName.push_back(name);

		getline(infile, category, ',');
		myTask.taskCategory.push_back(category);

		getline(infile, description, '\n');
		myTask.taskDescription.push_back(description);

		i++;
		}
	}
	infile.close();
	
//	taskName = nameV;
//	taskCategory = categoryV;
//	taskDescription = descriptionV;	
	
	cout << "Task Name" << "\t" << "Task Category" << "\t" << "Task Description" << endl;
	for (int j = 0; j < i; j++) {
		cout << taskName[j] << "\t" << taskCategory[j] << "\t" << taskDescription[j] << endl;
	}

	ofstream outFILE;
	outFILE.open("Tasks.txt");
	
	outFILE << "100 Project, School, Finish Task Scheduler" << endl;
	outFILE.close();

}

