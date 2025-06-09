#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <fstream>
#include <cctype> // for isalpha
#include <cstdlib>
#include <ctime>
#include <map>

// Global variable to store valid 5-letter words
std::unordered_set<std::string> validWords;

// Function to load the 5-letter words from a file
void loadWord(const std::string &filename)
{
    std::ifstream file(filename);
    std::string word;
    if (file.is_open())
    {
        while (file >> word)
        {
            // Ensure the word is exactly 5 letters long
            if (word.length() == 5)
            {
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
                validWords.insert(word);
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Unable to open word list file: " << filename << std::endl;
        exit(1);
    }
}

// Function to choose a random word from the set of valid words
std::string chooseWord()
{
    std::srand(std::time(0)); // Seed for random number generation
    int index = std::rand() % validWords.size();
    auto it = validWords.begin();
    std::advance(it, index);
    return *it;
}

// Function to check if the user's guess is a valid 5-letter word
bool isValidGuess(const std::string &guess)
{
    // Check if the guess has 5 letters and if it exists in the valid words set
    if (guess.length() != 5)
    {
        return false;
    }

    // Check if all characters in the guess are alphabetic
    for (char c : guess)
    {
        if (!std::isalpha(c))
        {
            return false;
        }
    }

    // Convert the guess to lowercase to match the format in validWords set
    std::string lowerGuess = guess;
    std::transform(lowerGuess.begin(), lowerGuess.end(), lowerGuess.begin(), ::tolower);

    // Check if the word exists in the valid words set
    return validWords.find(lowerGuess) != validWords.end();
}

// Function to set text color in the terminal (for UNIX-based systems)
void setColor(const std::string &color)
{
    static std::map<std::string, std::string> colors = {
        {"reset", "\033[0m"},
        {"green", "\033[32m"},
        {"yellow", "\033[33m"},
        {"gray", "\033[37m"}, // Light gray for incorrect letters
        {"white", "\033[37m"}};

    std::cout << colors[color];
}

void printDashes()
{
    std::cout << "---------------------\n";
}

void printGrid(const std::vector<std::string> &guesses, const std::string &word)
{
    std::cout << "\n   W O R D L E   \n";
    printDashes();

    for (int i = 0; i < 6; ++i)
    { // 6 attempts max
        if (i < guesses.size())
        {
            const std::string &guess = guesses[i];
            for (size_t j = 0; j < 5; ++j)
            {
                // Green if letter is in the correct position
                if (guess[j] == word[j])
                {
                    setColor("green");
                }
                // Yellow if letter is in the word but wrong position
                else if (word.find(guess[j]) != std::string::npos)
                {
                    setColor("yellow");
                }
                // Gray if letter is not in the word
                else
                {
                    setColor("gray");
                }
                std::cout << " " << char(toupper(guess[j])) << " ";
                setColor("reset");
            }
            std::cout << "\n";
        }
        else
        {
            // Empty row of underscores
            std::cout << " _ _ _ _ _ \n";
        }
        printDashes(); // Print dashed line after each row
    }
}

// Main function to run the Wordle game
int main()
{
    // Load the word list from "valid-wordle-words.txt"
    loadWord("valid-wordle-words.txt");

    std::string word = chooseWord();
    std::vector<std::string> guesses;
    std::string guess;
    int attempts = 6;

    std::cout << "Welcome to Wordle (C++ Edition)\n";
    std::cout << "You have 6 attempts to guess the 5-letter word.\n";

    while (attempts > 0)
    {
        printGrid(guesses, word);
        std::cout << "\nAttempts left: " << attempts << "\n";
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Validate the guess
        if (!isValidGuess(guess))
        {
            std::cout << "Invalid guess. Please enter a valid 5-letter word.\n";
            continue;
        }

        guesses.push_back(guess);

        // Check if the guess is correct
        if (guess == word)
        {
            printGrid(guesses, word);
            setColor("green");
            std::cout << "\nCongratulations! You guessed the word.\n";
            setColor("reset");
            break;
        }

        attempts--;
    }

    // If no attempts are left, reveal the word
    if (attempts == 0)
    {
        printGrid(guesses, word);
        setColor("red");
        std::cout << "\nGAME OVER! THE WORD WAS " << word << ".\n";
        setColor("reset");
    }

    return 0;
}
