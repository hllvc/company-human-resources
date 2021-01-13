// include
#include <string>

// include custom
#include "../include/employee.h"

employee_t::employee_t() {}
employee_t::employee_t(const std::string& name, const std::string& surname) : name_(name), surname_(surname) {}

// setters definition
void employee_t::setName(const std::string& name) {
	this->name_ = name;
}

void employee_t::setSurname(const std::string& surname) {
	this->surname_ = surname;
}

// getters inline in header
