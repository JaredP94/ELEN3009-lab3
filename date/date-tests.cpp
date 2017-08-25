#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
/*TEST_CASE("Date has uninitialised state") {	 
    // make some prior memory allocations - which will be the case in a typical program
    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
    auto i2 = 1.0;
    
    Date today;	
    std::cout << "Today is: " << endl;
    printDate(today);
}*/

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.

TEST_CASE("If Invalid Day Throws Exception") {
	CHECK_THROWS_AS({Date false_day1(0, Month::September, 2000);}, InvalidDay);
	CHECK_THROWS_AS({Date false_day2(45, Month::September, 2000);}, InvalidDay);
}

//TEST_CASE("If Invalid Month Throws Exception") {
//	CHECK_THROWS_AS({Date false_month(24, Month::Thursday, 2000);}, InvalidMonth); //Note: This error can't be handled as the compiler will check if the value exists within the Month enum class before building.
//}

TEST_CASE("If Negative Year Throws Exception") {
	CHECK_THROWS_AS({Date false_year(24, Month::September, -5000);}, InvalidYear);
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.

TEST_CASE("Date Is Not Equivalent To A Date With Different Day") {
    Date date_1(1, Month::January, 2000);
    Date date_2(15, Month::January, 2000);
    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Date Is Not Equivalent To A Date With Different Month") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::February, 2000);
    CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Date Is Not Equivalent To A Date With Different Years") {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 1498);
    CHECK_FALSE(date_1 == date_2);
}

// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.

TEST_CASE("Date Is Equivalent To Single Day Increment") {
    Date date_1(15, Month::June, 2000);
	date_1.incrementDay();
    Date date_2(16, Month::June, 2000);
    CHECK(date_1 == date_2);
}

TEST_CASE("Date Is Equivalent To Day Increment Causing Month Increment") {
    Date date_1(30, Month::June, 2000);
	date_1.incrementDay();
    Date date_2(1, Month::July, 2000);
    CHECK(date_1 == date_2);
}

TEST_CASE("Date Is Equivalent To Day Increment Causing Year Increment") {
    Date date_1(31, Month::December, 2000);
	date_1.incrementDay();
    Date date_2(1, Month::January, 2001);
    CHECK(date_1 == date_2);
}

// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
