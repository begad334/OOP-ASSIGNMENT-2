#include <iostream>

using namespace std;

bool bears(int n) {
    // Base case: If n is already 42, you win
    if (n == 42) {
        return true;
    }

    // If n is less than 42, you cannot reach the goal
    if (n < 42) {
        return false;
    }

    // Try the possible moves
    if (n % 2 == 0 && bears(n / 2)) {
        return true;
    }

    int lastDigit = n % 10;
    int nextToLastDigit = (n % 100) / 10;
    if ((n % 3 == 0 || n % 4 == 0) && bears(n - (lastDigit * nextToLastDigit))) {
        return true;
    }

    if (n % 5 == 0 && bears(n - 42)) {
        return true;
    }

    // If none of the above conditions is met, you lose
    return false;
}

int main() {
    int n;
    cout << "Enter the number of bears: ";
    cin >> n;

    if (bears(n)) {
        cout << "You can win the bear game starting with " << n << " bears." << endl;
    } else {
        cout << "You cannot win the bear game starting with " << n << " bears." << endl;
    }

    return 0;
}
