#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter) {
    vector<string> result;
    size_t pos = 0;
    while ((pos = target.find(delimiter)) != string::npos) {
        result.push_back(target.substr(0, pos));
        target.erase(0, pos + delimiter.length());
    }
    result.push_back(target); // Add the remaining part of the string
    return result;
}

int main() {
    string input1 = "10,20,30";
    string delimiter1 = ",";
    vector<string> parts1 = split(input1, delimiter1);

    cout << "Splitting \"" << input1 << "\" by \"" << delimiter1 << "\":\n";
    for (const string& part : parts1) {
        cout << part << endl;
    }

    string input2 = "do re mi fa so la ti do";
    string delimiter2 = " ";
    vector<string> parts2 = split(input2, delimiter2);

    cout << "\nSplitting \"" << input2 << "\" by \"" << delimiter2 << "\":\n";
    for (const string& part : parts2) {
        cout << part << endl;
    }

    return 0;
}
