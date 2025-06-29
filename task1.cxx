#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    int randomNumber, userGuess, attempts = 0;
    srand(time(0)); // Seed the random number generator

    randomNumber = rand() % 100 + 1; // Generate a number between 1 and 100

    cout << "🎯 Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Can you guess it?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}