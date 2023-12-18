#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    string currentNum = "";
    int total = 0;
    bool specialCharacterNear = false;

    vector<string> lines;
    ifstream file("input.txt");
    string line;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    const int rows = lines.size();
    const int cols = lines[0].size();

    // Declare a 2D array
    char array2D[rows][cols];

    // Copy the input into the array. x = '.', y = special character
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (lines[i][j] == '.') {
                array2D[i][j] = 'x';
            } else if (isdigit(lines[i][j])) {
                array2D[i][j] = lines[i][j];
            } else {
                array2D[i][j] = 'y';
            }
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (isdigit(array2D[i][j])) {
                currentNum += array2D[i][j];
                if (i == 0) { // first row
                    if (j == 0) {
                        if (array2D[i][j+1] == 'y' || array2D[i+1][j] == 'y' || array2D[i+1][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j < cols - 1) {
                        if (array2D[i][j-1] == 'y' || array2D[i][j+1] == 'y' || array2D[i+1][j-1] == 'y' || array2D[i+1][j] == 'y' || array2D[i+1][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j == cols - 1) {
                        if (array2D[i][j-1] == 'y' || array2D[i+1][j-1] == 'y' || array2D[i+1][j] == 'y') {
                            specialCharacterNear = true;
                        }
                    }
                } else if (i < rows - 1) { // middle rows
                    if (j == 0) {
                        if (array2D[i-1][j] == 'y' || array2D[i-1][j+1] == 'y' || array2D[i][j+1] == 'y' || array2D[i+1][j] == 'y' || array2D[i+1][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j < cols - 1) {
                        if (array2D[i-1][j-1] == 'y' || array2D[i-1][j] == 'y' || array2D[i-1][j+1] == 'y' || array2D[i][j-1] == 'y' || array2D[i][j+1] == 'y' || array2D[i+1][j-1] == 'y' || array2D[i+1][j] == 'y' || array2D[i+1][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j == cols - 1) {
                        if (array2D[i-1][j-1] == 'y' || array2D[i-1][j] == 'y' || array2D[i][j-1] == 'y' || array2D[i+1][j-1] == 'y' || array2D[i+1][j] == 'y') {
                            specialCharacterNear = true;
                        }
                    }
                } else if (i == rows - 1) { // last row
                    if (j == 0) {
                        if (array2D[i-1][j] == 'y' || array2D[i-1][j+1] == 'y' || array2D[i][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j < cols - 1) {
                        if (array2D[i-1][j-1] == 'y' || array2D[i-1][j] == 'y' || array2D[i-1][j+1] == 'y' || array2D[i][j-1] == 'y' || array2D[i][j+1] == 'y') {
                            specialCharacterNear = true;
                        }
                    } else if (j == cols - 1) {
                        if (array2D[i-1][j-1] == 'y' || array2D[i-1][j] == 'y' || array2D[i][j-1] == 'y') {
                            specialCharacterNear = true;
                        }
                    }
                }
            } else {
                if (currentNum != "" && specialCharacterNear) { // make sure we don't add empty strings
                    cout << "Adding: " << currentNum << endl;
                    total += stoi(currentNum);
                }
                specialCharacterNear = false;
                currentNum = "";
            }
        }
    }

    cout << "Total: " << total << endl;

    return 0;
}
