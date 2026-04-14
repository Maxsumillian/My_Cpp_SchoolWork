
// #ifndef MY_CPP_SCHOOLWORK_INPUTUTILS_H
// #define MY_CPP_SCHOOLWORK_INPUTUTILS_H
//
// #endif //MY_CPP_SCHOOLWORK_INPUTUTILS_H
// these are include gaurds auto generated with cmake to prevent dups of include header files

//
// Created by maxy2 on 4/10/2026.
//

#include <limits>
#include <string>
#include <algorithm>
#include <cctype>

// Tool box of data Validation
// has remove whitespace and to lower utils as well
void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getValidatedInt(std::string prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail())
        {
            clearInputBuffer();
            return value;
        }

        clearInputBuffer();
        std::cout << "Invalid input. Please enter a whole number.\n";
    }
}

double getValidatedDouble(std::string prompt)
{
    double value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (!std::cin.fail())
        {
            clearInputBuffer();
            return value;
        }

        clearInputBuffer();
        std::cout << "Invalid input. Please enter a valid decimal number.\n";
    }
}

std::string getValidatedString(std::string prompt)
{
    std::string value;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, value);

        if (!value.empty())
            return value;

        std::cout << "Input cannot be empty. Please try again.\n";
    }
}



std::string toLower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c)
        {
            return std::tolower(c);
        });

    return s;
}

std::string removeWhitespace(std::string s)
{
    s.erase(
        std::remove_if(s.begin(), s.end(),
            [](unsigned char c)
            {
                return std::isspace(c);
            }),
        s.end()
    );

    return s;
}

bool getValidatedBool(std::string prompt, std::string yes, std::string no)// [prompt](yes/no)
{
    std::string value;
    while (true)
    {
        std::cout << prompt << " (" <<  yes << "/" << no << ")";
        std::getline(std::cin, value);

        if (removeWhitespace(toLower(value)) == removeWhitespace(toLower(yes)))
            return true;
        if (removeWhitespace(toLower(value)) == removeWhitespace(toLower(no)))
            return false;


        std::cout << "Please Enter" << " (" << yes << "/" << no << ")\n";
    }
}