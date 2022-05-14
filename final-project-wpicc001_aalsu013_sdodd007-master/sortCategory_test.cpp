#ifndef __SORTCATEGORY_TEST_HPP__
#define __SORTCATEGORY_TEST_HPP__
#include "gtest/gtest.h"
#include "SortCategory.cpp"
//#include "task.cpp"
#include "task.hpp"
#include <vector>


TEST(categoryOrder, simpleTestSCHOOL){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("School");
  t1.setMonth(6);
  t1.setDay(5);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("CS HW");
  t2.setCategory("Personal");
  t2.setMonth(6);
  t2.setDay(20);
  t2.setYear(2021);
  templist.push_back(t2);
  
   SortCategory sort;
  sort.Sorting(templist);
 // category = 1; 
  
  EXPECT_EQ(templist.at(0).getDay(), 5);
  EXPECT_EQ(templist.at(0).getCategory(), "School");
}

TEST(categoryOrder, invalidTestPERSONAL){  // First task no category entry
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setMonth(6);
  t1.setDay(5);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("CS HW");
  t2.setCategory("Personal");
  t2.setMonth(6);
  t2.setDay(20);
  t2.setYear(2021);
  templist.push_back(t2);
  
 // category = 2; 
 SortCategory sort;
  sort.Sorting(templist);
 
  EXPECT_EQ(templist.at(0).getDay(), 20);
  EXPECT_EQ(templist.at(0).getCategory(), "Personal"); 
 }
            
TEST(categoryOrder, InvalidTest2SCHOOL){ // Second Task no category entry
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("School");
  t1.setMonth(6);
  t1.setDay(5);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("CS HW");
  t2.setMonth(6);
  t2.setDay(20);
  t2.setYear(2021);
  templist.push_back(t2);
  
   // category = 1;
  SortCategory sort;
  sort.Sorting(templist);
  

  EXPECT_EQ(templist.at(0).getDay(), 5);
  EXPECT_EQ(templist.at(0).getCategory(), "School"); 
}

TEST(categoryOrder, sameCategorySCHOOL){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("School");
  t1.setMonth(6);
  t1.setDay(6);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("CS HW");
  t2.setCategory("School");
  t2.setMonth(6);
  t2.setDay(20);
  t2.setYear(2021);
  templist.push_back(t2);
  
 // category = 1;
  SortCategory sort;
  sort.Sorting(templist);
  
EXPECT_EQ(templist.at(0).getDay(), 6);
  EXPECT_EQ(templist.at(0).getCategory(), "School"); 
}

TEST(categoryOrder, sameCategory2PERSONAL){ // with 3 tasks and latest option
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("Personal");
  t1.setMonth(6);
  t1.setDay(20);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("CS HW");
  t2.setCategory("Personal");
  t2.setMonth(6);
  t2.setDay(2);
  t2.setYear(2021);
  templist.push_back(t2);
  
  Task t3 = Task();
  t3.setName("Math HW");
  t3.setCategory("Personal");
  t3.setMonth(6);
  t3.setDay(1);
  t3.setYear(2021);
  templist.push_back(t3);
  
 // category = 2;
  SortCategory sort;
  sort.Sorting(templist);
  
  EXPECT_EQ(templist.at(0).getDay(), 20);
  EXPECT_EQ(templist.at(0).getCategory(), "Personal"); 
}

TEST(categoryorder, noEntrySCHOOL){  
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("");
  t1.setDay(0);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("CS HW");
  t2.setCategory("");
  t2.setDay(0); 
templist.push_back(t2);
  
  Task t3 = Task();
  t3.setName("Math HW");
  t3.setCategory("");
  t3.setDay(0);
  templist.push_back(t3);
  
 // category = 1;
  SortCategory sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(0).getDay(), 0);
  EXPECT_EQ(templist.at(0).getCategory(), "");
}


TEST(categoryOrder, sortPERSONAL){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setCategory("School");
  t1.setMonth(6);
  t1.setDay(1);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("CS HW");
  t2.setCategory("School");
  t2.setMonth(6);
  t2.setDay(2);
  t2.setYear(2021);
  templist.push_back(t2);
  
  Task t3 =  Task();
  t3.setName("Math HW");
  t3.setCategory("Personal");
  t3.setMonth(6);
  t3.setDay(3);
  t3.setYear(2021);
  templist.push_back(t3);
  
 // category = 2;
  SortCategory sort;
  sort.Sorting(templist);
  
   EXPECT_EQ(templist.at(0).getDay(), 3);
  EXPECT_EQ(templist.at(0).getCategory(), "Personal"); 
}

TEST(categoryOrder, sortSCHOOL){ 
  vector<Task> templist;
  
  Task t1 =  Task();
  t1.setName("Hist HW");
  t1.setCategory("School");
  t1.setMonth(6);
  t1.setDay(10);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("CS HW");
  t2.setCategory("Personal");
  t2.setMonth(6);
  t2.setDay(2);
  t2.setYear(2021);
  templist.push_back(t2);
 
  Task t3 = Task();
  t3.setName("Math HW");
  t3.setCategory("Personal");
  t3.setMonth(6);
  t3.setDay(3);
  t3.setYear(2021);
  templist.push_back(t3);
  
   // category = 1;
  SortCategory sort;
  sort.Sorting(templist);
   EXPECT_EQ(templist.at(0).getDay(), 10);
  EXPECT_EQ(templist.at(0).getCategory(), "School"); 
}

#endif
