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
	std::string * const input = new std::string();
	while (true) {
		std::cout << "Enter " << field << ": ";
		std::cin >> *input;
		try {
			is_digit(input);
			return input;
		} catch (const char * e) {
			if (e == std::string("is digit"))
				std::cout << field << " cannot contain digits!\n";
		}
	}
}

// function for JMBG input
std::string * const jmbg_input(const bool existence) {
	std::string * const jmbg = new std::string();
	while (true) {
		std::cout << "Enter JMBG: ";
		std::cin >> *jmbg;
		try {
			check_jmbg_input(*jmbg, existence);
			return jmbg;
		} catch (const char * e) {
			if (e == std::string("exists"))
				std::cout << "Employee with given JMBG already exists!\n";
			else if (e == std::string("empty"))
				std::cout << "JMBG can't be empty!\n";
			else if (e == std::string("size error"))
				std::cout << "Size of JMBG must be 13!\n";
			else if (e == std::string("not digit"))
				std::cout << "JMBG can only contain digits!\n";
		}
	}
}

// function for correct JMBG format
void check_jmbg_input(const std::string& jmbg, const bool existence) {
	if (existence && roster.check_existing_jmbg(jmbg))
		throw "exists";
	else if (jmbg.empty())
		throw "empty";
	else if (jmbg.size() != JMBG_SIZE)
		throw "size error";
	else
		is_not_digit(&jmbg);
}

// function for checking if string contains digits
void is_digit(std::string const * const input) {
	std::for_each(input->begin(), input->end(), [](const char& c){
	if (std::isdigit(c))
		throw "is digit";
		});
}

// function for checking if string does not contain digits
void is_not_digit(std::string const * const input) {
	std::for_each(input->begin(), input->end(), [](const char& c){
	if (!std::isdigit(c))
		throw "not digit";
		});
}
// function to find employee by JMBG
const_roster_it find_employee_by_jmbg(const std::string& jmbg) {
	const_roster_it employee;
	try {
		employee = roster.find_employee(jmbg);
	} catch (const char * e) {
		if (e == std::string("empty"))
			std::cout << "Employee list empty!\n";
	}
	return employee;
}
