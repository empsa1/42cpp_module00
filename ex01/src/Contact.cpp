#include "../include/Contact.hpp"
#include <iostream>

Contact::Contact() : firstName(""), phoneNumber("") {}
Contact::Contact(std::string firstName, std::string lastName,
        std::string nickname,std::string phoneNumber,
            std::string darkestSecret) : firstName(firstName),
            lastName(lastName), nickname(nickname), phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}