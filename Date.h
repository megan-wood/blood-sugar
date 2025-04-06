//
// Created by Megan on 3/27/23.
//

#ifndef BLOODSUGARPROGRAM__DATE_H_
#define BLOODSUGARPROGRAM__DATE_H_
#include <string>
#include <iostream>
class Date {
 public:
  Date(int entry_month, int entry_day, int entry_year) : month(entry_month), day(entry_day), year(entry_year) {};
  Date(std::string date);
  Date() : month(1), day(1), year(2023) {};
  bool operator==(const Date& rhs);
  operator const std::string&() const;
  friend std::ostream& operator<<(std::ostream& os, const Date& date);
 private:
  int month, day, year;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif //BLOODSUGARPROGRAM__DATE_H_
