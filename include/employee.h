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
		employee_t();
		employee_t(const std::string& name, const std::string& surname);

		// setters
		void setName(const std::string& name);
		void setSurname(const std::string& surname);

		// getters (inline)
		std::string getName() const { return name_; }
		std::string getSurname() const { return surname_; }

		// additional methods 
		void print_attributes() const;
};

#endif // __EMPLOYEE_H__
