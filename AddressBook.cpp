#include <iostream>
#include "Person.cpp"
using namespace std;

class AddressBook
{
private:
    Person person;

public:
    AddressBook()
    {
    }
    void addPerson(Person *);
};

void AddressBook::addPerson(Person *person)
{
    this->person = *person;
}