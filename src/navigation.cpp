// include
#include <cstdlib>
#include <string>
#include <iostream>

// include custom
#include "../include/navigation.h"

// custom choice for menu
const char FIRST_CHOICE = '1';
const char SECOND_CHOICE = '2';
const char EXIT_CHOICE = '0';

// all text as const string
const std::string MAIN_MENU_TEXT(
	"MAIN MENU\n"
	"[" + std::string(1, FIRST_CHOICE) + "] Create new employee\n"
	"[" + std::string(1, SECOND_CHOICE) + "] Delete existing employee\n"
	"\n[" + std::string(1, EXIT_CHOICE) + "] Find existing employee\n"
	"\nYour choice: "
);

void main_menu() {
	char choice;
	while(true) {
		std::cout << MAIN_MENU_TEXT;
		std::cin >> choice;
		switch (choice) {
			case FIRST_CHOICE:
				std::cout << "first";
				break;
			case SECOND_CHOICE:
				std::cout << "second";
				break;
			case EXIT_CHOICE:
				exit(0);
			default:
				std::cout << "wrong";
		}
	}
}
