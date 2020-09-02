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
    ~Person();
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
    cout << "\n\t#-------------------------------------------#\n";
    cout << "\nFirst Name : " << firstName
         << "\nLast Name : " << lastName
         << "\nPhone Number : " << phoneNumber
         << "\nAddress : " << address
         << "\nCity : " << city
         << "\nState : " << state
         << "\nZip : " << zip
         << endl;
}

Person::~Person()
{
    firstName.clear();
    lastName.clear();
    address.clear();
    city.clear();
    state.clear();
    zip.clear();
    phoneNumber.clear();
}