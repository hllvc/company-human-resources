// include
#include <ostream>
#include <string>
#include <iostream>

// include custom
#include "../include/employee.h"

employee_t::employee_t() {}
employee_t::employee_t(const std::string& name, const std::string& surname, const std::string& department) : name_(name), surname_(surname), department_(department) {}

// setters definition
void employee_t::setName(const std::string& name) {
	this->name_ = name;
}

void employee_t::setSurname(const std::string& surname) {
	this->surname_ = surname;
}

void employee_t::setDepartment(const std::string& department) {
	this->department_ = department;
}

void employee_t::setDocuments(const documents_t& documents) {
	this->documents_ = documents;
}

// getters inline in header

void employee_t::print_employee(std::ostream& output) const {
	output << "Name: ";
	output << this->name_ << std::endl;
	output << "Surname: ";
	output << this->surname_ << std::endl;
	output << "Department: ";
	output << this->department_ << std::endl;
	this->documents_.list_all_documents(output);
}
