#ifndef __SELECT_OR_TEST_HPP__
#define __SELECT_OR_TEST_HPP__

#include "gtest/gtest.h"
#include "spreadsheet.hpp"
#include "Select_Contains.hpp"
#include "select_or.hpp"

TEST(SelectOrTest, OrWithNothingSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});

	testsheet.set_selection(new Select_Or(new Select_Contains(&testsheet, "Age", "50"), new Select_Contains(&testsheet, "Last", "Hailey")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "");
}

TEST(SelectOrTest, OrWithOneSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "30", "News"});
	testsheet.add_row({"Jerry", "Jones", "35", "Soccer"});

	testsheet.set_selection(new Select_Or(new Select_Contains(&testsheet, "Last", "Otterman"), new Select_Contains(&testsheet, "Age", "50")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Ron Otterman 30 News \n");
}

TEST(SelectOrTest, OrWithTwoSharedTest) {

	Spreadsheet testsheet;
	testsheet.set_column_names({"First", "Last", "Age", "Major"});
	testsheet.add_row({"Bob", "Jones", "30", "business"});
	testsheet.add_row({"Ron", "Otterman", "40", "News"});
	testsheet.add_row({"Jeyy", "Jones", "40", "News"});

	testsheet.set_selection(new Select_Or(new Select_Contains(&testsheet, "Age", "30"), new Select_Contains(&testsheet, "Last", "Otterman")));

	std::stringstream out;
	testsheet.print_selection(out);
	EXPECT_EQ(out.str(), "Bob Jones 30 business \nRon Otterman 40 News \n");
}


#endif
