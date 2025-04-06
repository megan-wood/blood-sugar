//
// Created by Megan on 3/27/23.
//

#ifndef BLOODSUGARPROGRAM__INPUT_VALIDATION_H_
#define BLOODSUGARPROGRAM__INPUT_VALIDATION_H_
#include <string>
#include "Entry.h"
std::string get_valid_string(const std::string& prompt);
bool valid_file_format(const std::string& filename);
char get_valid_char(const std::string& prompt);
int get_valid_int(const std::string& prompt);
std::string get_valid_date_range(const std::string& prompt, const std::vector<Entry>& entries);
bool valid_format(const std::string& date);
bool date_in_range (const std::string& date, const std::vector<Entry>& entries);
#endif //BLOODSUGARPROGRAM__INPUT_VALIDATION_H_
