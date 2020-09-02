#include <iostream>
#include "Person.cpp"

class AddressBook
{
private:
    Person person;
    enum Choices
    {
        ADDRESS = 1,
        CITY,
        STATE,
        ZIPCODE,
        PHONE_NUMBER
    };

public:
    AddressBook()
    {
    }
    void addPerson(Person);
    void printAddressBook();
    void updateDetails(int, string);
};

void AddressBook::addPerson(Person person)
{
    this->person = person;
}

void AddressBook::updateDetails(int choice, string updatedValue)
{
    switch (choice)
    {
    case ADDRESS:
        person.address = updatedValue;
        break;
    case CITY:
        person.city = updatedValue;
        break;
    case STATE:
        person.state = updatedValue;
        break;
    case ZIPCODE:
        person.zip = updatedValue;
        break;
    case PHONE_NUMBER:
        person.phoneNumber = updatedValue;
        break;
    default:
        cout << "\nInvalid Input";
    }
}

void AddressBook::printAddressBook()
{
    person.printDetails();
}