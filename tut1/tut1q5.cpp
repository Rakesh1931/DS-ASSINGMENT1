#include <iostream>
using namespace std;

int main() {
    int mat[10][10];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    // Sum of each row
    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += mat[i][j];
        }
        cout << "Row " << i << ": " << rowSum << endl;
    }

    // Sum of each column
    cout << "\nSum of each column:" << endl;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += mat[i][j];
        }
        cout << "Column " << j << ": " << colSum << endl;
    }

    return 0;
}