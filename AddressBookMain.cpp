#include <iostream>
#include "AddressBook.cpp"
#include "InputUtility.cpp"

void presentWelcomeMessage()
{
    std::cout << "\n\t\t\t**** WELCOME TO ADDRESS BOOK PROGRAM ****" << std::endl;
}

Person getPersonFromUser()
{
    InputUtility inputUtility;

    std::string firstName = inputUtility.getStringInputfor("First Name");
    std::string lastName = inputUtility.getStringInputfor("Last Name");
    std::string address = inputUtility.getStringInputfor("Address");
    std::string city = inputUtility.getStringInputfor("City");
    std::string state = inputUtility.getStringInputfor("State");
    std::string phoneNumber = inputUtility.getStringInputfor("Phone Number");
    int zip = inputUtility.getIntegerInputFor("Zip Code");

    Person person(firstName, lastName, address, city, state, zip, phoneNumber);

    return person;
}

void addPerson()
{
    AddressBook addressBook;
    addressBook.addPerson(getPersonFromUser());

    addressBook.printAddressBook();
}

int main()
{
    presentWelcomeMessage();
    addPerson();
    return 0;
}