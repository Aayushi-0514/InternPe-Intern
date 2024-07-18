#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to clear the screen (platform dependent)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Array of choices
    const char* choices[] = { "Rock", "Paper", "Scissors" };

    int userWins = 0;
    int computerWins = 0;
    int ties = 0;
    char playAgain;

    do {
        clearScreen();

        // Get the user's choice
        int userChoice;
        cout << "Welcome to Rock, Paper, Scissors!\n";
        cout << "Enter your choice: (0 for Rock, 1 for Paper, 2 for Scissors): ";
        while (!(cin >> userChoice) || userChoice < 0 || userChoice > 2) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid choice. Please enter 0, 1, or 2: ";
        }

        // Generate the computer's choice
        int computerChoice = rand() % 3;

        // Display choices
        cout << "You chose: " << choices[userChoice] << endl;
        cout << "Computer chose: " << choices[computerChoice] << endl;

        // Determine the winner
        if (userChoice == computerChoice) {
            cout << "It's a tie!" << endl;
            ties++;
        } else if ((userChoice == 0 && computerChoice == 2) ||
                   (userChoice == 1 && computerChoice == 0) ||
                   (userChoice == 2 && computerChoice == 1)) {
            cout << "You win!" << endl;
            userWins++;
        } else {
            cout << "Computer wins!" << endl;
            computerWins++;
        }

        // Display the score
        cout << "Score: You - " << userWins << " | Computer - " << computerWins << " | Ties - " << ties << endl;

        // Ask if the player wants to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Final score: You - " << userWins << " | Computer - " << computerWins << " | Ties - " << ties << endl;

    return 0;
}
