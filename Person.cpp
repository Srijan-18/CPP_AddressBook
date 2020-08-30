#include <iostream>
#include <string>
using namespace std;

class Person
{
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    int zip;
    string phoneNumber;

public:
    Person() {}
    Person(string, string, string, string, string, int, string);
    void printDetails();
};

Person::Person(string firstName, string lastName, string address, string city, string state, int zip, string phoneNumber)
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
         << "\nAddress : " << address
         << "\nCity : " << city
         << "\nState : " << state
         << "\nZip : " << zip
         << "\nPhone Number : " << phoneNumber << endl;
}