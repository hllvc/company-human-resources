// include
#include <string>
#include <iostream>

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

void employee_t::setDocuments(const documents_t& documents) {
	this->documents_ = documents;
}

// getters inline in header

// additional attributes
void employee_t::print_attributes() const {
	std::cout << getName() << " " << getSurname();
}

void employee_t::print_documents() const {
	this->documents_.list_all_documents();
}
