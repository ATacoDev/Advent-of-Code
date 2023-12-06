#include <iostream>
#include <fstream>

using namespace std;

int checkForSymbol(int tempNumber, int startingIndex) {
    // do something
}

int main() {

    int tempStartingIndex = -1;
    int tempNumber = 0;
    int total = 0;

    ifstream file("input.txt");
    string str;
    while (getline(file, str))
    {
        for (int i = 0; i < str.length(); i++) {
            if (!isalpha(str[i]) && str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && !isdigit(str[i]) && str[i] != '.') { // check if is symbol
                // cout << str[i];               
                 /*
                Loop through every character. If it's a digit, loop through until it's not a digit, and set that to tempNumber.
                Also that tempNumber's starting index as the location of the first digit.
                After you have tempNumber and tempStartingIndex, insert into checkForSymbol function and see if there's an
                adjacent symbol to the left, right, or diaganol to the tempNumber. If there is, add that number to total.
                */
            }
        }
    }
return 0;
}