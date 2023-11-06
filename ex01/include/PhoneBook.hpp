#include "Contact.hpp"

class PhoneBook {
public: //Constructors and public methods
    PhoneBook();
    void addContact(const std::string& firstName, const std::string& lastName,
        const std::string& nickname, const std::string& phoneNumber,
            const std::string& darkestSecret);
    void listContacts() const;
    void displayContact(int index) const;
    int  getNumContacts() const;
    
private: //private variables of the class
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int numContacts;
};