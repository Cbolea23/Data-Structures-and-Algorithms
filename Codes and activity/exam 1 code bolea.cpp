#include <iostream>
#include <string>

using namespace std;

int main() {
    string toDo_List[10];
    int taskCount;
    char addTask;

    cout <<"Your To-Do List is empty."<<endl<<endl;

    do{
        cout <<"Add a task: ";
        getline(cin, toDo_List[taskCount]);
        taskCount++;

        cout <<"Add another task? (y/n): ";
        cin >> addTask;
        cin.ignore();
        

    }while (addTask == 'y' && taskCount<10);

    for (int t = 0; t <taskCount; t++){
        cout<< t + 1 << ": " << toDo_List[t] <<endl;
    }

    return 0;

}