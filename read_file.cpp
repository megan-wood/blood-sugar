#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Entry.h"

std::vector<Entry> read_file(std::ifstream& file) {
  std::vector<Entry> entries;
  //std::stringstream file_stream(file);
  std::string line;
  std::string date, bsl;
  std::getline(file, line, '\r');
  while(!file.eof()) {
    std::getline(file, line, '\r');
    //std::string date, bsl;
    std::stringstream stream(line);
//    getline(stream, date, ',');
//    getline(stream, bsl);
    getline(stream, date, ',');
    getline(stream, bsl, ',');
    entries.push_back(Entry(date, std::stoi(bsl)));
  }
  return entries;
}