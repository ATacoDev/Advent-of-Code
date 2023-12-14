#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int checkForSymbol(int tempNumber, int startingIndex) {
  return 0;
}

int main() {
  int total = 0;
  // int startingIndex = -1;
  string currentNum = "";
  // bool startingIndexFound = false;

  ifstream file("input.txt");
  string str;
  while (getline(file, str)) {
    for (int i = 0; i < str.length(); i++) {
      if (isdigit(str[i])) {
        currentNum += str[i];
      } else {
        if (!currentNum.empty()) {
          try {
            cout << "Adding value: " << currentNum << endl;
            total += stoi(currentNum);
          } catch (const std::invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << endl;
          }
          currentNum = "";
        }
      }
    }
  }

  cout << "Total: " << total << endl;

  return 0;
}

// add bool to check if there is a special character around, if so, turn string to int and add to total
