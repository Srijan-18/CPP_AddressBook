#include <iostream>

class InputUtility
{
public:
    std::string getStringInputfor(std::string field)
    {
        std::string input;
        std::cout << "\nEnter " << field << " : ";
        getline(std::cin, input);
        return input;
    }

    int getIntegerInputFor(std::string field)
    {
        int input;
        std::cout << "\nEnter " << field << " : ";
        std::cin >> input;
        return input;
    }
};