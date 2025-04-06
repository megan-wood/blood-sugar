//
// Created by Megan on 3/28/23.
//
#include <iostream>
#include <vector>
#include "Entry.h"
#include "number_ave.h"
#include "input_validation.h"

void calculate_number_ave(const std::vector<Entry>& entries) {
  int ave = 0, sum = 0;
  int days = get_valid_int("Please enter the number of days to calculate the average for: ");
  while (days > entries.size() || days < 1) {
    if (days > entries.size()) {
      std::cout << "The number of days you entered was too big. Please enter a number less than " << entries.size() << "." << std::endl;
    } else {
      std::cout << "The number of days you entered was too small (less than 1). Please enter a number greater than 0 and less than " << entries.size() << "." << std::endl;
    }
    days = get_valid_int("Please enter the number of days to calculate the average for: ");
  }
  for (int day = static_cast<int>(entries.size()) - 1; day >= static_cast<int>(entries.size()) - days; --day) {
    sum = sum + entries.at(day).get_value();
  }
  ave = sum / days;
  //std::cout << "Sum: " << sum << std::endl;
  std::cout << "The average for the last " << days << " days is " << ave << "." << std::endl;
}