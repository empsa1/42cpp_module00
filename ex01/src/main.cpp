#include "../include/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>

int validNumber(std::string n) {
    int i = -1;
    if (n.length() <= 0)
        return 0;
    int size = n.length();
    while (++i < size)
    {
        if (!(std::isdigit(n[i])))
            return 0;
    }
    return 1;
}

std::string removeSpaces(const std::string& str) {
    std::string result;
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isspace(str[i])) {
            result += str[i];
        }
    }
    return result;
}

int promptUser2() {
    std::string str = "";
    int result = -1;
    while (1) {
        std::getline(std::cin, str);
        str = removeSpaces(str);
        if (validNumber(str) == 0) {
            std::cout << "Enter the index of the entry to display: ";
            continue ;
        }
        result = atoi(str.c_str());
        if (result >= 0 && result < 8)
            break;
        std::cout << "Enter a valid index between [0-7]" << std::endl;
    }
    return result;
}

std::string promptUser(std::string input) {
    std::cout << input;
    std::string str = "";
    while (1) {
        std::getline(std::cin, str);
        str = removeSpaces(str);
        if (str.length() > 0)
            break;
        std::cout << "Invalid input" << std::endl;
        std::cout << input;
    }
    return str;
}

int main(int argc, char **argv) {
    PhoneBook phonebook;
    std::string command;
    if (argc != 1 || argv[1] != NULL) {
        std::cout << "Invalid usage of the program! Usage: /PhoneBook" << std::endl;
        return 1;
    }
    system("clear");
    std::cout << std::endl << "Welcome to the 80s and their " << "unbelievable technology!" <<
    " Write a program that behaves like a crappy awesome phonebook software." << std::endl;
    while (true) {
        std::cout << "Enter a command: ADD, SEARCH, EXIT: ";
        std::getline(std::cin, command);
        if (std::cin.eof()) {
            exit(1);
        }
        command = removeSpaces(command);
        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            firstName = promptUser("Enter first name: ");
            lastName = promptUser("Enter last name: ");
            nickname = promptUser("Enter nickname: ");
            phoneNumber = promptUser("Enter phone number: ");
            darkestSecret = promptUser("Enter your darkest secret: ");
            phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        } else if (command == "SEARCH") {
            if (phonebook.getNumContacts() > 0) {
                phonebook.listContacts();
                int index = -1;
                std::cout << "Enter the index of the entry to display: ";
                index = promptUser2();
                if (index >= 0)
                    phonebook.displayContact(index);
            } else
                std::cout << "The List is empty. Please add contacts before trying to search for them!" << std::endl;
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    std::cout << "Going to exit the program!" << std::endl;
    system("clear");
    std::cout << "Exited the program sucessfully!" << std::endl;
    return (0);
}
