// // using binary approach

// #include <iostream>
// using namespace std;

// int locateMissingBinary(int sequence[], int fullSize) {
//     int begin = 0, end = fullSize - 2;

//     while (begin <= end) {
//         int middle = begin + (end - begin) / 2;

//         if (sequence[middle] == middle + 1) {
//             begin = middle + 1;
//         } else {
//             end = middle - 1;
//         }
//     }

//     return begin + 1;
// }

// int main() {
//     int sortedSequence[] = {1, 2, 3, 4, 6, 7, 8};  // Missing 5
//     int sequenceSize = sizeof(sortedSequence) / sizeof(sortedSequence[0]) + 1;

//     int missingDigit = locateMissingBinary(sortedSequence, sequenceSize);
//     cout << "Binary Search: Missing number is " << missingDigit << endl;

//     return 0;
// }


// linear time approach

#include <iostream>
using namespace std;

int findMissingLinear(int sortedList[], int totalCount) {
    for (int scanIndex = 0; scanIndex < totalCount - 1; ++scanIndex) {
        if (sortedList[scanIndex] != scanIndex + 1) {
            return scanIndex + 1;
        }
    }
    return totalCount;  // If last number is missing
}

int main() {
    int inputArray[] = {1, 2, 3, 4, 6, 7, 8};  // Missing 5
    int arrayLength = sizeof(inputArray) / sizeof(inputArray[0]) + 1;

    int missingValue = findMissingLinear(inputArray, arrayLength);
    cout << "Linear Search: Missing number is " << missingValue << endl;

    return 0;
}