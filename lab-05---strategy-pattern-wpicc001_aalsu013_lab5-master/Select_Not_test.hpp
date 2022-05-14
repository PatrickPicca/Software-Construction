#ifndef __SELECT_NOT_TEST_HPP__
#define __SELECT_NOT_TEST_HPP__

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "Select_Not.hpp"

TEST(SelectNotTest, basicNotTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});

	testsheet.set_selection(new Select_Not(new Select_Contains(&testsheet, "Last", "Jones")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Ron Otterman 40 News \n");
}

TEST(SelectNotTest, NotMoreObjectsTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});
	testsheet.add_row({"Jerry", "Jones", "45", "Soccer"});

	testsheet.set_selection(new Select_Not(new Select_Contains(&testsheet, "Last", "Jones")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Ron Otterman 40 News \n");
}

TEST(SelectNotTest, NotNothingSelectedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});

	testsheet.set_selection(new Select_Not(new Select_Contains(&testsheet, "First", "Robert")));
 
	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Bob Jones 30 business \nRon Otterman 40 News \n");
}


#endif
