// include guard
#ifndef __ROSTER_H__
#define __ROSTER_H__

// include
#include <map>
#include <string>

// include custom
#include "employee.h"

// custom types
typedef std::map<std::string, employee_t>::iterator roster_it;
typedef std::map<std::string, employee_t>::const_iterator const_roster_it;

class roster_t {
	private:
		
		// roster_t attributes
		std::map<std::string, employee_t> roster_;

	public:

		// methods
		void append_employee(const std::string& jmbg, const employee_t& employee);
		void delete_employee(const std::string& jmbg);
		const_roster_it find_employee(const std::string& jmbg) const;
};

#endif // __ROSTER_H__
