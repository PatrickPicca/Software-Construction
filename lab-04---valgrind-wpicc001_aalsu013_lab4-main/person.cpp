#include "person.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

Person::Person(const char *name_, Person* father_, Person* mother_){
    name = new char[strlen(name_)+1];
    strcpy(name, name_);
    father = father_;
    mother = mother_;
    capacity = 1;
    numChildren = 0;
    children = new Person*[capacity];
}
//make sure array has enough space for it (+1).. other code does +1 too
//strlen only counts the charac. before the null. therefore must add one to the value of strlen to get enough space

Person::~Person(){
    delete[] children;
delete[] name;
//delete deallocates memory allocated for single object while
// delete[] deallocares memory allocated for array of objects
// was originally delete children;
}

void Person::addChild(Person *newChild){
    if(numChildren == capacity) expand(&children, &capacity);
    children[numChildren++] = newChild;
}

void Person::printAncestors(){
    cout << endl << "Ancestors of " << name << endl;
    printLineage('u', 0);
}

void Person::printDecendents(){
    cout << endl << "Decendents of " << name << endl;
    printLineage('d', 0);
}

void Person::printLineage(char dir, int level){
    char *temp = compute_relation(level);

    if(dir == 'd'){
        for(int i = 0; i < numChildren; i++){
            cout << temp << "child: " << children[i]->getName() << endl;
            children[i]->printLineage(dir, level + 1);
        }
    } else {
        if(mother){
            cout << temp << "mother: " << mother->getName() << endl;
            mother->printLineage(dir, level + 1);
        }
        if(father){
            cout << temp << "father: " << father->getName() << endl;
            father->printLineage(dir, level + 1);
        }
    }
     delete[] temp;
	// need to delete temp
	// compute_relation(level) is returning a char[] (used new[]) so must use delete[] 
}

/* helper function to compute the lineage
* if level = 0 then returns the empty string
* if level >= 1 then returns ("great ")^(level - 1) + "grand "
*/
char* Person::compute_relation(int level){
    if(level == 0) return strcpy(new char[1], "");

    char *temp = strcpy(new char[strlen("grand ") + 1], "grand ");;
    
    for(int i = 2; i <= level; i++){
        char *temp2 = new char[strlen("great ") + strlen(temp) + 1];
        strcat(strcpy(temp2, "great "), temp);
	delete[] temp;
         // deleting temp so that we don't overwrite it..
        temp = temp2;
    }
    return temp;
}

/* non-member function which doubles the size of t
 * NOTE: t's type will be a pointer to an array of pointers
 */
void expand(Person ***t, int *MAX){
  Person **temp = new Person*[2 * *MAX];
  memcpy(temp, *t, *MAX * sizeof(**t));
delete[] *t; 
 *MAX *= 2;
  *t = temp;
	// ***t points to original array/all pointers
	//t gives us the first element in the array (also represents the array itself) 
	// delete *t[] will delete all the pointers in the array
}
