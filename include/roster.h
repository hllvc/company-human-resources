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
typedef std::map<std::string, employee_t> roster_map;

class roster_t {
	private:
		
		// roster_t attributes
		roster_map roster_;

	public:

		// methods
		void append_employee(const std::string&, const employee_t&);
		void delete_employee(const_roster_it);
		const_roster_it find_employee(const std::string&) const;
		bool check_existing_jmbg(const std::string&) const;
		void print_employee(const employee_t&) const;
		void print_all_employees(std::ostream&) const;
		bool empty() const;
};

#endif // __ROSTER_H__
