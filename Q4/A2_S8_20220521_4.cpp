// File: A2_S8_20220521_4.cpp
// Purpose: Solving Problem no. 4
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023

#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int n) {
    // Create a vector to store whether numbers are prime or not
    vector<bool> isPrime(n + 1, true);

    // Loop to mark multiples of prime numbers as non-prime
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // Print the prime numbers in the specified range
    cout << "Prime numbers between 2 and " << n << " are:" << endl;
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;

    // Prompt the user to enter a number
    cout << "Enter a number (n): ";
    cin >> n;

    // Check if the entered number is less than 2
    if (n < 2) {
        cout << "No prime numbers in the specified range." << endl;
    } else {
        // Call the sieveOfEratosthenes function to find prime numbers
        sieveOfEratosthenes(n);
    }

    return 0;
}
