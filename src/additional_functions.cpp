// include
#include <algorithm>
#include <string>
#include <cctype>
#include <iostream>

// include custom
#include "../include/additional_functions.h"

extern roster_t roster;

#define JMBG_SIZE 13

// function for custom string input
const std::string * const string_input(const std::string& field) {
	while (true) {
		try {
			std::cout << "Enter " << field << ": ";
			const std::string * const input = check_string_input();
			return input;
		} catch (const char * e) {
			if (e == std::string("is digit"))
				std::cout << field << " cannot contain digits!\n";
		}
	}
}

// function for JMBG input
const std::string * const jmbg_input() {
	while (true) {
		try {
			std::cout << "Enter JMBG: ";
			const std::string * const jmbg = check_jmbg_input();
			return jmbg;
		} catch (const char * e) {
			if (e == std::string("empty"))
				std::cout << "JMBG can't be empty!\n";
			else if (e == std::string("size error"))
				std::cout << "Size of JMBG must be 13!\n";
			else if (e == std::string("not digit"))
				std::cout << "JMBG can only contain digits!\n";
		}
	}
}

// function for string input without digits
const std::string * const check_string_input() {
	std::string * const str_ptr = new std::string();
	std::cin >> *str_ptr;
	is_digit(str_ptr);
	return str_ptr;
}

// function for correct JMBG format
const std::string * const check_jmbg_input() {
	std::string * const str_ptr = new std::string();
	std::cin >> *str_ptr;
	if (str_ptr->empty())
		throw "empty";
	else if (str_ptr->size() != JMBG_SIZE)
		throw "size error";
	else
		is_not_digit(str_ptr);
	return str_ptr;
}

// function for checking if string contains digits
void is_digit(std::string const * const str_ptr) {
	std::for_each(str_ptr->begin(), str_ptr->end(), [](const char& c){
	if (std::isdigit(c))
		throw "is digit";
		});
}

// function for checking if string does not contain digits
void is_not_digit(std::string const * const str_ptr) {
	std::for_each(str_ptr->begin(), str_ptr->end(), [](const char& c){
	if (!std::isdigit(c))
		throw "not digit";
		});
}

// function to find employee by JMBG
const_roster_it find_employee_by_jmbg(const std::string& jmbg) {
	try {
		const_roster_it employee = roster.find_employee(jmbg);
		return employee;
	} catch (const char * e) {
		if (e == std::string("empty")) {
			std::cout << "There is no registered employees!\n";
		}
		else if (e == std::string("not found")) {
			std::cout << "Employee not found!\n";
		}
		throw "error";
	}
}
