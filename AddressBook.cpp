#include <iostream>
#include <vector>
#include "Person.cpp"

class AddressBook
{
private:
    vector<Person> personCollection;
    enum Choices
    {
        ADDRESS = 1,
        CITY,
        STATE,
        ZIPCODE,
        PHONE_NUMBER
    };

    void removeIfPresentPersonAt(string, int);
    int getPersonIndexByName(string);

public:
    AddressBook()
    {
    }
    void addPerson(Person);
    void printAddressBook();
    void updateDetails(int, string, string);
    void deletePerson(string name);
    bool isPresent(string name);
};

void AddressBook::addPerson(Person person)
{
    if(person.firstName.length() == 0)
        return;
    personCollection.push_back(person);
}

void AddressBook::updateDetails(int choice, string name, string updatedValue)
{
    int personIndex = getPersonIndexByName(name);
    switch (choice)
    {
    case ADDRESS:
        personCollection[personIndex].address = updatedValue;
        break;
    case CITY:
        personCollection[personIndex].city = updatedValue;
        break;
    case STATE:
        personCollection[personIndex].state = updatedValue;
        break;
    case ZIPCODE:
        personCollection[personIndex].zip = updatedValue;
        break;
    case PHONE_NUMBER:
        personCollection[personIndex].phoneNumber = updatedValue;
        break;
    }
}

void AddressBook::printAddressBook()
{
    if(personCollection.size() == 0){
        cout << "\n\n\t\t********** NO CONTACTS TO DISPLAY **********\n";
        return;
    }
    for (int personCounter = 0; personCounter < personCollection.size(); personCounter++)
        personCollection[personCounter].printDetails();
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

int AddressBook::getPersonIndexByName(string name) {
    int position = -1;
    for (int personCounter = 0; personCounter < personCollection.size(); personCounter++)
        if ((personCollection[personCounter].firstName + " " + personCollection[personCounter].lastName) == name)
        {
            position = personCounter;
            break;
        }
    return position;
}