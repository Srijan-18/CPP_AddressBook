#include <iostream>
#include "AddressBook.cpp"
#include "InputUtility.cpp"

using namespace std;

AddressBook addressBook;
InputUtility inputUtility;

void presentWelcomeMessage()
{
    cout << "\n\t\t\t**** WELCOME TO ADDRESS BOOK PROGRAM ****" << endl;
}

Person getPersonDetails()
{
    string firstName = inputUtility.getStringInputfor("First Name");
    string lastName = inputUtility.getStringInputfor("Last Name");
    if (addressBook.isPresent(firstName + " " + lastName))
    {
        cout << "\n\n\t\t********** PERSON ALREADY PRESENT **********\n";
        Person person;
        return person;
    }
    string phoneNumber = inputUtility.getStringInputfor("Phone Number");
    string address = inputUtility.getStringInputfor("Address");
    string city = inputUtility.getStringInputfor("City");
    string state = inputUtility.getStringInputfor("State");
    string zip = inputUtility.getStringInputfor("Zip Code");

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
    cout << "\nEnter 1 to update address\nEnter 2 to update city\nEnter 3 to update state\nEnter 4 to update zipcode\nEnter 5 to update phoneNumber\nAny other number to go back\nYOUR CHOICE: ";
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

bool continueUpdateProcess(int updateFieldChoice)
{
    return (updateFieldChoice > 0 && updateFieldChoice < 6) ? true : false;
}

void updateAPerson(string name)
{
    if (!addressBook.isPresent(name))
    {
        cout << "\n\n\t\t***** NO SUCH PERSON DATA PRESENT *****\n";
        return;
    }

    while (true)
    {
        int updateFieldChoice;
        updateFieldChoice = getUpdateChoice();
        if (!continueUpdateProcess(updateFieldChoice))
            break;
        addressBook.updateDetails(updateFieldChoice, name, getNewValue());
    }
}

int getSortChoice()
{
    cout << "\n\n\t\t***** SORT MENU *****\n";
    cout << "\nEnter 1 to sort by PERSON NAME\nEnter 2 to sort by ZIP\nEnter 3 to sort by CITY NAME\nEnter 4 to sort by STATE NAME\n\nYOUR CHOICE: ";
    int sortChoice;
    cin >> sortChoice;
    cin.get();
    return sortChoice;
}

void sortTheAddressBook()
{
    int sortChoice = getSortChoice();
    addressBook.sortAddressBook(sortChoice);
}

void printVector(vector<Person> requiredList)
{
    if (requiredList.size() == 0)
    {
        cout << "\n\n\t\t***** NO DATA TO DISPLAY *****\n";
        return;
    }

    for (int personCounter = 0; personCounter < requiredList.size(); personCounter++)
        requiredList[personCounter].printDetails();
}

int getSearchChoice()
{
    cout << "\n\n\t\t***** SEARCH MENU *****\n";
    cout << "\nEnter 1 to search by CITY \nEnter 2 to search by STATE\nEnter 3 to search by CITY AND STATE\n\nYOUR CHOICE: ";
    int searchChoice;
    cin >> searchChoice;
    cin.get();
    return searchChoice;
}

void searchAndPrint()
{
    enum searchChoices
    {
        CITY = 1,
        STATE,
        CITY_AND_STATE
    };

    vector<Person> requiredList;

    switch (getSearchChoice())
    {
    case CITY:
    {
        string cityName = inputUtility.getStringInputfor("City Name");
        requiredList = addressBook.getPersonsByCity(cityName);
        break;
    }
    case STATE:
    {
        string stateName = inputUtility.getStringInputfor("State Name");
        requiredList = addressBook.getPersonsByState(stateName);
        break;
    }
    case CITY_AND_STATE:
    {
        string cityName = inputUtility.getStringInputfor("City Name");
        string stateName = inputUtility.getStringInputfor("State Name");
        requiredList = addressBook.getPersonsByCityAndState(cityName, stateName);
        break;
    }
    default:
        cout << "\n\n\t\t***** INVALID INPUT *****\n";
    }

    printVector(requiredList);
}

void performOperations(int operationChoice)
{
    enum operationChoices
    {
        ADD_PERSON = 1,
        UPDATE,
        DELETE,
        DISPLAY,
        SORT,
        SEARCH
    };

    switch (operationChoice)
    {
    case ADD_PERSON:
        addressBook.addPerson(getPersonDetails());
        break;
    case UPDATE:
        updateAPerson(inputUtility.getStringInputfor("Name"));
        displayAddressBook();
        break;
    case DELETE:
        addressBook.deletePerson(inputUtility.getStringInputfor("Name"));
        break;
    case DISPLAY:
        addressBook.printAddressBook();
        break;
    case SORT:
        sortTheAddressBook();
        addressBook.printAddressBook();
        break;
    case SEARCH:
        searchAndPrint();
        break;
    default:
        break;
    }
}

void presentOperationChoices()
{
    bool flag = true;
    while (flag)
    {
        cout << "\nEnter 1 to add a person\nEnter 2 to update\nEnter 3 to delete\nEnter 4 to display whole AddressBook\nEnter 5 to sort\nEnter 6 to search\nAny other number to exit\n\nYOUR CHOICE: ";
        int choice;
        cin >> choice;
        cin.get();
        performOperations(choice);
        flag = choice > 0 && choice < 7;
    }
}

int main()
{
    presentWelcomeMessage();
    addressBook.addPerson(getPersonDetails());
    presentOperationChoices();
    return 0;
}