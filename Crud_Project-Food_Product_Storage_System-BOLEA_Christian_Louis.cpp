#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;
//CHRISTIAN LOUIS BOLEA
const int MAX_product = 100;

struct FoodProduct {
    string prodID;
    string fName;
    string quantiy;
    string price;
    string expire; 
    string delivery;
    string category;
          
};

FoodProduct product[MAX_product];
int numproduct = 0;

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
    printHeader("Food Product Storage System");
    
    cout << "| 1. Add Product to System              |" << endl;
    cout << "| 2. View Products                      |" << endl;
    cout << "| 3. Update Data                        |" << endl;
    cout << "| 4. Delete Data                        |" << endl;
    cout << "| 5. Exit                               |" << endl;
    cout << "+---------------------------------------+" << endl;
    cout << "Enter your choice: ";
}

void pauseForUser() {
    
    cout << "Press Enter to return to the menu..." << endl;
    cin.ignore();
    cin.get();  
}

void createProduct() {
    if (numproduct >= MAX_product) {
        cout << "Maximum number of Product reached." << endl;
        return;
    }

    clearScreen(); 

    printHeader("Create New Food Product");

    cout << "Enter Food name: ";
    cin.ignore();  
    getline(cin, product[numproduct].fName);

    cout << "Enter Food ID: ";
    cin >> product[numproduct].prodID;
    cin.ignore();

    cout << "Enter Quantity: ";
    cin >> product[numproduct].quantiy;

    cout << "Enter Per price: ";
    cin >> product[numproduct].price;
    cin.ignore();

    cout << "Enter Category(dairy, vegetable, meat, etc...): ";
    cin >> product[numproduct].category;
    cin.ignore();    

    cout << "Enter Expiration Date (M/D/Y): ";
    getline(cin, product[numproduct].expire);

    cout << "Enter Delivery Date (M/D/Y): ";
    cin >> product[numproduct].delivery;
    cin.ignore();

    

    numproduct++;
    cout << "Product added successfully." << endl;
    cin.ignore();
    
}

void readProduct() {
    clearScreen();

    printHeader("Food Product List");

    if (numproduct == 0) {
        cout << "No Food data found." << endl;
    } else {
        cout << left << setw(5) << "No."
             << setw(20) << "Product ID" 
             << setw(20) << "Food Name" 
             << setw(20) << "Quantity" 
             << setw(20) << "Category"
             << setw(20) << "Per Price"
             << setw(20) << "Expiration Date"  
             << "Delivery Date" << endl;
        cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        
        for (int i = 0; i < numproduct; i++) {
            cout << setw(5) << (i+1)
                 << setw(20) << product[i].prodID 
                 << setw(20) << product[i].fName 
                 << setw(20) << product[i].quantiy
                << setw(20) << product[i].category
                 << setw(1) << "$ " << setw(20) << product[i].price
                 << setw(20) << product[i].expire 
                 << product[i].delivery << endl;
        }
    }

    
    pauseForUser();
}

void updateProduct(int index) {
    if (index < 0 || index >= numproduct) {
        cout << "Invalid Food Product index." << endl;
        return;
    }

    clearScreen(); 

    printHeader("Update Food Product Data");

    cout << "Enter updated Food name: ";
    cin.ignore();  
    getline(cin, product[index].fName);

    cout << "Enter updated Product ID: ";
    cin >> product[index].prodID;
    cin.ignore();

    cout << "Enter updated Quantity: ";
    cin >> product[index].quantiy;

    cout << "Enter updated Price per Food: ";
    cin >> product[index].price;
    cin.ignore(); 

    cout << "Enter updated Category: ";
    cin >> product[index].category;
    cin.ignore(); 

    cout << "Enter updated Expiration date: ";
    getline(cin, product[index].expire);

    cout << "Enter updated Delivery Date: ";
    cin >> product[index].delivery;
    cin.ignore(); 

    cout << "Data updated successfully." << endl;
    cin.ignore();
}

void deleteProduct(int index) {
    if (index < 0 || index >= numproduct) {
        cout << "Invalid Food product index." << endl;
        return;
    }

    clearScreen(); 

    for (int i = index; i < numproduct - 1; i++) {
        product[i] = product[i + 1];
    }
    numproduct--;

    cout << "Food Product deleted successfully." << endl;
}

int main() {
    int choice;

    do {
        clearScreen();
        printMenu();
        cin >> choice;

        if (choice == 1) {
            createProduct();
        } else if (choice == 2) {
            readProduct();
        } else if (choice == 3) {
            cout << "Enter Food product index (1-" << numproduct << "): ";
            int updateIndex;
            cin >> updateIndex;
            updateProduct(updateIndex - 1);
        } else if (choice == 4) {
            cout << "Enter Food product index to delete (1-" << numproduct << "): ";
            int deleteIndex;
            cin >> deleteIndex;
            deleteProduct(deleteIndex - 1);
        } else if (choice == 5) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }
    } while (choice != 5);


    return 0;
}