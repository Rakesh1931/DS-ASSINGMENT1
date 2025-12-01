#include <iostream>
using namespace std;

// Binary Search function (O(log n))
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;  // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Not found
}

// Linear Search function (O(n))
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    // Binary Search
    int binaryIndex = binarySearch(arr, size, key);
    if (binaryIndex != -1)
        cout << "Binary Search: Element found at index " << binaryIndex << endl;
    else
        cout << "Binary Search: Element not found." << endl;

    // Linear Search
    int linearIndex = linearSearch(arr, size, key);
    if (linearIndex != -1)
        cout << "Linear Search: Element found at index " << linearIndex << endl;
    else
        cout << "Linear Search: Element not found." << endl;

    return 0;
}