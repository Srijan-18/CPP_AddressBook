#include <iostream>
#include "AddressBook.cpp"
#include "InputUtility.cpp"

void presentWelcomeMessage()
{
    std::cout << "\n\t\t\t**** WELCOME TO ADDRESS BOOK PROGRAM ****" << std::endl;
}

Person getPersonDetails()
{
    std::string firstName = "Srijan";
    std::string lastName = "Mishra";
    std::string address = "My Address";
    std::string city = "My city";
    std::string state = "My State";
    std::string phoneNumber = "9876543210";
    int zip = 876543;

    Person person(firstName, lastName, address, city, state, zip, phoneNumber);

    return person;
}

void addPerson()
{
    AddressBook addressBook;
    addressBook.addPerson(getPersonDetails());

    addressBook.printAddressBook();
}

int main()
{
    presentWelcomeMessage();
    addPerson();
    return 0;
}