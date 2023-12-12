// File: A2_S8_20220521_5.cpp
// Purpose: Solving Problem no. 5
// Author: بيجاد عبد الغفار عبد الهادي محمود
// Section: S8
// ID: 20220521
// TA: Khaled Ahmed
// Date: 26 Oct 2023


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
};

// Function to add a new player and score to the list
void addPlayer(vector<Player>& players) {
    Player newPlayer;
    cout << "Enter player name: ";
    cin >> newPlayer.name;
    cout << "Enter player score: ";
    cin >> newPlayer.score;

    if (players.size() < 10) {
        players.push_back(newPlayer);
    } else {
        auto minScore = min_element(players.begin(), players.end(),
                                    [](const Player& p1, const Player& p2) {
                                        return p1.score < p2.score;
                                    });

        if (newPlayer.score > minScore->score) {
            *minScore = newPlayer;
        } else {
            cout << "New player's score is not higher than the lowest score in the top 10, so it will not be added." << endl;
        }
    }
}

// Function to print the top 10 names and scores
void printTopScores(const vector<Player>& players) {
    cout << "Top Scores:" << endl;
    cout << "----------------" << endl;

    vector<Player> sortedPlayers = players;
    sort(sortedPlayers.begin(), sortedPlayers.end(),
         [](const Player& p1, const Player& p2) {
             return p1.score > p2.score;
         });

    for (const auto& player : sortedPlayers) {
        cout << player.name << ": " << player.score << endl;
    }
    cout << endl;
}

// Function to find the highest score for a specific player
void findPlayerScore(const vector<Player>& players) {
    string playerName;
    cout << "Enter player name: ";
    cin >> playerName;

    int highestScore = 0;
    bool playerFound = false;

    for (const auto& player : players) {
        if (player.name == playerName && player.score > highestScore) {
            highestScore = player.score;
            playerFound = true;
        }
    }

    if (playerFound) {
        cout << "Highest score for " << playerName << ": " << highestScore << endl;
    } else {
        cout << "Player not found or not in the top 10." << endl;
    }
}

// Function to display the menu and handle user input
void displayMenu(vector<Player>& players) {
    char choice;

    do {
        cout << "Menu" << endl;
        cout << "----" << endl;
        cout << "1. Add a new player and score" << endl;
        cout << "2. Print top 10 names and scores" << endl;
        cout << "3. Find a player's highest score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addPlayer(players);
                break;
            case '2':
                printTopScores(players);
                break;
            case '3':
                findPlayerScore(players);
                break;
            case '4':
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != '4');
}

int main() {
    vector<Player> players;

    displayMenu(players);

    return 0;
}
