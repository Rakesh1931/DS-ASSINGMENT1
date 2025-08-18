#include <iostream>
using namespace std;

const int MAX = 100;

class ArrayOperations {
private:
    int arr[MAX];
    int size;

public:
    ArrayOperations() {
        size = 0;
    }

    void create() {
        cout << "Enter number of elements: ";
        cin >> size;
        if (size > MAX) {
            cout << "Size exceeds maximum limit!" << endl;
            size = 0;
            return;
        }
        cout << "Enter " << size << " elements:" << endl;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insert() {
        if (size >= MAX) {
            cout << "Array is full! Cannot insert." << endl;
            return;
        }
        int pos, val;
        cout << "Enter position to insert (0 to " << size << "): ";
        cin >> pos;
        if (pos < 0 || pos > size) {
            cout << "Invalid position!" << endl;
            return;
        }
        cout << "Enter value to insert: ";
        cin >> val;
        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = val;
        size++;
        cout << "Element inserted." << endl;
    }

    void remove() {
        if (size == 0) {
            cout << "Array is empty! Cannot delete." << endl;
            return;
        }
        int pos;
        cout << "Enter position to delete (0 to " << size - 1 << "): ";
        cin >> pos;
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted." << endl;
    }

    void linearSearch() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        int val, found = -1;
        cout << "Enter value to search: ";
        cin >> val;
        for (int i = 0; i < size; i++) {
            if (arr[i] == val) {
                found = i;
                break;
            }
        }
        if (found != -1)
            cout << "Value found at position: " << found << endl;
        else
            cout << "Value not found in array." << endl;
    }
};

int main() {
    ArrayOperations ao;
    int choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ao.create(); break;
            case 2: ao.display(); break;
            case 3: ao.insert(); break;
            case 4: ao.remove(); break;
            case 5: ao.linearSearch(); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);

    return 0;
}