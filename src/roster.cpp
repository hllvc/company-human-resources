// include
#include <string>
#include <map>
#include <algorithm>

// include custom
#include "../include/roster.h"

// methods definitions
void roster_t::append_employee(const employee_t& employee, const std::string& jmbg) {
	this->roster_[jmbg] = employee;
}

void roster_t::delete_employee(const std::string& jmbg) {
	if (this->roster_.empty())
		throw "empty";
	roster_it employee = this->roster_.find(jmbg);
	if (employee != this->roster_.end())
		employee = roster_.erase(employee);
	else
		throw "not found";
}

const_roster_it roster_t::find_employee(const std::string& jmbg) const {
	return this->roster_.find(jmbg);
}
