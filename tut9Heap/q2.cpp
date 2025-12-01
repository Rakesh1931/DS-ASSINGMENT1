#include <iostream>
using namespace std;

// Heapify for Max-Heap (for increasing order)
void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

// Heapify for Min-Heap (for decreasing order)
void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

// Increasing order (Max-Heap)
void heapSortIncreasing(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    // Heap sort
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapifyMax(arr, i, 0);
    }
}

// Decreasing order (Min-Heap)
void heapSortDecreasing(int arr[], int n) {
    // Build min heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Heap sort
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    // Increasing Order
    heapSortIncreasing(arr, n);
    cout << "Sorted Increasing: ";
    printArray(arr, n);

    // Reset array
    int arr2[] = {12, 11, 13, 5, 6, 7};

    // Decreasing Order
    heapSortDecreasing(arr2, n);
    cout << "Sorted Decreasing: ";
    printArray(arr2, n);

    return 0;
}
