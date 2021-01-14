// include guard
#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__

// include
#include <string>

class document_t {
	private:
		std::string name_;
		std::string type_;
		std::string description_;
	
	public:

		// constructors
		document_t(const std::string&, const std::string&, const std::string&);

		// setters
		void setName(const std::string&);
		void setType(const std::string&);
		void setDescription(const std::string&);

		// getters
		std::string getName() const { return this->name_; }
		std::string getType() const { return this->type_; }
		std::string getDescription() const { return this->description_; }

};

#endif // __DOCUMENT_H__
