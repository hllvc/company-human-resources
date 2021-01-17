// include guard
#ifndef __ADDITIONAL_FUNCTIONS_H__
#define __ADDITIONAL_FUNCTIONS_H__

// include
#include <string>
#include <vector>

// include custom
#include "employee.h"
#include "roster.h"
#include "document.h"
#include "documents.h"

// main functions
const std::string * const string_input(const std::string&);
const std::string * const jmbg_input(const bool);
const documents_t  * const documents_input();

// auxiliary functions
void check_jmbg_input(const std::string&, const bool);
void is_digit(std::string const * const);
void is_not_digit(std::string const * const);
void delete_employee_by_jmbg(const std::string&);
void find_employee_by_jmbg(const std::string&);
void update_employee_by_jmbg(const std::string&);
bool change_field(const std::string&);
const char yes_no(const std::string&);

// data functions
void write_data();
void read_data();
const std::string * const get_path();
std::vector<std::string> split_input(std::string&);
bool check_field(std::string&);

// templates

#endif // __ADDITIONAL_FUNCTIONS_H__
