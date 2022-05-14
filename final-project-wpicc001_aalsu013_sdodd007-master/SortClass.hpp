#ifndef __SORTCLASS_HPP__
#define __SORTCLASS_HPP__

#include "task.hpp"
#include <vector>
#include <string>

using namespace std;

class SortClass {

	public:

		virtual void Sorting(vector<Task> &vect) = 0;

		virtual void Filter(vector<Task> &vect) = 0;
		

}; 

#endif
