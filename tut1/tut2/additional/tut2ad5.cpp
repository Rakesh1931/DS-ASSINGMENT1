#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int possible = 0;
    int i = 0;
    // First pass: count how many 2s can be duplicated
    while (i + possible < n) {
        if (arr[i] == 2) {
            if (i + possible == n - 1) break; // Edge case: last 2 can't be duplicated
            possible++;
        }
        i++;
    }

    int last = i - 1;
    // Second pass: shift and duplicate from the end
    for (int j = last; j >= 0; j--) {
        if (arr[j] == 2) {
            if (j + possible < n) arr[j + possible] = 2;
            possible--;
            if (j + possible < n) arr[j + possible] = 2;
        } else {
            if (j + possible < n) arr[j + possible] = arr[j];
        }
    }
}
int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}