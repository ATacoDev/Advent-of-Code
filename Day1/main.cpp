#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    int beginningNumber = 0;
    int endingNumber = 0;
    int total = 0;
    int combinedNumber = 0;
    bool beginningNumberFound = false;

    std::ifstream file("input.txt");
    std::string str;
    while (getline(file, str))
    {
        beginningNumberFound = false;
        beginningNumber = 0;
        endingNumber = 0;
        for (int i = 0; i < str.length(); ++i) {
        if (isdigit(str[i]) && !beginningNumberFound) {
            beginningNumber = str[i] - '0';
            endingNumber = str[i] - '0';
            beginningNumberFound = true;
        } 
        if (beginningNumberFound && isdigit(str[i])) {
            endingNumber = str[i] - '0';
        }
    }
    combinedNumber = (beginningNumber * 10) + endingNumber;
    total += combinedNumber; 
    }

    cout << "TOTAL: " << total << endl;

  return 0;
}
