// include guard
#ifndef __ADDITIONAL_FUNCTIONS_H__
#define __ADDITIONAL_FUNCTIONS_H__

// include
#include <string>

// include custom
#include "employee.h"
#include "roster.h"

// main functions
const std::string * const jmbg_input();
const std::string * const string_input(const std::string&);
const_roster_it find_employee_by_jmbg(const std::string& jmbg);

// sub_main functions
const std::string * const check_jmbg_input();
const std::string * const check_string_input();

// auxiliary functions
void is_digit(std::string const * const);
void is_not_digit(std::string const * const);


#endif // __ADDITIONAL_FUNCTIONS_H__
