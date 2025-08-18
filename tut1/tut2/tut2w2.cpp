#include <iostream>
using namespace std;

void performBubbleSort(int data[], int totalElements) {
    for (int pass = 0; pass < totalElements - 1; ++pass) {
        for (int index = 0; index < totalElements - pass - 1; ++index) {
            if (data[index] > data[index + 1]) {
                // Swap adjacent elements
                int tempValue = data[index];
                data[index] = data[index + 1];
                data[index + 1] = tempValue;
            }
        }
    }
}

void displayArray(int sortedData[], int length) {
    cout << "Sorted array: ";
    for (int i = 0; i < length; ++i) {
        cout << sortedData[i] << " ";
    }
    cout << endl;
}

int main() {
    int unsortedValues[] = {64, 34, 25, 12, 22, 11, 90};
    int numberOfItems = sizeof(unsortedValues) / sizeof(unsortedValues[0]);

    performBubbleSort(unsortedValues, numberOfItems);
    displayArray(unsortedValues, numberOfItems);

    return 0;
}