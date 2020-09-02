#include <iostream>
#include "AddressBook.cpp"
#include "InputUtility.cpp"

using namespace std;

AddressBook addressBook;

void presentWelcomeMessage()
{
    cout << "\n\t\t\t**** WELCOME TO ADDRESS BOOK PROGRAM ****" << endl;
}

Person getPersonDetails()
{
    InputUtility inputUtility;

    string firstName = inputUtility.getStringInputfor("First Name");
    string lastName = inputUtility.getStringInputfor("Last Name");
    string address = inputUtility.getStringInputfor("Address");
    string city = inputUtility.getStringInputfor("City");
    string state = inputUtility.getStringInputfor("State");
    string zip = inputUtility.getStringInputfor("Zip Code");
    string phoneNumber = inputUtility.getStringInputfor("Phone Number");

    Person person(firstName, lastName, address, city, state, zip, phoneNumber);

    return person;
}

void addPerson()
{
    AddressBook addressBook;
    addressBook.addPerson(getPersonDetails());

    addressBook.printAddressBook();
}
int getUpdateChoice()
{
    int choice;
    cout << "\nEnter 1 to update address\nEnter 2 to update city\nEnter 3 to update state\nEnter 4 to update zipcode\nEnter 5 to update phoneNumber\nYOUR CHOICE: ";
    cin >> choice;
    cin.get();
    return choice;
}

string getNewValue()
{
    cout << "\nEnter New Value: ";
    string updatedValue;
    getline(cin, updatedValue);
    return updatedValue;
}

void displayAddressBook()
{
    addressBook.printAddressBook();
}

void performOperations()
{
    addressBook.addPerson(getPersonDetails());
    displayAddressBook();
    int choice = getUpdateChoice();
    addressBook.updateDetails(choice, getNewValue());
    displayAddressBook();
}

int main()
{
    presentWelcomeMessage();
    performOperations();
    return 0;
}