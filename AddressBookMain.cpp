#include <iostream>
#include "Person.cpp"
#include "InputUtility.cpp"

using namespace std;

void presentWelcomeMessage()
{
    cout << "\n\t\t\t**** WELCOME TO ADDRESS BOOK PROGRAM ****" << endl;
}

Person getPersonFromUser()
{
    InputUtility inputUtility;
    
    string firstName = inputUtility.getStringInputfor("First Name");
    string lastName = inputUtility.getStringInputfor("Last Name");
    string address = inputUtility.getStringInputfor("Address");
    string city = inputUtility.getStringInputfor("City");
    string state = inputUtility.getStringInputfor("State");
    string phoneNumber = inputUtility.getStringInputfor("Phone Number");
    int zip;
    cout << "\nEnter Zipcode : ";
    cin >> zip;

    Person person(firstName, lastName, address, city, state, zip, phoneNumber);

    return person;
}

void addPerson()
{
    Person person = getPersonFromUser();

    person.printDetails();
}

int main()
{
    presentWelcomeMessage();
    addPerson();
    return 0;
}