// include 
#include <string>

// include custom
#include "../include/documents.h"

// methods definitions
void documents_t::append_document(const std::string& key, const document_t& document) {
	this->documents_[key] = document;
}
