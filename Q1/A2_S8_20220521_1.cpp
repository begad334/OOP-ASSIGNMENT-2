// File: A2_S8_20220521_1.cpp
// Purpose: Solving Problem no. 1
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023


#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char sentence[101]; // Buffer to store the input sentence

    // Read the input sentence
    cout << "Enter a sentence (up to 100 characters): ";
    cin.getline(sentence, sizeof(sentence));

    // Initialize variables for correction
    bool capitalizeNext = true; // Start with an uppercase letter

    // Process the sentence
    for (int i = 0; sentence[i] != '\0'; i++) {
        char currentChar = sentence[i];

        // Convert uppercase letters to lowercase
        if (isupper(currentChar)) {
            currentChar = tolower(currentChar);
        }

        // If the character is a space or newline, skip additional spaces
        if (currentChar == ' ' || currentChar == '\n') {
            if (capitalizeNext) {
                // Replace space with an uppercase letter
                sentence[i] = 'A' + currentChar - ' ';
                capitalizeNext = false;
            } else {
                // Replace consecutive spaces with a single space
                while (sentence[i + 1] == ' ' || sentence[i + 1] == '\n') {
                    for (int j = i + 1; sentence[j] != '\0'; j++) {
                        sentence[j] = sentence[j + 1];
                    }
                }
            }
        } else {
            // Next character should be capitalized
            capitalizeNext = false;
        }
    }

    // Capitalize the first letter
    if (islower(sentence[0])) {
        sentence[0] = toupper(sentence[0]);
    }

    // Print the corrected sentence
    cout << "Corrected sentence: " << sentence << endl;

    return 0;
}
