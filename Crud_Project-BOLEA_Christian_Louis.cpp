#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;
//CHRISTIAN LOUIS BOLEA
const int MAX_STUDENTS = 100;

struct Student {
    string studID;
    string name;
    string age;
    float gpa;
    string course; 
    string year;
          
};

Student students[MAX_STUDENTS];
int numStudents = 0;

void clearScreen() {
    
    system("cls");
    
    
}

void printHeader(const string& title) {
    cout << "+---------------------------------------+" << endl;
    cout << "| " << setw(37) << left << title << " |" << endl;
    cout << "| " << setw(37) << left << "By Christian Louis Bolea" << " |" << endl;
    cout << "+---------------------------------------+" << endl;
}

void printMenu() {
    printHeader("Student Information System");
    
    cout << "| 1. Create Student                     |" << endl;
    cout << "| 2. View Students                      |" << endl;
    cout << "| 3. Update Student                     |" << endl;
    cout << "| 4. Delete Student                     |" << endl;
    cout << "| 5. Exit                               |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "Enter your choice: ";
}

void pauseForUser() {
    
    cout << "Press Enter to return to the menu..." << endl;
    cin.ignore();
    cin.get();  
}

void createStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached." << endl;
        return;
    }

    clearScreen(); 

    printHeader("Create New Student");

    cout << "Enter student name: ";
    cin.ignore();  
    getline(cin, students[numStudents].name);

    cout << "Enter student ID: ";
    cin >> students[numStudents].studID;
    cin.ignore();

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
    clearScreen();

    printHeader("Student List");

    if (numStudents == 0) {
        cout << "No students found." << endl;
    } else {
        cout << left << setw(5) << "No."
             << setw(20) << "Student ID" 
             << setw(20) << "Name" 
             << setw(10) << "Age" 
             << setw(10) << "GPA"
             << setw(15) << "Course" 
             << "Year" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        
        for (int i = 0; i < numStudents; i++) {
            cout << setw(5) << (i+1)
                 << setw(20) << students[i].studID 
                 << setw(20) << students[i].name 
                 << setw(10) << students[i].age 
                 << setw(10) << students[i].gpa
                 << setw(15) << students[i].course 
                 << students[i].year << endl;
        }
    }

    
    pauseForUser();
}

void updateStudent(int index) {
    if (index < 0 || index >= numStudents) {
        cout << "Invalid student index." << endl;
        return;
    }

    clearScreen(); 

    printHeader("Update Student");

    cout << "Enter updated name: ";
    cin.ignore();  
    getline(cin, students[index].name);

    cout << "Enter updated Student ID: ";
    cin >> students[index].studID;
    cin.ignore();

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

    clearScreen(); 

    for (int i = index; i < numStudents - 1; i++) {
        students[i] = students[i + 1];
    }
    numStudents--;

    cout << "Student deleted successfully." << endl;
}

int main() {
    int choice;

    do {
        clearScreen();
        printMenu();
        cin >> choice;

        if (choice == 1) {
            createStudent();
        } else if (choice == 2) {
            readStudents();
        } else if (choice == 3) {
            cout << "Enter student index to update (1-" << numStudents << "): ";
            int updateIndex;
            cin >> updateIndex;
            updateStudent(updateIndex - 1);
        } else if (choice == 4) {
            cout << "Enter student index to delete (1-" << numStudents << "): ";
            int deleteIndex;
            cin >> deleteIndex;
            deleteStudent(deleteIndex - 1);
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5);


    return 0;
}