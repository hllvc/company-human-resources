// include
#include <ostream>
#include <string>
#include <iostream>

// include custom
#include "../include/document.h"

// constructors
document_t::document_t() {};
document_t::document_t(const std::string& name, const std::string& type, const std::string& description) : name_(name), type_(type), description_(description) {}

// setters
void document_t::setName(const std::string& name) {
	this->name_ = name;
}

void document_t::setType(const std::string& type) {
	this->type_ = type;
}

void document_t::setDescription(const std::string& description) {
	this->description_ = description;
}

// getters defined in headaer

// methods

void document_t::print_attributes(std::ostream& output) const {
	output << "Document name: " << this->name_ << std::endl;
	output << "Type: " << this->type_ << std::endl;
	output << "Description: " << this->description_ << std::endl;
}
