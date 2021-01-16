// include
#include <iterator>
#include <ostream>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>

// include custom
#include "../include/roster.h"

// methods definitions
void roster_t::append_employee(const std::string& jmbg, const employee_t& employee) {
	this->roster_[jmbg] = employee;
}

void roster_t::delete_employee(const_roster_it employee) {
	employee = this->roster_.erase(employee);
}

const_roster_it roster_t::find_employee(const std::string& jmbg) const {
	const_roster_it employee = this->roster_.find(jmbg);
	if (employee != this->roster_.end())
		return employee;
	else
		throw "not found";
}

bool roster_t::check_existing_jmbg(const std::string& jmbg) const {
	if (this->roster_.find(jmbg) != this->roster_.end())
		return true;
	else 
		return false;
}

void roster_t::print_employee(const employee_t& employee) const {
	employee.print_employee(std::cout);
}

void roster_t::print_all_employees(std::ostream& output) const {
	for (const_roster_it it = this->roster_.begin(); it != this->roster_.end(); std::advance(it, 1)) {
		output << "JMBG: " << it->first << std::endl;
		it->second.print_employee(output);
		output << std::endl;
	}
}

bool roster_t::empty() const {
	return this->roster_.empty();
}
