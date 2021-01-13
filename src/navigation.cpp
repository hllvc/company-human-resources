// include
#include <cstdlib>
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
	employee_t employee;

	// name & surname input
	bool valid_input = false;
	while (!valid_input) {
		try {
			std::cout << "Enter name (only one word): ";
			std::string * const name = string_input();
			std::cout << "Enter surname (only one word): ";
			std::string * const surname = string_input();
			employee = employee_t(*name, *surname);
			delete name;
			delete surname;
			valid_input = true;
		} catch (const char * e) {
			if (e == std::string("is digit"))
				std::cout << "Input must not contain digit!";
		}
	}

	// jmbg input
	valid_input = false;
	while (!valid_input) {
		try {
			std::cout << "Enter JMBG: ";
			std::string * const jmbg = jmbg_input();
			roster.append_employee(*jmbg, employee);
			delete jmbg;
			valid_input = true;
		} catch (const char * e) {
			if (e == std::string("empty"))
				std::cout << "JMBG can't be empty!";
			else if (e == std::string("size error"))
				std::cout << "Size of JMBG must be 13";
			else if (e == std::string("is digit"))
				std::cout << "JMBG can only contain digits!";
		}
	}
}

// find employee function
void find_employee() {

}
