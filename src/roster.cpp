// include
#include <string>
#include <map>
#include <algorithm>

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
 void roster_t::print_employee(const_roster_it employee) const {
	 employee->second.print_attributes();
}

bool roster_t::empty() const {
	return this->roster_.empty();
}
