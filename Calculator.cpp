#include <iostream>

void displayMenu() {
    std::cout << "Simple Calculator" << std::endl;
    std::cout << "Choose an operation:" << std::endl;
    std::cout << "1. Addition (+)" << std::endl;
    std::cout << "2. Subtraction (-)" << std::endl;
    std::cout << "3. Multiplication (*)" << std::endl;
    std::cout << "4. Division (/)" << std::endl;
}

int main() {
    double num1, num2;
    int choice;
    double result;

    // Display the menu
    displayMenu();

    // Get user input
    std::cout << "Enter your choice (1-4): ";
    std::cin >> choice;

    // Validate the user's choice
    if (choice < 1 || choice > 4) {
        std::cout << "Invalid choice. Please run the program again and select a valid operation." << std::endl;
        return 1;
    }

    // Get the numbers from the user
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Perform the chosen operation
    switch (choice) {
        case 1:
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case 2:
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case 3:
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case 4:
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            } else {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << std::endl;
            }
            break;
        default:
            // This case should not occur due to the earlier validation
            std::cout << "An unexpected error occurred." << std::endl;
            break;
    }

    return 0;
}
