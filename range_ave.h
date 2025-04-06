//
// Created by Megan on 3/28/23.
//

#ifndef BLOODSUGARPROGRAM__RANGE_AVE_H_
#define BLOODSUGARPROGRAM__RANGE_AVE_H_
#include "Entry.h"
#include "Date.h"
void calculate_range_ave(const std::vector<Entry>& entries);
int get_index_for_date(const std::vector<Entry>& entries, const std::string& date);
#endif //BLOODSUGARPROGRAM__RANGE_AVE_H_
