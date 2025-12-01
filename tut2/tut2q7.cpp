#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i); // All remaining elements in L are greater than R[j]
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    return inv_count;
}

long long countInversions(int arr[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += countInversions(arr, left, mid);
        inv_count += countInversions(arr, mid + 1, right);
        inv_count += mergeAndCount(arr, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    long long result = countInversions(arr, 0, n - 1);
    cout << "Number of inversions: " << result << endl;

    return 0;
}


// brute force solution
// #include <iostream>
// using namespace std;

// int countInversions(int arr[], int n) {
//     int count = 0;
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[i] > arr[j]) {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     int arr[] = {2, 4, 1, 3, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Number of inversions: " << countInversions(arr, n) << endl;
//     return 0;
// }