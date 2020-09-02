#include <iostream>

using namespace std;

class Person
{
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    void printDetails();

public:
    Person() {}
    Person(string, string, string, string, string, string, string);
    friend class AddressBook;
};

Person::Person(string firstName, string lastName, string address, string city, string state, string zip, string phoneNumber)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phoneNumber = phoneNumber;
}

void Person::printDetails()
{
    cout << "\n\t#-------------------------------------------#";
    cout << "\nFirst Name : " << firstName
         << "\nLast Name : " << lastName
         << "\nPhone Number : " << phoneNumber
         << "\nAddress : " << address
         << "\nCity : " << city
         << "\nState : " << state
         << "\nZip : " << zip
         << endl;
}