// include
#include <ostream>
#include <string>
#include <iostream>

// include custom
#include "../include/navigation.h"
#include "../include/additional_functions.h"
#include "../include/employee.h"
#include "../include/roster.h"
#include "../include/document.h"

extern roster_t roster;

// custom choice for menu
const char FIRST_CHOICE = '1';
const char SECOND_CHOICE = '2';
const char THIRD_CHOICE = '3';
const char FOURTH_CHOICE = '4';
const char FIFTH_CHOICE = '5';
const char EXIT_CHOICE = '0';

// navigation text
const std::string MAIN_MENU_TEXT(
	"MAIN MENU\n\n"
	"[" + std::string(1, FIRST_CHOICE) + "] Create new employee\n"
	"[" + std::string(1, SECOND_CHOICE) + "] Delete existing employee\n"
	"[" + std::string(1, THIRD_CHOICE) + "] Find existing emplyee\n"
	"[" + std::string(1, FOURTH_CHOICE) + "] Show all emplyees\n"
	"[" + std::string(1, FIFTH_CHOICE) + "] Change Employee info\n"
	"\n[" + std::string(1, EXIT_CHOICE) + "] Exit\n"
	"\nYour choice: "
);

const int LENGTH = 20;
const char SIGN = '-';
const std::string LINE(LENGTH, SIGN); 
 
// main menu function
void main_menu() {
	char choice;
	while(true) {
		std::cout << LINE << "\n\n";
		std::cout << MAIN_MENU_TEXT;
		std::cin >> choice;
		std::cout << LINE << "\n\n";
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
			case FOURTH_CHOICE:
				show_all_employees();
				break;
			case FIFTH_CHOICE:
				update_employee();
				break;
			case EXIT_CHOICE:
				write_data();
				exit(0);
			default:
				std::cout << "Wrong input!" << std::endl;
		}
	}
}

// new employee function
void create_new_employee() {
	std::string const * const name = string_input("name");
	std::string const * const surname = string_input("surname");
	std::string const * const department = string_input("department");

	employee_t * const employee = new employee_t(*name, *surname, *department);
	
	delete name;
	delete surname;
	delete department;

	std::cout << std::endl;
	char choice = yes_no("Do you want to add any of documents?");
	if (choice == 'y') {
		documents_t const * const documents = documents_input();
		employee->setDocuments(*documents);
		delete documents;
	}

	std::cout << std::endl;
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
	} else {
		std::cout << LINE << std::endl;
		std::cout << "Employee list is empty!\n";
	}
}

// find employee function
void find_employee() {
	if (!roster.empty()){
		std::string const * const jmbg = jmbg_input(false);
		find_employee_by_jmbg(*jmbg);
		std::cout << std::endl;
		delete jmbg;
	} else {
		std::cout << LINE << std::endl;
		std::cout << "Employee list is empty!\n";
	}
}

void show_all_employees() {
	if (!roster.empty()){
		roster.print_all_employees(std::cout);
	} else {
		std::cout << LINE << std::endl;
		std::cout << "Employee list is empty!\n";
	}
}


void update_employee() {
	if (!roster.empty()) {
		std::string const * const jmbg = jmbg_input(false);
		update_employee_by_jmbg(*jmbg);
		delete jmbg;
	} else {
		std::cout << LINE << std::endl;
		std::cout << "Employee list is empty!\n";
	}
}