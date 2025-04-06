//
// Created by Megan on 3/27/23.
//
#include <string>
#include <sstream>
#include <utility>
#include "Entry.h"
#include "Date.h"

Entry::Entry(std::string date, int bsl) {
//  std::string month, day, year;  // 5/2/20 5/20/20 12/2/20 12/20/20
//  std::stringstream stream(date);
//  getline(stream, month, '/');
//  getline(stream, day, '/');
//  getline(stream, year, '/');
//  int month_int = std::stoi(month);
//  int day_int = std::stoi(day);
//  int year_int = std::stoi(year);
//  Date entry_date(month_int, day_int, year_int);
  Date entry_date(date);
  //std::pair<Date, int> entry_pair(entry_date, bsl);
  //entry = entry_pair;
  entry = std::make_pair(entry_date, bsl);
//  if (date.at(1) == '/') {
//    month = date.at(0);
//  } else if (date.at(2) == '/') {
//    std::string month_string;
//    month_string.push_back(date.at(0));
//    month_string.push_back(date.at(1));
//    month = std::stoi(month_string);
//  }
//  if (date.at())
};

Date Entry::get_date() const {
  return entry.first;
}

int Entry::get_value() const {
  return entry.second;
}

