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

    void removeIfPresentPersonAt(string, int);

public:
    AddressBook()
    {
    }
    void addPerson(Person);
    void printAddressBook();
    void updateDetails(int, string);
    void deletePerson(string name);
    bool isPresent(string name);
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
    for (int personCounter = 0; personCounter < personCollection.size(); personCounter++)
        if ((personCollection[personCounter].firstName + " " + personCollection[personCounter].lastName) == name)
            return true;

    return false;
}

void AddressBook::deletePerson(string name)
{
    if (!isPresent(name))
    {
        cout << "\nNo such person present.";
        return;
    }

    for (int personCounter = 0; personCounter < personCollection.size(); personCounter++)
        removeIfPresentPersonAt(name, personCounter);
}

void AddressBook::removeIfPresentPersonAt(string name, int position)
{
    if ((personCollection[position].firstName + " " + personCollection[position].lastName) == name)
        personCollection.erase(personCollection.begin() + position);
}