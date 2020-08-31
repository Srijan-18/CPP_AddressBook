#include <iostream>

class Person
{
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    int zip;
    std::string phoneNumber;

public:
    Person() {}
    Person(std::string, std::string, std::string, std::string, std::string, int, std::string);
    void printDetails();
};

Person::Person(std::string firstName, std::string lastName, std::string address, std::string city, std::string state, int zip, std::string phoneNumber)
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
    std::cout << "\n\t#-------------------------------------------#";
    std::cout << "\nFirst Name : " << firstName
            << "\nLast Name : " << lastName
            << "\nAddress : " << address
            << "\nCity : " << city
            << "\nState : " << state
            << "\nZip : " << zip
            << "\nPhone Number : " << phoneNumber << std::endl;
}