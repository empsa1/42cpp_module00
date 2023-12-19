#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : numContacts(0) {}

void PhoneBook::addContact(const std::string& firstName, const std::string& lastName,
    const std::string& nickname, const std::string& phoneNumber,
             const std::string& darkestSecret) {
    int i = -1;
    if (numContacts < maxContacts) {
        contacts[numContacts] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
        numContacts++;
    }
    else
    {
        while (++i < maxContacts - 1)
            contacts[i] = contacts[i + 1];
        contacts[maxContacts - 1] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    }
}

int PhoneBook::getNumContacts() const {
    return numContacts;
}

std::string aux(std::string string) {
    if (string.length() > 10)
        string = string.substr(0, 9) + ".";
    return (string);
}

void PhoneBook::listContacts() const {
    int i = -1;
    std::cout << "|" << std::right << std::setw(10) << "Index" << "|" << std::setw(10) << "FirstName" << "|"
              << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nick name" << "|" << std::endl;
    while (++i < numContacts)
    {
        std::cout << "|" << std::right << std::setw(10) << i << "|" << std::setw(10) << aux(contacts[i].getFirstName()) << "|"
            << std::setw(10) << aux(contacts[i].getLastName()) << "|" << std::setw(10) << aux(contacts[i].getNickname()) << "|"
                << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index >= 0 && index < numContacts) {
        //system("clear");
        std::cout << std::endl <<  "Here is the contact you asked for:" << std::endl << std::endl;
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl << std::endl;
    } else {
        std::cout << "Invalid index. Please enter a valid index." << std::endl;
    }
}