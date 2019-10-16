#include <iostream>
#include "Date.h"

// month, date, year
void Date::set(int m, int d, int y)
{
  month = m;
  day = d;
  year = y;
}

// date stored in the object
void Date::print()
{
  std::cout << "MONTH: " << month
            << ", DAY: " << day
            << ", YEAR: " << year << std::endl;
}

// return respectively the month, the day and the year stored in a Date object
inline const int Date::get_month()
{
  return month;
}

inline const int Date::get_day()
{
  return day;
}

inline const int Date::get_year()
{
  return year;
}
