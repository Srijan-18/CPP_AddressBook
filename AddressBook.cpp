#include <iostream>
#include <vector>
#include "Person.cpp"

class AddressBook
{
private:
    vector<Person> personCollection;
    Person person;
    enum Choices
    {
        ADDRESS = 1,
        CITY,
        STATE,
        ZIPCODE,
        PHONE_NUMBER
    };

    bool isPresent(string name);

public:
    AddressBook()
    {
    }
    void addPerson(Person);
    void printAddressBook();
    void updateDetails(int, string);
    void deletePerson(string name);
};

void AddressBook::addPerson(Person person)
{
    personCollection.push_back(person);   
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
    }
}

void AddressBook::printAddressBook()
{
    person.printDetails();
}

bool AddressBook::isPresent(string name)
{
    return ((person.firstName + " " + person.lastName) == name);
}

void AddressBook::deletePerson(string name)
{
    if (!isPresent(name))
    {
        cout << "\nNo such person present.";
        return;
    }

    person.~Person();
}