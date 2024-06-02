#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));
    // Generate a random number between 1 and 100
    int number_to_guess = std::rand() % 100 + 1;
    int user_guess = 0;

    std::cout << "Welcome to the number guessing game!" << std::endl;
    std::cout << "I have selected a random number between 1 and 100." << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> user_guess;

        if (user_guess < number_to_guess) {
            std::cout << "Your guess is too low. Try again." << std::endl;
        } else if (user_guess > number_to_guess) {
            std::cout << "Your guess is too high. Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
            break;
        }
    }

    return 0;
}