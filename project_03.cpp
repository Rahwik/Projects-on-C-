//Guess the Number
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int num, guess, tries = 0; // Declare variables to store the random number, user's guess, and number of tries
    srand(time(0)); // Seed the random number generator with the current time
    num = rand() % 100 + 1; // Generate a random number between 1 and 100
    cout << "Guess My Number Game\n\n"; // Print game title

    do
    {
        cout << "Enter a guess between 1 and 100 : "; // Prompt the user to enter a guess
        cin >> guess; // Read user's input
        tries++; // Increment the number of tries

        if (guess > num)
            cout << "Too high!\n\n"; // If guess is too high, print a message
        else if (guess < num)
            cout << "Too low!\n\n"; // If guess is too low, print a message
        else
            cout << "\nCorrect! You got it in " << tries << " guesses!\n"; // If guess is correct, print a message with the number of tries
    } while (guess != num); // Continue loop until the guess matches the random number

    return 0;
}
