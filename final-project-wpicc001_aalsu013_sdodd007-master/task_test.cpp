#ifndef __TASK_TEST_HPP__
#define __TASK_TEST_HPP__

#include "gtest/gtest.h"

#include "task.hpp"
//#include "task.cpp"
#include <string>
#include <cstring>
#include <iostream>


TEST(taskTest, nameTest){ 
  Task* t1 = new Task();
  t1->setName("CS Project");
  
  EXPECT_EQ(t1->getName(), "CS Project");
}

TEST(taskTest, dayTest){ 
  Task* t1 = new Task();
  t1->setDay(5);
  
  EXPECT_EQ(t1->getDay(), 5);
}
TEST(taskTest, monthTest){ 
  Task* t1 = new Task();
  t1->setMonth(6);
 
  EXPECT_EQ(t1->getMonth(), 6);
  
}

TEST(taskTest, yearTest){ 
  Task* t1 = new Task();
  t1->setYear(2021);
 
  EXPECT_EQ(t1->getYear(), 2021);
}

TEST(taskTest, priorityTest){ 
  Task* t1 = new Task();
  t1->setPriority(2);
 
  EXPECT_EQ(t1->getPriority(), 2);

}
TEST(taskTest, descriptionTest){ 
 
  Task* t1 = new Task();
  t1->setDescription("Finish making tests");

  EXPECT_EQ(t1->getDescription(), "Finish making tests");
}

TEST(taskTest, categoryTest){ 
 
  Task* t1 = new Task();
  t1->setCategory("School");

  EXPECT_EQ(t1->getCategory(), "School");
}



TEST(taskTest, allTest){ 
 
  Task* t1 = new Task();
  t1->setName("CS Project");
  t1->setDay(5);
  t1->setMonth(6);
  t1->setYear(2021);
  t1->setPriority(2);
  t1->setDescription("Finish making tests");
  t1->setCategory("School");
  
  EXPECT_EQ(t1->getName(), "CS Project");
  EXPECT_EQ(t1->getDay(), 5);
  EXPECT_EQ(t1->getMonth(),6);
  EXPECT_EQ(t1->getYear(), 2021);
  EXPECT_EQ(t1->getPriority(), 2);
  EXPECT_EQ(t1->getDescription(), "Finish making tests");
  EXPECT_EQ(t1->getCategory(), "School");
}

TEST(taskTest, allEmpty){ 
 
  Task* t1 = new Task();
  t1->setName("");
  t1->setDay(0);
  t1->setMonth(0);
  t1->setYear(0);
  t1->setPriority(0);
  t1->setDescription("");
  t1->setCategory("");
  
  EXPECT_EQ(t1->getName(), "");
  EXPECT_EQ(t1->getDay(), 0);
  EXPECT_EQ(t1->getMonth(),0);
  EXPECT_EQ(t1->getYear(), 0);
  EXPECT_EQ(t1->getPriority(), 0);
  EXPECT_EQ(t1->getDescription(), "");
  EXPECT_EQ(t1->getCategory(), "");
}
/*
TEST(taskTest, editName){ 
  Task* t1 = new Task();
  t1->setName("CS Project");
  
  string edit_input = 1;
  t1->EditTask("CS 100 Project");
  
  EXPECT_EQ(t1->getName(), "CS 100 Project");
}

TEST(taskTest, editDescription){ 
  Task* t1 = new Task();
  t1->setDescription("Finish making tests");
  
  string edit_input = 2;
  t1->EditTask("Finish making unit tests for all files");

  EXPECT_EQ(t1->getDescription(), "Finish making unit tests for all files");
}

TEST(taskTest, editDueDate){ 
  Task* t1 = new Task();
  t1->setDay(5);
  t1->setMonth(6);
  t1->setYear(2021);
  
  string edit_input = 3;
  t1->EditTask(20);
  t1->EditTask(7);
  t1->EditTask(2021);
  
   EXPECT_EQ(t1->getDay(), "20");
   EXPECT_EQ(t1->getMonth(), "7");
  EXPECT_EQ(t1->getYear(), "2021");
}

TEST(taskTest, editPriority){ 
  Task* t1 = new Task();
  t1->setPriority(2);
  
  string edit_input = 4;
  t1->EditTask(3);
 
  EXPECT_EQ(t1->getPriority(), "3");

}
*/

#endif
