#ifndef __PERSONALTASK_TEST_HPP
#define __PERSONALTASK_TEST_HPP

#include "gtest/gtest.h"

#include "task.hpp"
//#include "task.cpp"

#include "personal_task.cpp"
#include "personal_task.hpp"
#include <string>



TEST(personalTest, nameTest){ 
  PersonalTask* t1 = new PersonalTask();
  t1->setName("CS Project");
  
  EXPECT_EQ(t1->getName(), "CS Project");
}

TEST(personalTest, dayTest){ 
  PersonalTask* t1 = new PersonalTask();
  t1->setDay(5);
  
  EXPECT_EQ(t1->getDay(), 5);
}
TEST(personalTest, monthTest){ 
  PersonalTask* t1 = new PersonalTask();
  t1->setMonth(6);
 
  EXPECT_EQ(t1->getMonth(), 6);
  
}

TEST(personalTest, yearTest){ 
  PersonalTask* t1 = new PersonalTask();
  t1->setYear(2021);
 
  EXPECT_EQ(t1->getYear(), 2021);
}

TEST(personalTest, priorityTest){ 
  PersonalTask* t1 = new PersonalTask();
  t1->setPriority(2);
 
  EXPECT_EQ(t1->getPriority(), 2);

}
TEST(personalTest, descriptionTest){ 
 
  PersonalTask* t1 = new PersonalTask();
  t1->setDescription("Finish making tests");

  EXPECT_EQ(t1->getDescription(), "Finish making tests");
}

TEST(personalTest, categoryTest){ 
 
  PersonalTask* t1 = new PersonalTask();
  t1->setCategory("School");

  EXPECT_EQ(t1->getCategory(), "School");
}



TEST(personalTest, allTest){ 
 
  PersonalTask* t1 = new PersonalTask();
  t1->setName("CS Project");
  t1->setDay(5);
  t1->setMonth(6);
  t1->setYear(2021);
  t1->setPriority(2);
  t1->setDescription("Finish making tests");
  t1->setCategory("School");
  
  EXPECT_EQ(t1->getName(), "CS Project");
  EXPECT_EQ(t1->getDay(), 5);
  EXPECT_EQ(t1->getMonth(), 6);
  EXPECT_EQ(t1->getYear(), 2021);
  EXPECT_EQ(t1->getPriority(), 2);
  EXPECT_EQ(t1->getDescription(), "Finish making tests");
  EXPECT_EQ(t1->getCategory(), "School");
}

TEST(personalTest, allEmpty){ 
 
  PersonalTask* t1 = new PersonalTask();
  t1->setName("");
  t1->setDay(0);
  t1->setMonth(0);
  t1->setYear(0);
  t1->setPriority(0);
  t1->setDescription("");
  t1->setCategory("");
  
  EXPECT_EQ(t1->getName(), "");
  EXPECT_EQ(t1->getDay(),0);
  EXPECT_EQ(t1->getMonth(), 0);
  EXPECT_EQ(t1->getYear(), 0);
  EXPECT_EQ(t1->getPriority(), 0);
  EXPECT_EQ(t1->getDescription(), "");
  EXPECT_EQ(t1->getCategory(), "");
}
/*
TEST(personalTest, editName){ 
  PersonalTask* t1 = new Task();
  t1->setName("CS Project");
  
  edit_input = 1;
  t1->EditTask("CS 100 Project");
  
  EXPECT_EQ(t1->getName(), "CS 100 Project");
}

TEST(personalTest, editDescription){ 
  PersonalTask* t1 = new Task();
  t1->setDescription("Finish making tests");
  
  edit_input = 2;
  t1->EditTask("Finish making unit tests for all files");

  EXPECT_EQ(t1->getDescription(), "Finish making unit tests for all files");
}

TEST(personalTest, editDueDate){ 
  PersonalTask* t1 = new Task();
  t1->setDay(5);
  t1->setMonth(6);
  t1->setYear(2021);
  
  edit_input = 3;
  t1->EditTask(20);
  t1->EditTask(7);
  t1->EditTask(2021);
  
  EXPECT_EQ(t1->getDay(), "20");
  EXPECT_EQ(t1->getMonth(), "7");
  EXPECT_EQ(t1->getYear(), "2021");
}

TEST(personalTest, editPriority){ 
  PersonalTask* t1 = new Task();
  t1->setPriority(2);
  
  edit_input = 4;
  t1->EditTask(3);
 
  EXPECT_EQ(t1->getPriority(), "3");
}
*/

#endif
