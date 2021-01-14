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
	std::string const * const name = string_input("Name");
	std::string const * const surname = string_input("Surname");

	employee_t const * const employee = new employee_t(*name, *surname);
	
	delete name;
	delete surname;

	std::string const * const jmbg = jmbg_input(true);
	roster.append_employee(*jmbg, *employee);

	delete jmbg;
	delete employee;
}

// delete employee funciton
void delete_employee() {
	if (!roster.empty()){
		std::string const * const jmbg = jmbg_input(false);
		delete_employee_by_jmbg(*jmbg);
		delete jmbg;
	} else
		std::cout << "Employee list is empty!\n";
}

// find employee function
void find_employee() {
	if (!roster.empty()){
		std::string const * const jmbg = jmbg_input(false);
		find_employee_by_jmbg(*jmbg);
		delete jmbg;
	} else
		std::cout << "Employee list is empty!\n";
}
