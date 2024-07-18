#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Generate random number between 1 and 100
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to Guess the Number Game!" << endl;
    cout << "I have picked a number between 1 and 100. Try to guess it." << endl << endl;

    do {
        cout << "Enter your guess (1-100): ";
        cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > randomNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts!" << endl;
        }

    } while (guess != randomNumber);

    return 0;
}
