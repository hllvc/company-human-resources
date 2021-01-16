// include 
#include <iterator>
#include <string>
#include <iostream>

// include custom
#include "../include/documents.h"


// methods definitions
void documents_t::append_document(const document_t& document) {
	this->documents_["DOC" + std::to_string(this->getDoc_num())] = document;
}

void documents_t::list_all_documents(std::ostream& output) const {
	for (const_doc_it it = this->documents_.begin(); it != this->documents_.end(); std::advance(it, 1)) {
		output << it->first << std::endl;
		it->second.print_attributes(output);
	}
}

const int documents_t::getDoc_num() {
	this->doc_num_++;
	return this->doc_num_-1;
}

void documents_t::clear_all_documents() {
	this->documents_.clear();
}
