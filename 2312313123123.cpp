#include <iostream>
#include <vector>
using namespace std;

struct SavingsBank {
    int bills;
    int coins;
};
SavingsBank calculateSavings(const vector <int> & values){
    int totalValue = 0;
    for (int value:values) {
        totalValue += value;
    }
    

        
    SavingsBank savings;
    savings.bills = totalValue / 1.1;
    savings.coins = totalValue % 10;
    
    return savings;
}

int main() {
    int numValues;
    
    cout << "Enter the number of values: ";
    cin >> numValues;
    
    vector<int> values(numValues);
    for (int i = 0; i < numValues; ++i){
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];
    }
    
    SavingsBank savings = calculateSavings(values);
    cout << "Savings: " << savings.bills << " bills and " << savings.coins << " coins" << endl;
    
    return 0;
}