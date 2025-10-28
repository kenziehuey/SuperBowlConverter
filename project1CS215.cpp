/*
Purpose: This program converts a user-input year representing a Super Bowl game
into its corresponding Super Bowl number expressed as a Roman numeral.
It validates the input and ensures it falls within the valid range.
Name: Mackenzie Huey
*/


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// constants

const int START_SUPERBOWL = 1967;
const int MAX_ROMAN = 3999;
const int MAX_YEAR = START_SUPERBOWL + MAX_ROMAN - 1;

// function to convert a number to a roman numeral
string roman_numeral(int n) 
{
    string roman = "";

    
    // roman numeral patterns
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    // convert each digit to its Roman numeral equivalent
    roman += M[n / 1000];
    roman += C[(n % 1000) / 100];
    roman += X[(n % 100) / 10];
    roman += I[n % 10];

    return roman;
}
int main() {
    string input; // stores user input

    while (true) {
        // display menu 
        cout << "Roman Numerals Converter\n";
        cout << "The Super Bowl is the annual final playoff game of the NFL to determine the league champion\n";
        cout << "The first Super Bowl took place on January 15, 1967.\n";
        cout << "Super Bowl I (Los Angeles Memorial Coliseum) --> 1967\n";
        cout << "If you had a time machine, which year of the Super Bowl would you want to attend (1967 - 5965)?\n";
        cout << "Please enter the year you want to attend (click Q or q to quit): \n";

        getline(cin, input); // Read entire input including spaces

        // quit if user enters 'Q' or 'q'
        if (input == "Q" || input == "q") {
            cout << "Back to 2025, and have a great day!\n";
            break;
        }

        // extract the first valid number from input
        stringstream ss(input);
        int year;
        if (!(ss >> year)) { // If no valid number found
            cout << "Please enter a valid four-digit year (1967 - 5965)!\n";
            continue;
        }

        // if the year is too small, print error message
        if (year < START_SUPERBOWL) {
            cout << "The time machine will bring you to the year of " << year << ":\n";
            cout << "Wait!!! The year you entered is TOO EARLY for the first Super Bowl!\n";
            continue;
        }

        // if the year is too large, print error message
        if (year > MAX_YEAR) {
            cout << "The time machine will bring you to the year of " << year << ":\n";
            cout << "Hold on!!! The year you entered is TOO BIG for Roman Numerals!\n";
            continue;
        }

        // calculate super bowl number
        int super_bowl_number = year - START_SUPERBOWL + 1;
        string roman_numeral_sb = roman_numeral(super_bowl_number);

        // display the result
        cout << "The time machine will bring you to the year of " << year << ":\n";
        cout << "It is Super Bowl " << roman_numeral_sb << "!\n";
        cout << "We will help you find out the results and other information next time :)\n";
    }

    return 0;
}