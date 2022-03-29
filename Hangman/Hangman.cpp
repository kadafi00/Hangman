#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

int main()
{
// Display Title of the program to the user
	cout << "Welcome to Travis Moore's Code Breaking Game!" << endl;
// Ask the recruit to log in using their name
	cout << "Please log in using your first name." << endl;
// Hold the recruit's name in a var, and address them by it throughout the simulation.
// Other var declarations
	string userName;
	cin >> userName;
    char userin;
    // Create an int var to count the number of simulations being run starting at 1
    int trys = 1;
    // Display an overview of what Keywords II is to the recruit 
	cout << "Welcome " << userName << ", to the code breaking game. It's basically hangman." << endl;
	// Display directions to the recruit on how to use Keywords
	cout << "The game will choose 3 words randomaly from a set of 10." << endl;
	cout << "It is your job to guess those three words by choosing one letter at a time." << endl;
	cout << "Once you have guessed all three words, enter them as the code word with no spaces to hack the system." << endl;

    // Create a collection of 10 words you had written down manually
	vector<string> codewords{ "HACKER", "SAVVY", "GAMER", "SODA", "PHYSICS", 
	"ENGINEER", "BLOOD", "VAMPIRE",  "PRINCESS", "SAVIOR" };
    do {
        srand((time(0)));
        random_shuffle(codewords.begin(), codewords.end());
        // Display the simulation # is starting to the recruit. 
        cout << "Simulation " << trys++ << " has begun." << endl;
        // Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
        string correctCode = codewords[0] + " " + codewords[1] + " " + codewords[2];

        //     Show recruit the letters he or she has guessed
        vector<char> lettersGuessed;
        //     Show player how much of the secret word he or she has guessed
        string sofar(correctCode.size(), '#');
        sofar[codewords[0].size()] = ' ';
        int indexCode = codewords[0].size() + codewords[1].size() + 1;
        sofar[indexCode] = ' ';

        //     While recruit has entered a letter that he or she has already guessed
        int wrong = 0;
        char guess;
        string lUsed = "";
        // While loop for new letters entered by the user
        while ((wrong < 8 && sofar != correctCode)) {
            cout << "You have " << (8 - wrong) << " guesses left." << endl;
            cout << endl;
            cout << "Please enter a letter." << endl;
            cout << sofar << endl;
            cin >> guess;
            guess = toupper(guess);
            // While loop for letters already entered by the user
            while (lUsed.find(guess) != string::npos) {
                cout << "Letter already guessed." << endl;
                cout << "Please enter a letter." << endl;
                cin >> guess;
                guess = toupper(guess);
            }
            // If statement for when the user guesses a letter that is in the code
            if (correctCode.find(guess) != string::npos) {
                for (int i = 0; i < correctCode.length(); i++)
                    if (correctCode[i] == guess) {
                        sofar[i] = guess;
                    }
                cout << "Correct! The letter " << guess << " is in the code word!" << endl;
                lUsed = lUsed + guess;
            }

            else
            {
                // Everytime the user guesses incorrectly, iterate wrong once then each wrong correlates to a different
                // part of the hangman
                cout << "Incorrect." << endl;
                ++wrong;
                lUsed = lUsed + guess;
            }
            // These if statements allow me to create the hangman figure each time a letter is incorrectly guessed
            if (wrong == 0) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << "    " << endl;
                cout << "    " << endl;
                cout << "    " << endl;
                cout << endl;
            }
            else if (wrong == 1) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << "    " << endl;
                cout << "    " << endl;
                cout << endl;
            }
            else if (wrong == 2) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << " |  " << endl;
                cout << "    " << endl;
                cout << endl;
            }
            else if (wrong == 3) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << "-|  " << endl;
                cout << "    " << endl;
                cout << endl;
            }
            else if (wrong == 4) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << "-|- " << endl;
                cout << "    " << endl;
                cout << endl;
            }
            else if (wrong == 5) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << "-|- " << endl;
                cout << "|   " << endl;
                cout << endl;
            }
            else if (wrong == 6) {
                cout << "    " << endl;
                cout << "    " << endl;
                cout << " O  " << endl;
                cout << "-|- " << endl;
                cout << "| | " << endl;
                cout << endl;
            }
            else if (wrong == 7) {
                cout << "    " << endl;
                cout << " |  " << endl;
                cout << " O  " << endl;
                cout << "-|- " << endl;
                cout << "| | " << endl;
                cout << endl;
            }
            else if (wrong == 8) {
                cout << "  _ " << endl;
                cout << " |  " << endl;
                cout << " O  " << endl;
                cout << "-|- " << endl;
                cout << "| | " << endl;
                cout << endl;
            }
            // This is to display the characters already used by the player
            cout << endl;
            cout << "Characters used: " << lUsed << endl;

        }

        if (wrong == 8)
        {
            // If wrong 8 times, display the correct phrase and ask if they want to play again
            cout << endl;
            cout << "Unfortunately, you have been hung. The correct phrase: " << correctCode << endl;
            cout << "Would you like to run the simulation again? y for yes, n for no" << endl;
        }

        else
        {
            // Takes all three words, stores them in winningCode and asks the user to input said code
            string winningCode;
            cout << endl;
            cout << "You got the phrase! " << correctCode << endl;
            cout << "Please enter the 3 word code with no spaces to crack the code." << endl;
            cin >> winningCode;
            cout << "Congratulations! You've cracked the code!" << endl;
            cout << "Would you like to run the simulation again? y for yes, n for no" << endl;
        }
        // For when the user enters y, it will restart the do while loop
        cin >> userin;
        userin = toupper(userin);
    } while (userin == 'Y');
}

