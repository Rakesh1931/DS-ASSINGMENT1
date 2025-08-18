#include <iostream>
#include <vector>
using namespace std;

struct Element {
    int row, col, value;
};

class SparseMatrix {
    int rows, cols;
    vector<Element> data;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int r, int c, int val) {
        if (val != 0)
            data.push_back({r, c, val});
    }

    void display() {
        cout << "Row Col Val\n";
        for (auto& e : data)
            cout << e.row << "   " << e.col << "   " << e.value << endl;
    }

    SparseMatrix transpose() {
        SparseMatrix result(cols, rows);
        for (auto& e : data)
            result.addElement(e.col, e.row, e.value);
        return result;
    }

    SparseMatrix add(SparseMatrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cout << "Addition not possible: dimension mismatch.\n";
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, cols);
        int i = 0, j = 0;
        while (i < data.size() && j < other.data.size()) {
            if (data[i].row < other.data[j].row ||
               (data[i].row == other.data[j].row && data[i].col < other.data[j].col)) {
                result.data.push_back(data[i++]);
            } else if (data[i].row > other.data[j].row ||
                      (data[i].row == other.data[j].row && data[i].col > other.data[j].col)) {
                result.data.push_back(other.data[j++]);
            } else {
                int sum = data[i].value + other.data[j].value;
                if (sum != 0)
                    result.data.push_back({data[i].row, data[i].col, sum});
                i++; j++;
            }
        }

        while (i < data.size()) result.data.push_back(data[i++]);
        while (j < other.data.size()) result.data.push_back(other.data[j++]);

        return result;
    }

    SparseMatrix multiply(SparseMatrix& other) {
        if (cols != other.rows) {
            cout << "Multiplication not possible: dimension mismatch.\n";
            return SparseMatrix(0, 0);
        }

        SparseMatrix result(rows, other.cols);
        SparseMatrix otherT = other.transpose();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (auto& a : data) {
                    if (a.row == i) {
                        for (auto& b : otherT.data) {
                            if (b.row == j && b.col == a.col) {
                                sum += a.value * b.value;
                            }
                        }
                    }
                }
                if (sum != 0)
                    result.addElement(i, j, sum);
            }
        }

        return result;
    }
};

int main() {
    int r1, c1, r2, c2, n, row, col, val;

    cout << "Enter dimensions of Matrix A (rows cols): ";
    cin >> r1 >> c1;
    SparseMatrix A(r1, c1);

    cout << "Enter number of non-zero elements in A: ";
    cin >> n;
    cout << "Enter row col value for each:\n";
    for (int i = 0; i < n; ++i) {
        cin >> row >> col >> val;
        A.addElement(row, col, val);
    }

    cout << "\nMatrix A:\n";
    A.display();

    cout << "\nTranspose of A:\n";
    SparseMatrix AT = A.transpose();
    AT.display();

    cout << "\nEnter dimensions of Matrix B (rows cols): ";
    cin >> r2 >> c2;
    SparseMatrix B(r2, c2);

    cout << "Enter number of non-zero elements in B: ";
    cin >> n;
    cout << "Enter row col value for each:\n";
    for (int i = 0; i < n; ++i) {
        cin >> row >> col >> val;
        B.addElement(row, col, val);
    }

    cout << "\nMatrix B:\n";
    B.display();

    cout << "\nA + B:\n";
    SparseMatrix sum = A.add(B);
    sum.display();

    cout << "\nA × B:\n";
    SparseMatrix product = A.multiply(B);
    product.display();

    return 0;
}