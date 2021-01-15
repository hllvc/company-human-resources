// include guard
#ifndef __ADDITIONAL_FUNCTIONS_H__
#define __ADDITIONAL_FUNCTIONS_H__

// include
#include <string>

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
char yes_no(const std::string& text);

// templates

#endif // __ADDITIONAL_FUNCTIONS_H__
