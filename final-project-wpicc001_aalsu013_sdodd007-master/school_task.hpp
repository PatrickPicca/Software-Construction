#ifndef __SCHOOL_TASK_HPP
#define __SCHOOL_TASK_HPP


#include "task.hpp"

class SchoolTask : public Task {


	public: 
		void Add_SchoolTask();
		SchoolTask();

		SchoolTask(string category, string name, string description, int thePrio, int theDay, int theMonth, int theYear);

	
};


#endif
