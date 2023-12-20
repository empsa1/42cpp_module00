#include "../include/PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>


int validNumber(std::string n) {
    int i = -1;
    int size = n.length();
    while (++i < size)
    {
        if (!std::isdigit(n[i]))
            return 0;
    }
    return 1;
}

int stringToInt(const std::string& str) {
    std::istringstream iss(str);
    int result;
    if (!(iss >> result)) {
        result = 0;
    }
    return result;
}

int main(int argc, char **argv) {
    PhoneBook phonebook;
    std::string command;
    if (argc != 1 || argv[1] != NULL) {
        std::cout << "Invalid usage of the program! Usage: /phonebook" << std::endl;
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
        if (command == "ADD") {
            std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            if (firstName.length() == 0) {
                std::cout << "Invalid input." << std::endl;
                break;
            }
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            if (lastName.length() == 0) {
                std::cout << "Invalid input." << std::endl;
                break;
            }
            std::cout << "Enter nickname: ";
            std::getline(std::cin, nickname);
            if (nickname.length() == 0) {
                std::cout << "Invalid input." << std::endl;
                break;
            }
            std::cout << "Enter your phone number: ";
            std::cin >> phoneNumber;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (!validNumber(phoneNumber) || phoneNumber.length() != 9) {
                    std::cout << "Invalid phone number." << std::endl;
                    break;
                }
                std::cout << "Enter your darkest secret: ";
                std::getline(std::cin, darkestSecret);
                if (darkestSecret.length() == 0) {
                    std::cout << "Invalid input." << std::endl;
                    break;
                }
                phonebook.addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        } else if (command == "SEARCH") {
            if (phonebook.getNumContacts() > 0) {
                phonebook.listContacts();
                std::string indexInput;
                int index;
                std::cout << "Enter the index of the entry to display: ";
                std::getline(std::cin, indexInput);
                try {
                    index = stringToInt(indexInput);
                    if (index >= 0) {
                        phonebook.displayContact(index);
                    } else
                        std::cout << "Invalid input. Please enter a number bigger than 0" << std::endl;
                } catch (const std::invalid_argument& e) {
                    std::cout << "Invalid input. Please enter an integer." << std::endl;
                } catch (const std::out_of_range& e) {
                std::cout << "Input is out of range for a valid index." << std::endl;
            }
            } else {
                std::cout << "The List is empty. Please add contacts before trying to search for them!" << std::endl;
            }
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
