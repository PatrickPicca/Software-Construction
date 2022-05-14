#ifndef __PERSONAL_TASK_HPP
#define __PERSONAL_TASK_HPP


#include "task.hpp"

class PersonalTask : public Task {


	public: 
		void Add_PersonalTask();
		PersonalTask();

		PersonalTask(string category, string name, string description, int thePrio, int theDay, int theMonth, int theYear);


};


#endif
