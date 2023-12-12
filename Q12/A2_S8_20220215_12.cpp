#include <iostream>
#include <string>
#include <map>
#include <regex>

using namespace std;

// Define a map of suspicious words and phrases with associated point values
map<string, int> suspiciousTerms = {
        {"account", 2},
        {"verification", 3},
        {"password", 3},
        {"credit card", 3},
        {"social security", 3},
        {"bank", 2},
        {"confirm", 2},
        {"urgent", 2},
        {"free", 2},
        {"click here", 3},
        {"win", 2},
        {"limited time", 2},
        {"money back", 2},
        {"refund", 2},
        {"update", 2},
        {"phishing", 3},
        {"verify", 2},
        {"login", 2},
        {"fraud", 3},
        {"hurry", 2},
        {"risk-free", 2},
        {"renew", 2},
        {"unauthorized", 3},
        {"account information", 3},
        {"suspicious", 3},
        {"click below", 3},
        {"congratulations", 2},
        {"dear friend", 2},
        {"winner", 2},
        {"re-activate", 2}
};

pair<map<string, int>, int> scanForPhishingTerms(const string& text) {
    map<string, int> termCounts;
    int totalPoints = 0;

    for (const auto& term : suspiciousTerms) {
        const string& keyword = term.first;
        const int points = term.second;

        regex pattern("\\b" + keyword + "\\b", regex_constants::icase);
        smatch match;
        int count = 0;

        string::const_iterator searchStart(text.cbegin());
        while (regex_search(searchStart, text.cend(), match, pattern)) {
            count++;
            searchStart = match.suffix().first;
        }

        if (count > 0) {
            termCounts[keyword] = count;
            totalPoints += (count * points);
        }
    }

    return make_pair(termCounts, totalPoints);
}

int main() {
    string emailText = "Your account needs verification. Click here to confirm your password.";

    pair<map<string, int>, int> result = scanForPhishingTerms(emailText);
    map<string, int> termCounts = result.first;
    int totalPoints = result.second;

    cout << "Phishing Terms Found:" << endl;
    for (const auto& term : termCounts) {
        cout << term.first << ": " << term.second << " occurrences (" << term.second * suspiciousTerms[term.first] << " points)" << endl;
    }

    cout << "\nTotal Points for the Message: " << totalPoints << endl;

    return 0;
}
