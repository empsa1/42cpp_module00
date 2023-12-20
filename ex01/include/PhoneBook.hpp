#include "Contact.hpp"

class PhoneBook {
public: 
    PhoneBook();
    void addContact(const std::string& firstName, const std::string& lastName,
        const std::string& nickname, const std::string& phoneNumber,
            const std::string& darkestSecret);
    void listContacts() const;
    void displayContact(int index) const;
    int  getNumContacts() const;
    
private:
    static const int maxContacts = 8;
    Contact contacts[maxContacts];
    int numContacts;
};