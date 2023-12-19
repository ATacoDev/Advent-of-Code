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

    // Print the array
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << array2D[i][j] << " ";
        }
        cout << endl;
    }
    
    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            int numAdjacent = 0;
            int localTotal = 1;

            if (array2D[y][x] == 'y') {

                // LEFT
                if (x > 0) {
                    if (isdigit(array2D[y][x - 1])) {
                        numAdjacent += 1;

                        int thisX = x - 1;
                        while (isdigit(array2D[y][thisX]) && thisX >= 0) {
                            currentNum += array2D[y][thisX];
                            thisX--;
                        }
                        reverse(currentNum.begin(), currentNum.end());
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";
                    }
                }

                // RIGHT
                if (x < cols) {
                    if (isdigit(array2D[y][x + 1])) {
                        numAdjacent += 1;

                        int thisX = x + 1;
                        while (isdigit(array2D[y][thisX]) && thisX < cols) {
                            currentNum += array2D[y][thisX];
                            thisX++;
                        }
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";
                    }
                }

                // Bottom
                if (x > 0 && y < rows) {
                    int possibleOutcome[] = {0,0,0};
                    if (isdigit(array2D[y + 1][x - 1])) {
                        possibleOutcome[0] = 1;
                    }
                    if (isdigit(array2D[y + 1][x])) {
                        possibleOutcome[1] = 1;
                    }
                    if (isdigit(array2D[y + 1][x + 1])) {
                        possibleOutcome[2] = 1;
                    }

                    // [1, 0, 1]
                    if (possibleOutcome[0] == 1 && possibleOutcome[1] == 0 && possibleOutcome[2] == 1) {
                        numAdjacent += 2;

                        // Bottom Left
                        int thisXLeft = x - 1;
                        while (isdigit(array2D[y + 1][thisXLeft]) && thisXLeft >= 0) {
                            currentNum += array2D[y + 1][thisXLeft];
                            thisXLeft--;
                        }
                        reverse(currentNum.begin(), currentNum.end());
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";

                        // Bottom Right
                        int thisXRight = x + 1;
                        while (isdigit(array2D[y + 1][thisXRight]) && thisXRight < cols) {
                            currentNum += array2D[y + 1][thisXRight];
                            thisXRight++;
                        }
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";

                    } else if (possibleOutcome[0] == 1 || possibleOutcome[1] == 1 || possibleOutcome[2] == 1) {
                        numAdjacent += 1;
                        

                        if (isdigit(array2D[y + 1][x])) {
                            currentNum += array2D[y + 1][x];
                        }

                        int thisXLeft = x - 1;
                        while (isdigit(array2D[y + 1][thisXLeft]) && thisXLeft >= 0) {
                            currentNum = array2D[y + 1][thisXLeft] + currentNum;
                            thisXLeft--;
                        }

                        int thisXRight = x + 1;
                        while (isdigit(array2D[y + 1][thisXRight]) && thisXRight < cols) {
                            currentNum += array2D[y + 1][thisXRight];
                            thisXRight++;
                        }

                        if (currentNum != "") {
                            cout << "Adding: " << currentNum << endl;
                            localTotal *= stoi(currentNum);
                            currentNum = "";
                        }
                        
                    }
                }


                // Top
                if (x > 0 && y > 0) {
                    int possibleOutcome[] = {0,0,0};
                    if (isdigit(array2D[y - 1][x - 1])) {
                        possibleOutcome[0] = 1;
                    }
                    if (isdigit(array2D[y - 1][x])) {
                        possibleOutcome[1] = 1;
                    }
                    if (isdigit(array2D[y - 1][x + 1])) {
                        possibleOutcome[2] = 1;
                    }

                    // [1, 0, 1]
                    if (possibleOutcome[0] == 1 && possibleOutcome[1] == 0 && possibleOutcome[2] == 1) {
                        numAdjacent += 2;

                        // Top Left
                        int thisXLeft = x - 1;
                        while (isdigit(array2D[y - 1][thisXLeft]) && thisXLeft >= 0) {
                            currentNum += array2D[y - 1][thisXLeft];
                            thisXLeft--;
                        }
                        reverse(currentNum.begin(), currentNum.end());
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";

                        // Top Right
                        int thisXRight = x + 1;
                        while (isdigit(array2D[y - 1][thisXRight]) && thisXRight < cols) {
                            currentNum += array2D[y - 1][thisXRight];
                            thisXRight++;
                        }
                        cout << "Adding: " << currentNum << endl;
                        localTotal *= stoi(currentNum);
                        currentNum = "";

                    } else if (possibleOutcome[0] == 1 || possibleOutcome[1] == 1 || possibleOutcome[2] == 1) {
                        numAdjacent += 1;

                        if (isdigit(array2D[y - 1][x])) {
                            currentNum += array2D[y - 1][x];
                        }

                        int thisXLeft = x - 1;
                        while (isdigit(array2D[y - 1][thisXLeft]) && thisXLeft >= 0) {
                            currentNum = array2D[y - 1][thisXLeft] + currentNum;
                            thisXLeft--;
                        }

                        int thisXRight = x + 1;
                        while (isdigit(array2D[y - 1][thisXRight]) && thisXRight < cols) {
                            currentNum += array2D[y - 1][thisXRight];
                            thisXRight++;
                        }

                        if (currentNum != "") {
                            cout << "Adding: " << currentNum << endl;
                            localTotal *= stoi(currentNum);
                            currentNum = "";
                        }
                        
                    }
                }

                if (numAdjacent == 2) {
                    total += localTotal;

                } else {
                    numAdjacent = 0;
                }

            }
        }
    }

    cout << "Total: " << total << endl;

    return 0;
}
