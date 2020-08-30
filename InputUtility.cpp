#include <iostream>

using namespace std;

class InputUtility
{
public:
    string getStringInputfor(string field)
    {
        string input;
        cout << "\nEnter " << field << " : ";
        getline(cin, input);
        return input;
    }
};