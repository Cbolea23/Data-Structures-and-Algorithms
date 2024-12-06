#include <iostream>
#include <vector>
#include <string>

using namespace std;

class NameSorter {
public:
    void bubbleSortNames(vector<string>& names) {
        int n = names.size();
        bool swapped;

        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (names[j] > names[j + 1]) {
                    swap(names[j], names[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};

int main() {
    int numNames;
    cout << "Enter the number of names: ";
    cin >> numNames;

    vector<string> names(numNames);
    cout << "Enter the names:\n";
    for (int i = 0; i < numNames; ++i) {
        cin >> names[i];
    }

    NameSorter sorter;
    sorter.bubbleSortNames(names);

    cout << "Sorted names:\n";
    for (string name : names) {
        cout << name << endl;
    }

    return 0;
}