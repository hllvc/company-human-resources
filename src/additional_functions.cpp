// include
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

// include custom
#include "../include/additional_functions.h"

#define JMBG_SIZE 13

// function for string input without digits
std::string * string_input() {
	std::string * const str_ptr = new std::string();
	std::cin >> *str_ptr;
	is_digit(str_ptr);
	return str_ptr;
}

// function for JMBG input
std::string * jmbg_input() {
	std::string * const str_ptr = new std::string();
	std::cin >> *str_ptr;
	if (str_ptr->empty())
		throw "empty";
	else if (str_ptr->size() != JMBG_SIZE)
		throw "size error";
	else
		is_digit(str_ptr);
	return str_ptr;
}

// function for checking if string contains digits
void is_digit(std::string const * const str_ptr) {
	std::for_each(str_ptr->begin(), str_ptr->end(), [](const char& c){
	if (std::isdigit(c))
		throw "is digit";
		});
}
