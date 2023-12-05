#include <iostream>
#include <fstream>

using namespace std;

string numbers = "";
string gameIDString = "";

// int IDSum = 0;
int gameID = 0;
int powerSet = 0; // red * green * blue
int powerSetSum = 0; // sum of all power sets

int tempNumRed = 0;
int tempNumGreen = 0;
int tempNumBlue = 0;

int greatestRed = 0;
int greatestGreen = 0;
int greatestBlue = 0;

bool gameFound = false;
// bool valid = true;


int main() {

    // 12 red, 13 green, 14 blue MAX

    ifstream file("input.txt");
    string str;
    while (getline(file, str))
    {
        // valid = true;
        gameIDString = "";
        gameFound = false;
        gameID = 0;

        greatestRed = 0;
        greatestGreen = 0;
        greatestBlue = 0;

        tempNumRed = 0;
        tempNumGreen = 0;
        tempNumBlue = 0;

        // Extracting the game ID
        // Only accesses "Game #:"
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ':') {
                gameID += stoi(gameIDString);
                gameFound = true;
            } else if (isdigit(str[i]) && !gameFound) {
                gameIDString += str[i];
            }

        //Extracting the temporary variables for red, green, and blue

        if (isspace(str[i]) && str[i + 1] == 'r' && gameFound) { // check whether to assign numbers to red, green, or blue
            tempNumRed = stoi(numbers);
            numbers = "";
        } else if (isspace(str[i]) && str[i + 1] == 'g' && gameFound) {
            tempNumGreen = stoi(numbers);
            numbers = "";
        } else if (isspace(str[i]) && str[i + 1] == 'b' && gameFound) {
            tempNumBlue = stoi(numbers);
            numbers = "";
        } else if (isdigit(str[i]) && str[i + 1] != ':' && gameFound) { // ':' means the end of the game ID
            numbers += str[i];
        }
            if (tempNumRed > greatestRed) { // find the greatest number of each color
                greatestRed = tempNumRed;
            }
            if (tempNumGreen > greatestGreen) {
                greatestGreen = tempNumGreen;
            }
            if (tempNumBlue > greatestBlue) {
                greatestBlue = tempNumBlue;
            }
        } 
        powerSet = greatestRed * greatestGreen * greatestBlue;
        powerSetSum += powerSet;
    }
    
    cout << "Power Set: " << powerSetSum << endl;

return 0;
}