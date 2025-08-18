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

    void removeDuplicates() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; ) {
                if (arr[i] == arr[j]) {
                    for (int k = j; k < size - 1; k++) {
                        arr[k] = arr[k + 1];
                    }
                    size--;
                } else {
                    j++;
                }
            }
        }

        cout << "Duplicates removed. Array now contains unique elements." << endl;
    }

    void reverseArray() {
        if (size == 0) {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0, j = size - 1; i < j; i++, j--) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        cout << "Array reversed." << endl;
    }

    void matrixMultiplication() {
        int A[10][10], B[10][10], C[10][10];
        int m, n, p, q;

        cout << "Enter rows and columns of Matrix A: ";
        cin >> m >> n;
        cout << "Enter rows and columns of Matrix B: ";
        cin >> p >> q;

        if (n != p) {
            cout << "Matrix multiplication not possible! Columns of A must equal rows of B." << endl;
            return;
        }

        cout << "Enter elements of Matrix A:" << endl;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        cout << "Enter elements of Matrix B:" << endl;
        for (int i = 0; i < p; i++)
            for (int j = 0; j < q; j++)
                cin >> B[i][j];

        // Initialize result matrix
        for (int i = 0; i < m; i++)
            for (int j = 0; j < q; j++)
                C[i][j] = 0;

        // Multiply
        for (int i = 0; i < m; i++)
            for (int j = 0; j < q; j++)
                for (int k = 0; k < n; k++)
                    C[i][j] += A[i][k] * B[k][j];

        cout << "Resultant Matrix (A × B):" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++)
                cout << C[i][j] << " ";
            cout << endl;
        }
    }

    void transposeMatrix() {
        int mat[10][10], trans[10][10];
        int rows, cols;

        cout << "Enter rows and columns of the matrix: ";
        cin >> rows >> cols;

        cout << "Enter matrix elements:" << endl;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cin >> mat[i][j];

        // Transpose logic
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                trans[j][i] = mat[i][j];

        cout << "Transposed Matrix:" << endl;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++)
                cout << trans[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    ArrayOperations ao;
    int choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE ARRAY\n";
        cout << "2. DISPLAY ARRAY\n";
        cout << "3. INSERT ELEMENT\n";
        cout << "4. DELETE ELEMENT\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. REMOVE DUPLICATES\n";
        cout << "7. REVERSE ARRAY\n";
        cout << "8. MATRIX MULTIPLICATION\n";
        cout << "9. MATRIX TRANSPOSE\n";
        cout << "10. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ao.create(); break;
            case 2: ao.display(); break;
            case 3: ao.insert(); break;
            case 4: ao.remove(); break;
            case 5: ao.linearSearch(); break;
            case 6: ao.removeDuplicates(); break;
            case 7: ao.reverseArray(); break;
            case 8: ao.matrixMultiplication(); break;
            case 9: ao.transposeMatrix(); break;
            case 10: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 10);

    return 0;
}