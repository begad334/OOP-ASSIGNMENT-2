#include <iostream>

using namespace std;

void binaryPrint(int n) {
    if (n > 1) {
        binaryPrint(n / 2);
    }
    cout << n % 2;
}

int main() {
    int n1 = 0;
    int n2 = 4;
    int n3 = 27;

    binaryPrint(n1);  // Output: 0
    cout << endl;  // Newline after each number
    binaryPrint(n2);  // Output: 100
    cout << endl;  // Newline after each number
    binaryPrint(n3);  // Output: 11011
    cout << endl;  // Newline after each number

    return 0;
}
