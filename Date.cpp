//
// Created by Megan on 3/27/23.
//
#include <string>
#include <sstream>
#include "Date.h"

Date::Date(std::string date) {
  std::string month_string, day_string, year_string;  // 5/2/20 5/20/20 12/2/20 12/20/20
  std::stringstream stream(date);
  getline(stream, month_string, '/');
  getline(stream, day_string, '/');
  getline(stream, year_string, '/');
  month = std::stoi(month_string);
  day = std::stoi(day_string);
  year = std::stoi(year_string);
}

bool Date::operator==(const Date& rhs) {
  if (month != rhs.month) {
    return false;
  }
  if (day != rhs.day) {
    return false;
  }
  if (year != rhs.year) {
    return false;
  }
  return true;
}

Date::operator const std::string&() const {
  return std::to_string(month) + '/' + std::to_string(day) + '/' + std::to_string(year);
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date.month << '/' << date.day << '/' << date.year;
  return os;
}