// include 
#include <iterator>
#include <string>

// include custom
#include "../include/documents.h"

// methods definitions
void documents_t::append_document(const document_t& document) {
	static unsigned long doc_number;
	this->documents_["DOC"+std::to_string(doc_number)] = document;
	doc_number++;
}

void documents_t::list_all_documents() const {
	for (const_doc_it it = this->documents_.begin(); it != this->documents_.end(); std::advance(it, 1))
		it->second.print_attributes();
}
