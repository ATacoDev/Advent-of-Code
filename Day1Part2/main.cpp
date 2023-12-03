#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// regex patterns to replace string versions of integer values
regex onePattern("one");
regex twoPattern("two");
regex threePattern("three");
regex fourPattern("four");
regex fivePattern("five");
regex sixPattern("six");
regex sevenPattern("seven");
regex eightPattern("eight");
regex ninePattern("nine");

/* 
    CONVERT STRING TO REGEX ALTERED STRING
    replace string with regex pattern
    ex of four = f4r
    reason for character on boundaries both
    before and after integer is to prevent certain cases:

    eightwothree would otherwise be converted to 
    eigh2o3e instead of 8t2o3e  */
string replaceStringWithRegex(string str) {
    str = regex_replace(str, onePattern, "o1e");
    str = regex_replace(str, twoPattern, "t2e");
    str = regex_replace(str, threePattern, "t3e");
    str = regex_replace(str, fourPattern, "f4r");
    str = regex_replace(str, fivePattern, "f5e");
    str = regex_replace(str, sixPattern, "s6x");
    str = regex_replace(str, sevenPattern, "s7n");
    str = regex_replace(str, eightPattern, "e8t");
    str = regex_replace(str, ninePattern, "n9e");
    return str;
}

int main() {

int beginningNumber = 0;
int endingNumber = 0;
int total = 0;
int combinedNumber = 0;

bool beginningNumberFound = false;

ifstream file("input.txt");
string str;
while (getline(file, str))
{
    beginningNumberFound = false;
    beginningNumber = 0;
    endingNumber = 0;
    combinedNumber = 0;

    str = replaceStringWithRegex(str);

    for (int i = 0; i < str.length(); ++i) {
    // find beginning number
    // if beginning number alread found, don't access
    if (isdigit(str[i]) && !beginningNumberFound) {
        beginningNumber = str[i] - '0';
        endingNumber = str[i] - '0';
        beginningNumberFound = true;
    } 
    // find ending number
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