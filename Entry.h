//
// Created by Megan on 3/27/23.
//

#ifndef BLOODSUGARPROGRAM__ENTRY_H_
#define BLOODSUGARPROGRAM__ENTRY_H_
#include "Date.h"
#include <utility>
class Entry {
 public:
  //Entry(std::pair<Date, int> entry_pair) : entry(entry_pair) {};
  Entry(std::string date, int bsl);
  Date get_date() const;
  int get_value() const;
 private:
  std::pair<Date, int> entry;
//  Date date_of_entry;
//  int level;
};

#endif //BLOODSUGARPROGRAM__ENTRY_H_
