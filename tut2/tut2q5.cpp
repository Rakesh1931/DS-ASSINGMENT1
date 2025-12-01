#include <iostream>
using namespace std;

// Diagonal Matrix
class DiagonalMatrix {
    int* data;
    int n;
public:
    DiagonalMatrix(int size) : n(size) {
        data = new int[n];
    }
    void set(int i, int j, int val) {
        if (i == j) data[i - 1] = val;
    }
    int get(int i, int j) {
        return (i == j) ? data[i - 1] : 0;
    }
    ~DiagonalMatrix() {
       delete[] data; 
      }
};

// Tri-diagonal Matrix
class TriDiagonalMatrix {
    int* data;
    int n;
public:
    TriDiagonalMatrix(int size) : n(size) {
        data = new int[3 * n - 2];
    }
    void set(int i, int j, int val) {
        if (i - j == 1) data[i - 2] = val;
        else if (i == j) data[n - 1 + i - 1] = val;
        else if (j - i == 1) data[2 * n - 1 + i - 1] = val;
    }
    int get(int i, int j) {
        if (i - j == 1) return data[i - 2];
        else if (i == j) return data[n - 1 + i - 1];
        else if (j - i == 1) return data[2 * n - 1 + i - 1];
        else return 0;
    }
    ~TriDiagonalMatrix() { 
      delete[] data; 
    }
};

// Lower Triangular Matrix
class LowerTriangularMatrix {
    int* data;
    int n;
public:
    LowerTriangularMatrix(int size) : n(size) {
        data = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int val) {
        if (i >= j) data[i * (i - 1) / 2 + j - 1] = val;
    }
    int get(int i, int j) {
        return (i >= j) ? data[i * (i - 1) / 2 + j - 1] : 0;
    }
    ~LowerTriangularMatrix() { 
      delete[] data; 
    }
};

// Upper Triangular Matrix
class UpperTriangularMatrix {
    int* data;
    int n;
public:
    UpperTriangularMatrix(int size) : n(size) {
        data = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int val) {
        if (i <= j) data[i * n - (i - 1) * i / 2 + j - i] = val;
    }
    int get(int i, int j) {
        return (i <= j) ? data[i * n - (i - 1) * i / 2 + j - i] : 0;
    }
    ~UpperTriangularMatrix() {
       delete[] data; 
      }
};

// Symmetric Matrix
class SymmetricMatrix {
    int* data;
    int n;
public:
    SymmetricMatrix(int size) : n(size) {
        data = new int[n * (n + 1) / 2];
    }
    void set(int i, int j, int val) {
        if (i >= j) data[i * (i - 1) / 2 + j - 1] = val;
        else data[j * (j - 1) / 2 + i - 1] = val;
    }
    int get(int i, int j) {
        return (i >= j) ? data[i * (i - 1) / 2 + j - 1] : data[j * (j - 1) / 2 + i - 1];
    }
    ~SymmetricMatrix() { 
      delete[] data; 
    }
};

// Display matrix
void displayMatrix(auto& matrix, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << matrix.get(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, n, i, j, val;
    cout << "Enter matrix size (n x n): ";
    cin >> n;

    while (true) {
        cout << "\nChoose Matrix Type:\n";
        cout << "1. Diagonal\n2. Tri-diagonal\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n6. Exit\nChoice: ";
        cin >> choice;

        if (choice == 6) break;

        switch (choice) {
        case 1: {
            DiagonalMatrix mat(n);
            cout << "Enter diagonal elements:\n";
            for (i = 1; i <= n; ++i) {
                cout << "Element [" << i << "," << i << "]: ";
                cin >> val;
                mat.set(i, i, val);
            }
            cout << "Matrix:\n";
            displayMatrix(mat, n);
            break;
        }
        case 2: {
            TriDiagonalMatrix mat(n);
            cout << "Enter tri-diagonal elements:\n";
            for (i = 1; i <= n; ++i) {
                for (j = max(1, i - 1); j <= min(n, i + 1); ++j) {
                    cout << "Element [" << i << "," << j << "]: ";
                    cin >> val;
                    mat.set(i, j, val);
                }
            }
            cout << "Matrix:\n";
            displayMatrix(mat, n);
            break;
        }
        case 3: {
            LowerTriangularMatrix mat(n);
            cout << "Enter lower triangular elements:\n";
            for (i = 1; i <= n; ++i) {
                for (j = 1; j <= i; ++j) {
                    cout << "Element [" << i << "," << j << "]: ";
                    cin >> val;
                    mat.set(i, j, val);
                }
            }
            cout << "Matrix:\n";
            displayMatrix(mat, n);
            break;
        }
        case 4: {
            UpperTriangularMatrix mat(n);
            cout << "Enter upper triangular elements:\n";
            for (i = 1; i <= n; ++i) {
                for (j = i; j <= n; ++j) {
                    cout << "Element [" << i << "," << j << "]: ";
                    cin >> val;
                    mat.set(i, j, val);
                }
            }
            cout << "Matrix:\n";
            displayMatrix(mat, n);
            break;
        }
        case 5: {
            SymmetricMatrix mat(n);
            cout << "Enter symmetric matrix elements (lower triangle):\n";
            for (i = 1; i <= n; ++i) {
                for (j = 1; j <= i; ++j) {
                    cout << "Element [" << i << "," << j << "]: ";
                    cin >> val;
                    mat.set(i, j, val);
                }
            }
            cout << "Matrix:\n";
            displayMatrix(mat, n);
            break;
        }
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}