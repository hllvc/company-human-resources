// include
#include <string>
#include <iostream>

// include custom
#include "../include/navigation.h"
#include "../include/additional_functions.h"
#include "../include/employee.h"
#include "../include/roster.h"

extern roster_t roster;

// custom choice for menu
const char FIRST_CHOICE = '1';
const char SECOND_CHOICE = '2';
const char THIRD_CHOICE = '3';
const char EXIT_CHOICE = '0';

// navigation text
const std::string MAIN_MENU_TEXT(
	"MAIN MENU\n"
	"[" + std::string(1, FIRST_CHOICE) + "] Create new employee\n"
	"[" + std::string(1, SECOND_CHOICE) + "] Delete existing employee\n"
	"[" + std::string(1, THIRD_CHOICE) + "] Find existing emplyee\n"
	"\n[" + std::string(1, EXIT_CHOICE) + "] Exit\n"
	"\nYour choice: "
);

// main menu function
void main_menu() {
	char choice;
	while(true) {
		std::cout << MAIN_MENU_TEXT;
		std::cin >> choice;
		switch (choice) {
			case FIRST_CHOICE:
				create_new_employee();
				break;
			case SECOND_CHOICE:
				delete_employee();
				break;
			case THIRD_CHOICE:
					find_employee();	
				break;
			case EXIT_CHOICE:
				exit(0);
			default:
				std::cout << "wrong";
		}
	}
}

// new employee function
void create_new_employee() {

	// name, surname & JMBG input
	std::string const * const name = string_input("Name");
	std::string const * const surname = string_input("Surname");
	std::string const * const jmbg = jmbg_input();

	employee_t const employee(*name, *surname);
	try {
		roster.append_employee(*jmbg, employee);
	} catch (const char * e) {
		if (e == std::string("exists"))
			std::cout << "Employee with given JMBG already exists";
		delete jmbg;
		delete name;
		delete surname;
		return;
	}

	delete jmbg;
	delete name;
	delete surname;
}

// delete employee funciton
void delete_employee() {
	std::string const * const jmbg = jmbg_input();
	try {
		roster.delete_employee(*jmbg);
	} catch (const char * e) {
		if (e == std::string("empty"))
			std::cout << "There is no registered employees!\n";
		else if (e == std::string("not found"))
			std::cout << "Employee not found!\n";
		delete jmbg;
		return;
	}
	delete jmbg;
}

// find employee function
void find_employee() {
	std::string const * const jmbg = jmbg_input();
	const_roster_it employee;
	try {
		employee = find_employee_by_jmbg(*jmbg);
	} catch (const char * e) {
		if (e == std::string("error")) {} {
			delete jmbg;
			return;
		}
	}
	delete jmbg;
	std::cout << "{" << employee->first << " : " << employee->second.getName() << " " << employee->second.getSurname() << "}";
}
