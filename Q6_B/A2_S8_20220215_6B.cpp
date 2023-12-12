#include <iostream>
#include <string>

using namespace std;

void printCombinations(string prefix, int k) {
    if (k == 0) {
        // If k is zero, print the prefix and return
        cout << prefix << endl;
        return;
    }

    // Recursively generate combinations by appending '0' and '1' to the prefix
    printCombinations(prefix + '0', k - 1);
    printCombinations(prefix + '1', k - 1);
}

int main() {
    string prefix = "00101";
    int k = 2;

    cout << "All possible combinations of " << prefix << " with " << k << " more digits:\n";
    printCombinations(prefix, k);

    return 0;
}
