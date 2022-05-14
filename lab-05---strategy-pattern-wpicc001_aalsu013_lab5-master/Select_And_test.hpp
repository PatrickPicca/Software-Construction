#ifndef __SELECT_AND_TEST_HPP__
#define __SELECT_AND_TEST_HPP__

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "select_and.hpp"

TEST(SelectAndTest, AndWithNothingSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});

	testsheet.set_selection(new Select_And(new Select_Contains(&testsheet, "Last", "Billy"), new Select_Contains(&testsheet, "Last", "Hailey")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "");
}

TEST(SelectAndTest, AndWithOneSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "30", "News"});
	testsheet.add_row({"Jerry", "Jones", "35", "Soccer"});

	testsheet.set_selection(new Select_And(new Select_Contains(&testsheet, "Last", "Jones"), new Select_Contains(&testsheet, "Age", "30")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Bob Jones 30 business \n");
}

TEST(SelectAndTest, AndWithTwoSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});
	testsheet.add_row({"Jeyy", "Jones", "40", "News"});

	testsheet.set_selection(new Select_And(new Select_Contains(&testsheet, "Age", "40"), new Select_Contains(&testsheet, "Major", "News")));
 
	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Ron Otterman 40 News \nJeyy Jones 40 News \n");
}


#endif
