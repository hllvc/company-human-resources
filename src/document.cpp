// include
#include <string>

#include "../include/document.h"

// constructors
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

// getter defined in headaer
