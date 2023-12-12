#include <iostream>

using namespace std;

void printPattern(int n, int i) {
    if (n == 1) {
        for (int j = 0; j < i; j++) {
            cout << "   ";
        }
        cout << "*" << endl;
    } else {
        printPattern(n / 2, i);
        for (int j = 0; j < i; j++) {
            cout << "   ";
        }
        for (int j = 0; j < n; j++) {
            cout << "*";
            if (j < n - 1) {
                cout << "  ";
            }
        }
        cout << endl;
        printPattern(n / 2, i + n / 2);
    }
}

void pattern(int n) {
    printPattern(n, 0);
}

int main() {
    int n =8;
    pattern(n);

    return 0;
}
