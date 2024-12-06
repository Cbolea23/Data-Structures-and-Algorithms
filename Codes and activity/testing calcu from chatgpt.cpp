#include <iostream>
using namespace std;

int main() {
    char operation;
    double num1, num2;

    // Ask the user for the operation
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;

    // Ask the user for two numbers
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Perform the operation based on the user's input
    if (operation == '+') {
        cout << "Result: " << num1 + num2 << endl;
    } else if (operation == '-') {
        cout << "Result: " << num1 - num2 << endl;
    } else if (operation == '*') {
        cout << "Result: " << num1 * num2 << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            cout << "Result: " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << std::endl;
        }
    } else {
        cout << "Error: Invalid operation." << endl;
    }

    return 0;
}