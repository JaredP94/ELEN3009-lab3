// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date(int day, Month month, int year):
	_day{day},
	_month{month},
	_year{year}
	{
		if (_day < 1 || _day > daysInMonth()) throw InvalidDay();
		if (daysInMonth() == false) throw InvalidMonth();
		if (_year < 0) throw InvalidYear();
	}

Date::Date():
	_day{_default.day()},
	_month{_default.month()},
	_year{_default.year()}
	{}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

bool Date::operator==(const Date& rhs) const
{
	Date lhs = Date(_day, _month, _year);
	if (lhs._day == rhs._day && lhs._month == rhs._month && lhs._year == rhs._year) return true;
	return false;
 }
 
void Date::incrementDay()
 {
	int month_integer = static_cast<int>(_month);
	if (_day == daysInMonth() && month_integer == 12){
		_day = 1;
		month_integer = 1;
		_year++;
	}
	else if (_day == daysInMonth()){
		_day = 1;
		month_integer++;
	}
	else _day++;
	_month = static_cast<Month>(month_integer);
}

void Date::setDefaultDate(int day, Month month, int year)
{
	_default = Date(day, month, year);
}

Date Date::_default{14, Month::June, 1994};