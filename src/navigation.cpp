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
				std::cout << "second";
				break;
			case THIRD_CHOICE:
					
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
	roster.append_employee(*jmbg, employee);

	delete jmbg;
	delete name;
	delete surname;
}

// find employee function
void find_employee() {

}
