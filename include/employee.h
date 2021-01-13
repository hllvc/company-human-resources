// include guard
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

// include
#include <string>

class employee_t {
	private:

		// employee_t attributes
		std::string name_;
		std::string surname_;

	public:

		// constructors
		employee_t(std::string name, std::string surname) : name_(name), surname_(surname) {}

		// setters
		void setName(std::string name);
		void setSurname(std::string surname);

		// getters (inline)
		std::string getName() const { return name_; }
		std::string getSurname() const { return surname_; }
};

#endif // __EMPLOYEE_H__
