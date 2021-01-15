// include guard
#ifndef __DOCUMENTS_H__
#define	__DOCUMENTS_H__

// include
#include <string>
#include <map>

// include custom
#include "document.h"

// custom types
typedef std::map<std::string, document_t>::const_iterator const_doc_it;
typedef std::map<std::string, document_t> doc_map;

class documents_t {
	private:

		// documents_t attributes
		doc_map documents_;

	public:
		// methods
		void append_document(const document_t&);
		void list_all_documents() const;

};

#endif // __DOCUMENTS_H__
