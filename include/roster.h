// include guard
#ifndef __ROSTER_H__
#define __ROSTER_H__

// include
#include <map>
#include <string>

// include custom
#include "employee.h"

class roster_t {
	private:
		
		// roster_t attributes
		std::map<std::string, employee_t> roster_;

	public:

		// methods
		void append_employee(const employee_t& employee, const std::string& jmbg);
		void delete_employee(const std::string& jmbg);
};

#endif // __ROSTER_H__
