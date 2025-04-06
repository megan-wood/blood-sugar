//
// Created by Megan on 3/27/23.
//
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "input_validation.h"
#include "Entry.h"

std::string get_valid_string(const std::string& prompt) {
  std::string line;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    std::string word;
    line2parse >> word;
    if (line2parse) { //if I was able to read the string
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse && valid_file_format(word)) { //if there is nothing left we will fail to read it
        return word;
      }
    }
  }
}

bool valid_file_format(const std::string& filename) {  // data2.csv
  int index = filename.length();
  if (filename.at(index - 4) == '.' && filename.at(index - 3) == 'c' && filename.at(index - 2) == 's' && filename.at(index - 1) == 'v') {
    return true;
  }
  return false;
}

char get_valid_char(const std::string& prompt) {
  // Adapted from class code on the Google Drive
  std::string line;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    char character;
    line2parse >> character;
    if (line2parse) { //if I was able to read the character
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse && (character == 'r' || character == 'n' || character == 'y')) { //if there is nothing left we will fail to read it
        return character;
      }
    }
  }
}

int get_valid_int(const std::string& prompt) {
  // Taken from class code on the Google Drive
  std::string line;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line); //grabs the entire line
    std::stringstream line2parse(line);
    int num;
    line2parse >> num;
    if (line2parse) { //if I was able to read the number
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse) { //if there is nothing left we will fail to read it
        return num;
      }
    }
  }
}

std::string get_valid_date_range(const std::string& prompt, const std::vector<Entry>& entries) {
  std::string line;
  while (true) {
    std::cout << prompt;
    std::getline(std::cin, line);
    std::stringstream line2parse(line);
    std::string date;
    line2parse >> date;
    if (line2parse) {
      std::string what_is_left;
      line2parse >> what_is_left;
      if (not line2parse && valid_format(date) && date_in_range(date, entries)) {
        return date;
      }
    }
  }
}

bool valid_format(const std::string& date) {
  int count = 0;
  for (int i = 0; i < date.size(); ++i) {
    if (date.at(i) == '/') {
      count++;
    }
  }
  if (count == 2) {
    return true;
  }
  std::cout << "The date was not in the correct format. Please enter in dd/mm/yy format." << std::endl;
  return false;
}

bool date_in_range(const std::string& date, const std::vector<Entry>& entries) {
  Date date_obj(date);
  for (auto entry : entries) {
    if (date_obj == entry.get_date()) {
      return true;
    }
  }
  std::cout << "This date is not in the range. Please enter in dd/mm/yy format and a date in the range of " << entries.at(0).get_date() << " and " << entries.at(entries.size() - 1).get_date() << '.' << std::endl;
  return false;
}