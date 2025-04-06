#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "input_validation.h"
#include "read_file.h"
#include "Entry.h"
#include "range_ave.h"
#include "number_ave.h"

int main(int argc, char* argv[]) {
  std::string filename = get_valid_string("Enter the file name for the data: ");
//  std::cout << "Input File: " << filename << std::endl;
  std::ifstream file(filename);
  //std::istream istream_file(file);
  if (file.is_open()) {
    std::vector<Entry> entries = read_file(file);
    char redo, command;
    do {
      do {
        command = get_valid_char("Do you want an average for a range of dates (r) or an average for the last number of days (n): ");
      } while (command == 'y');
      if (command == 'r') {
        calculate_range_ave(entries);
      } else if (command == 'n') {
        calculate_number_ave(entries);
      }
      redo = get_valid_char("Do you want to calculate another average? Type 'y' for yes or 'n' for no: ");
    } while (redo == 'y');
  } else {
    std::string filename = get_valid_string("Enter the file name for the data: ");
  }
  return 0;
}
