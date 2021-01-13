// include
#include <string>
#include <map>
#include <algorithm>

// include custom
#include "../include/roster.h"

// custom types
typedef std::map<std::string, employee_t>::iterator roster_it;
typedef std::map<std::string, employee_t>::const_iterator const_roster_it;

// methods definitions
void roster_t::append_employee(const employee_t& employee, const std::string& jmbg) {
	this->roster_[jmbg] = employee;
}
void roster_t::delete_employee(const std::string& jmbg) {
	if (this->roster_.empty())
		throw "empty";
	roster_it employee = std::find(this->roster_.begin(), this->roster_.end(), jmbg);
	if (employee == this->roster_.end())
		throw "not found";
	else
		employee = roster_.erase(employee);
}
