#include <iostream>
#include <fstream>

using namespace std;

string numbers = "";
string gameIDString = "";

int IDSum = 0;
int gameID = 0;

int tempNumRed = 0;
int tempNumGreen = 0;
int tempNumBlue = 0;

bool gameFound = false;
bool valid = true;


int main() {

    // 12 red, 13 green, 14 blue MAX

    ifstream file("input.txt");
    string str;
    while (getline(file, str))
    {
        valid = true;
        gameIDString = "";
        gameFound = false;
        gameID = 0;

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
        if (str[i] == ';' || i == str.length() - 1) { // ';' means end of revealed cubes, reset tempNums
            if (tempNumRed > 12 || tempNumGreen > 13 || tempNumBlue > 14) {
                valid = false;
            }
            tempNumRed = 0;
            tempNumGreen = 0;
            tempNumBlue = 0;
        }
        } 
        if (valid) { // check whether the game ID is valid, and add to sum if correct
            IDSum += gameID;
        } else {
            // cout << "Invalid game ID: " << gameID << endl;
        }
    }

    cout << "IDSum: " << IDSum << endl;

return 0;
}
