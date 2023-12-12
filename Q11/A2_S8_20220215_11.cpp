#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool compareCharacterByCharacter(const string& file1, const string& file2) {
    ifstream input1(file1);
    ifstream input2(file2);
    string line1, line2;
    int lineNum = 1;

    while (getline(input1, line1) && getline(input2, line2)) {
        if (line1 != line2) {
            cout << "Files are not identical. First difference found at line " << lineNum << ":" << endl;
            cout << "File 1: " << line1 << endl;
            cout << "File 2: " << line2 << endl;
            return false;
        }
        lineNum++;
    }

    if (input1.eof() && input2.eof()) {
        cout << "Files are identical." << endl;
        return true;
    } else {
        cout << "Files have different lengths." << endl;
        return false;
    }
}

bool compareWordByWord(const string& file1, const string& file2) {
    ifstream input1(file1);
    ifstream input2(file2);
    string word1, word2;
    int lineNum = 1;

    while (input1 >> word1 && input2 >> word2) {
        if (word1 != word2) {
            cout << "Files are not identical. First difference found at line " << lineNum << ":" << endl;
            cout << "File 1: " << word1 << endl;
            cout << "File 2: " << word2 << endl;
            return false;
        }
        lineNum++;
    }

    if (input1.eof() && input2.eof()) {
        cout << "Files are identical." << endl;
        return true;
    } else {
        cout << "Files have different lengths." << endl;
        return false;
    }
}

int main() {
    string file1, file2;
    int choice;

    cout << "Enter the names of the two files to compare:" << endl;
    cin >> file1 >> file2;

    cout << "Choose the comparison method (1 for character-by-character, 2 for word-by-word): ";
    cin >> choice;

    if (choice == 1) {
        compareCharacterByCharacter(file1, file2);
    } else if (choice == 2) {
        compareWordByWord(file1, file2);
    } else {
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }

    return 0;
}
