#include <iostream>
using namespace std;

int main() {
    int score1;
    cout << "Enter the score for Exam 1: ";
    cin >> score1;

    int score2;
    cout << "Enter the score for Exam 2: ";
    cin >> score2;

    int score3;
    cout << "Enter the score for Exam 3: ";
    cin >> score3;


    int average = (score1 + score2 + score3) / 3;

    if (average >= 70) {
        cout << "Average Score: " << average << endl;
        cout << "Result: Passed" << endl;
    } 
    else if (average <= 70) {
        cout << "Average Score: " << average << endl;
        cout << "Result: Failed" << endl;
    } 
    return 0;
}