#include <iostream>
using namespace std;

struct SavingsBank {
    int bills;
    int coins;
};

int main() {
    SavingsBank savings;
    int numValues;
    
    cout << "Enter the number of values: ";
    cin >> numValues;
    
    for (int i = 0; i < numValues; ++i){
        int value;
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        
        if (i % 2 == 0){
            savings.bills += value;
        } else{
            savings.coins += value;
        }
    }
    
    cout << "Savings: " << savings.bills << " bills and " << savings.coins << " coins" << endl;
    
    return 0;
}