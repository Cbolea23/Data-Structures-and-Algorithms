#include <iostream>
using namespace std;

int main() {
    cout << "MY BASIC CALCULATOR - BOLEA" << endl;
//First number
    int number1;
    cout << "Enter a number: ";
    cin >> number1;

//Operations  
    char operation;
    cout << " Select operation: +, -, /, x. ";
    cin >> operation;

 //Second number
    int number2;
    cout << "Enter a number: ";
    cin >> number2;
    
//If and else statement
//Minus Operator
    if (operation == '-') {
        cout << "RESULT: " << number1 - number2 << endl;
    } 
 //Divide Operator  
    else if (operation == '/') {
        if (number1 == 0) {
            cout << "ERROR: Cannot divide zero" << endl;
        }else if (number2 == 0) {
            cout << "ERROR: Cannot divide zero" << endl;
        }else cout << "RESULT: " << number1 / number2 << endl;
    } 
//Addition Operator
    else if (operation == '+') {
        cout << "RESULT: " << number1 + number2 << endl;
    } 
//Multiplication Operator    
    else if (operation == 'x') {
        cout << "RESULT: " << number1 * number2 << endl;       
    } else {
        cout << "ERROR: please select a proper operation" << endl;
    }
    return 0;

}