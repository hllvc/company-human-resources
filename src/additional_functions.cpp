// include
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <list>
#include <string>
#include <cctype>
#include <iostream>

// include custom
#include "../include/additional_functions.h"

extern roster_t roster;

#define JMBG_SIZE 13

// function for documents input
const documents_t  * const documents_input() {
	documents_t * const documents = new documents_t();
	while (true) {
		std::string const * const doc_name = string_input("document name");
		std::string const * const doc_type = string_input("type");
		std::string const * const doc_description = string_input("description");

		document_t const * const document = new document_t(*doc_name, *doc_type, *doc_description);

		delete doc_name;
		delete doc_type;
		delete doc_description;

		documents->append_document(*document);

		delete document;

		char choice = yes_no("Do you want to add another document?");
		if (choice == 'n')
			return documents;
	}
}

// function for yes no
const char yes_no(const std::string& text) {
		char choice;
		while (true) {
			std::cout << std::endl << text <<  " (y/n): ";
			std::cin >> choice;
			if (choice == 'y' || choice == 'n')
				return choice;
			else
				std::cout << "Wrong input!\n";
		}
}

// function for custom string input
const std::string * const string_input(const std::string& field) {
	std::string * const input = new std::string();
	while (true) {
		std::cout << "Enter " << field << ": ";
		std::cin >> *input;
		try {
			is_digit(input);
			return input;
		} catch (const char * e) {
			if (e == std::string("is digit"))
				std::cout << field << " cannot contain digits!\n";
		}
	}
}

// function for JMBG input
const std::string * const jmbg_input(const bool existence) {
	std::string * const jmbg = new std::string();
	while (true) {
		std::cout << "Enter JMBG: ";
		std::cin >> *jmbg;
		try {
			check_jmbg_input(*jmbg, existence);
			return jmbg;
		} catch (const char * e) {
			std::cout << std::endl;
			if (e == std::string("exists"))
				std::cout << "Employee with given JMBG already exists!\n";
			else if (e == std::string("empty"))
				std::cout << "JMBG can't be empty!\n";
			else if (e == std::string("size error"))
				std::cout << "Size of JMBG must be 13!\n";
			else if (e == std::string("not digit"))
				std::cout << "JMBG can only contain digits!\n";
		}
	}
}

// function for correct JMBG format
void check_jmbg_input(const std::string& jmbg, const bool existence) {
	if (existence && roster.check_existing_jmbg(jmbg))
		throw "exists";
	else if (jmbg.empty())
		throw "empty";
	else if (jmbg.size() != JMBG_SIZE)
		throw "size error";
	else
		is_not_digit(&jmbg);
}

// function for checking if string contains digits
void is_digit(std::string const * const input) {
	std::for_each(input->begin(), input->end(), [](const char& c){
	if (std::isdigit(c))
		throw "is digit";
		});
}

bool is_digit(const std::string& input) {
	for (std::string::const_iterator it = input.begin(); it != input.end(); std::advance(it, 1))
		if (std::isdigit(*it))
			return true;
	return false;
}

// function for checking if string does not contain digits
void is_not_digit(std::string const * const input) {
	std::for_each(input->begin(), input->end(), [](const char& c){
	if (!std::isdigit(c))
		throw "not digit";
		});
}

void delete_employee_by_jmbg(const std::string& jmbg) {
	try {
		const_roster_it employee = roster.find_employee(jmbg);
		roster.delete_employee(employee);
	} catch (const char * e) {
		if (e == std::string("not found"))
			std::cout << "Employee with given JMBG not found!\n";
	}
}

void find_employee_by_jmbg(const std::string& jmbg) {
	try {
		const_roster_it employee = roster.find_employee(jmbg);
		employee->second.print_employee(std::cout);
	} catch (const char * e) {
		if (e == std::string("not found"))
			std::cout << "Employee with given JMBG not found!\n";
	}
}

void update_employee_by_jmbg(const std::string& jmbg) {
	try {
		roster_it employee = roster.find_employee(jmbg);
		if (change_field("name")) {
			std::string const * const name = string_input("name");
			employee->second.setName(*name);
			delete name;
		}
		if (change_field("surname")) {
			std::string const * const surname = string_input("surname");
			employee->second.setSurname(*surname);
			delete surname;
		}
		if (change_field("department")) {
			std::string const * const department = string_input("department");
			employee->second.setDepartment(*department);
			delete department;
		}
	} catch (const char * e) {
		if (e == std::string("not found"))
		std::cout << "Employee with given JMBG not found!\n";
	}
}

bool change_field(const std::string& field) {
	if (yes_no("Change " + field + "?") == 'y')
		return true;
	return false;
}

// functions for loading and saving data
const std::string * const get_path() {
	std::string * const path = new std::string();
	char * userpath = std::getenv("USERPROFILE");
	if (userpath != nullptr)
			*path = std::string(userpath) + "\\Documents\\data.txt";
	else
		userpath = std::getenv("HOME");
	if (userpath != nullptr)
		*path = std::string(userpath) + "/Documents/data";
	else
		*path = "data.txt";
	return path;
}

void write_data() {
	std::string const * const path = get_path();
	std::ofstream file(*path);
	delete path;
	roster.print_all_employees(file);
	file.close();
}

void read_data() {
	std::string const * const path = get_path();
	std::ifstream file(*path);
	delete path;
	std::string line;
	std::string jmbg;
	employee_t employee;
	document_t document;
	documents_t documents;
	std::vector<std::string> list;
	while (std::getline(file, line)) {
		list = split_input(line);
		if (list.at(0) == "JMBG:")
			jmbg = list.at(1);
		else if (list.at(0) == "Name:")
			employee.setName(list.at(1));
		else if (list.at(0) == "Surname:")
			employee.setSurname(list.at(1));
		else if (list.at(0) == "Department:")
			employee.setDepartment(list.at(1));
		else if (list.at(0) == "Document:")
			document.setName(list.at(1));
		else if (list.at(0) == "Type:")
			document.setType(list.at(1));
		else if (list.at(0) == "Description:") {
			document.setDescription(list.at(1));
			documents.append_document(document);
		} else if (line == "") {
			employee.setDocuments(documents);
			documents.clear_all_documents();
			roster.append_employee(jmbg, employee);
		}
	}
}

std::vector<std::string> split_input(std::string& line) {
	std::vector<std::string> split_list;
	std::string str = "";
	for (std::string::iterator it = line.begin(); it != line.end(); std::advance(it, 1)){
		if (*it == ' ') {
			split_list.push_back(str);
			str = "";
			continue;
		}
		str += *it;
	}
	split_list.push_back(str);
	return split_list;
}
