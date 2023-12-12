// File: A2_S8_20220521_2.cpp
// Purpose: Solving Problem no. 2
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to check if a character is a punctuation letter
bool isPunctuation(char c) {
    return ispunct(c) && c != '-';
}

// Function to convert masculine pronouns to inclusive pronouns
string convertToInclusiveSpeech(const string& sentence) {
    stringstream ss(sentence);
    string word;
    string inclusiveSentence;

    while (ss >> word) {
        // Remove punctuation from the word
        word.erase(remove_if(word.begin(), word.end(), isPunctuation), word.end());

        // Convert masculine pronouns to inclusive pronouns
        if (word == "he" || word == "He") {
            inclusiveSentence += "he or she ";
        } else if (word == "him" || word == "Him") {
            inclusiveSentence += "him or her ";
        } else if (word == "his" || word == "His") {
            inclusiveSentence += "his or her ";
        } else if (word == "himself" || word == "Himself") {
            inclusiveSentence += "himself or herself ";
        } else {
            inclusiveSentence += word + " ";
        }
    }

    return inclusiveSentence;
}

int main() {
    cout << "Enter a sentence: ";
    string sentence;
    getline(cin, sentence);

    string inclusiveSpeech = convertToInclusiveSpeech(sentence);
    cout << inclusiveSpeech << endl;

    return 0;
}
