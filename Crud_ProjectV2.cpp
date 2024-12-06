#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    string name;
    int age;
    float gpa;
    string course; 
    int year;
};

Student students[MAX_STUDENTS];
int numStudents = 0;

void printHeader(const string& title) {
    cout << "+---------------------------------------+" << endl;
    cout << "| " << setw(37) << left << title << " |" << endl;
    cout << "+---------------------------------------+" << endl;
}

void printMenu() {
    printHeader("Student Information System");
    cout << "| 1. Create Student                    |" << endl;
    cout << "| 2. Read Students                     |" << endl;
    cout << "| 3. Update Student                    |" << endl;
    cout << "| 4. Delete Student                    |" << endl;
    cout << "| 5. Exit                              |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "Enter your choice: ";
}

void createStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached." << endl;
        return;
    }

    printHeader("Create New Student");

    cout << "Enter student name: ";
    cin.ignore();  
    getline(cin, students[numStudents].name);

    cout << "Enter student age: ";
    cin >> students[numStudents].age;
    
    cout << "Enter student GPA: ";
    cin >> students[numStudents].gpa;

    cin.ignore();  

    cout << "Enter student course: ";
    getline(cin, students[numStudents].course);

    cout << "Enter student year: ";
    cin >> students[numStudents].year;

    cin.ignore(); 

    numStudents++;
    cout << "Student added successfully." << endl;
    cin.ignore();
}

void readStudents() {
    printHeader("Student List");

    if (numStudents == 0) {
        cout << "No students found." << endl;
        return;
    }

    cout << left << setw(5) << "No." 
         << setw(20) << "Name" 
         << setw(10) << "Age" 
         << setw(10) << "GPA"
         << setw(15) << "Course" 
         << "Year" << endl;
    cout << "-------------------------------------------------------------" << endl;
    
    for (int i = 0; i < numStudents; i++) {
        cout << setw(5) << (i+1) 
             << setw(20) << students[i].name 
             << setw(10) << students[i].age 
             << setw(10) << students[i].gpa
             << setw(15) << students[i].course 
             << students[i].year << endl;
    }
}

void updateStudent(int index) {
    if (index < 0 || index >= numStudents) {
        cout << "Invalid student index." << endl;
        return;
    }

    printHeader("Update Student");

    cout << "Enter updated name: ";
    cin.ignore();  
    getline(cin, students[index].name);

    cout << "Enter updated age: ";
    cin >> students[index].age;

    cout << "Enter updated GPA: ";
    cin >> students[index].gpa;

    cin.ignore(); 

    cout << "Enter updated course: ";
    getline(cin, students[index].course);

    cout << "Enter updated year: ";
    cin >> students[index].year;

    cin.ignore(); 

    cout << "Student updated successfully." << endl;
    cin.ignore();
}

void deleteStudent(int index) {
    if (index < 0 || index >= numStudents) {
        cout << "Invalid student index." << endl;
        return;
    }

    for (int i = index; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    numStudents--;

    cout << "Student deleted successfully." << endl;
}

int main() {
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                createStudent();
                break;
            case 2:
                readStudents();
                break;
            case 3:
                cout << "Enter student index to update (1-" << numStudents << "): ";
                int updateIndex;
                cin >> updateIndex;
                updateStudent(updateIndex - 1);  
                break;
            case 4:
                cout << "Enter student index to delete (1-" << numStudents << "): ";
                int deleteIndex;
                cin >> deleteIndex;
                deleteStudent(deleteIndex - 1);  
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 5);

    return 0;
}
