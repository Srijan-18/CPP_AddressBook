#include <iostream>
#include "Person.cpp"

class AddressBook
{
private:
    Person person;

public:
    AddressBook()
    {
    }
    void addPerson(Person);
    void printAddressBook();
};

void AddressBook::addPerson(Person person)
{
    this->person = person;
}

void AddressBook::printAddressBook()
{
    person.printDetails();
}