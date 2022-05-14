#ifndef __SORTNAME_TEST_HPP__
#define __SORTNAME_TEST_HPP__

#include "gtest/gtest.h"

#include "SortName.cpp"
//#include "task.cpp"
#include "task.hpp"
#include <string>
#include <vector>


TEST(nameOrder, simpleTest){ 
  vector<Task> templist;
  
  Task t1 =  Task();
  t1.setName("Bio HW");
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
  
  SortName sort;
  sort.Sorting(templist);


  EXPECT_EQ(templist.at(0).getName(), "Bio HW");
}

TEST(nameOrder, IncompleteTaskname1){
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("d");
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("CS HW");
  t2.setMonth(6);
  t2.setDay(20);
  t2.setYear(2021);
  templist.push_back(t2);
  
  SortName sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(1).getName(), "d");
}

 
TEST(nameOrder, IncompleteTaskname2){
  vector<Task> templist;  
  Task t1 = Task();
  t1.setName("Geo HW");
  t1.setMonth(6);
  t1.setDay(5);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("zo");
  templist.push_back(t2);
  
  SortName sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(0).getName(), "Geo HW");
}

TEST(nameOrder, sameName){ 
  vector<Task> templist;
  
  Task t1 =  Task();
  t1.setName("CS HW");
  t1.setMonth(6);
  t1.setDay(5);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("CS HW");
  t2.setMonth(6);
  t2.setDay(5);
  t2.setYear(2021);
  templist.push_back(t2);
  
  SortName sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(0).getName(), "CS HW");
  EXPECT_EQ(templist.at(0).getDay(), 5);      
}

TEST(nameOrder, sameName2){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("ENG HW");
  t1.setMonth(6);
  t1.setDay(20);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("ENG HW");
  t2.setMonth(6);
  t2.setDay(21);
  t2.setYear(2021);
  templist.push_back(t2);
  
  Task t3 = Task();
  t3.setName("ENG HW");
  t3.setMonth(6);
  t3.setDay(2);
  t3.setYear(2021);
  templist.push_back(t3);
 
  SortName sort;
  sort.Sorting(templist);
 
  EXPECT_EQ(templist.at(0).getName(), "ENG HW");
  EXPECT_EQ(templist.at(0).getDay(), 20); 
}

TEST(nameOrder, ABC){  
  vector<Task> templist;
  
  Task t1 =  Task();
  t1.setName("B");
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("A");
  templist.push_back(t2);
  
  Task t3 =  Task();
  t3.setName("C");
  templist.push_back(t3);
 
  SortName sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(0).getName(), "A"); 
}

TEST(nameOrder, notSortedTest){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Hist HW");
  t1.setMonth(6);
  t1.setDay(1);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 = Task();
  t2.setName("Aero HW");
  t2.setMonth(6);
  t2.setDay(2);
  t2.setYear(2021);
  templist.push_back(t2);
  
  Task t3 = Task();
  t3.setName("Math HW");
  t3.setMonth(6);
  t3.setDay(3);
  t3.setYear(2021);
  templist.push_back(t3);
  
//  SortName *sort;
//  sort->Sorting(templist);

  EXPECT_EQ(templist.at(0).getName(), "Hist HW");
}

TEST(nameOrder, sortNames2){ 
  vector<Task> templist;
  
  Task t1 = Task();
  t1.setName("Astrology HW");
  t1.setMonth(6);
  t1.setDay(1);
  t1.setYear(2021);
  templist.push_back(t1);

  Task t2 =  Task();
  t2.setName("Accounting HW");
  t2.setMonth(6);
  t2.setDay(2);
  t2.setYear(2021);
  templist.push_back(t2);
  
  Task t3 =  Task();
  t3.setName("Aerospace HW");
  t3.setMonth(6);
  t3.setDay(3);
  t3.setYear(2021);
  templist.push_back(t3);
  
  SortName sort;
  sort.Sorting(templist);

  EXPECT_EQ(templist.at(0).getName(), "Astrology HW"); // don't check for 2nd letter so first task should be at front
}
#endif
