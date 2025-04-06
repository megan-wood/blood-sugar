//
// Created by Megan on 3/28/23.
//
#include <iostream>
#include <vector>
#include <string>
#include "Entry.h"
#include "Date.h"
#include "input_validation.h"
#include "range_ave.h"

void calculate_range_ave(const std::vector<Entry>& entries) {
  double ave = 0;
  int sum = 0, days = 0;
  std::string start = get_valid_date_range("Please enter a start date for the range date: ", entries);
  std::string end = get_valid_date_range("Please enter a end date for the range date: ", entries);
  int index_for_start = get_index_for_date(entries, start);
  int index_for_end = get_index_for_date(entries, end);
  for (int i = index_for_start; i < index_for_end + 1; ++i) {
    sum = sum + entries.at(i).get_value();
    days++;
  }
  ave = sum / days;
//  std::cout << "Sum: " << sum << std::endl;
  std::cout << "The average from " << start << " to " << end << " (" << days << " days) is " << ave << "." << std::endl;
}

int get_index_for_date(const std::vector<Entry>& entries, const std::string& date) {
  Date date_string(date);
  for (int i = 0; i < entries.size(); ++i) {
    if (date_string == entries.at(i).get_date()) {
      return i;
    }
  }
}