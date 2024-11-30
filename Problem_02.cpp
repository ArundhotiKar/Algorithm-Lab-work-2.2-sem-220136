#include <bits/stdc++.h>
using namespace std;
using namespace chrono; 

int binarySearch(int arr[], int n, int target, int& comparisons) {
    int left = 0, right = n - 1;

    while (left <= right) {
        comparisons++; 
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; 
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1; 
    }
    return -1; 
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 7; 
    int comparisons = 0; 
    // Measure time taken by the binary search
    auto start = high_resolution_clock::now();
    int index = binarySearch(arr, n, target, comparisons);
    auto end = high_resolution_clock::now();

    // Calculate the duration
    auto duration = duration_cast<nanoseconds>(end - start);

    
    if (index != -1)
        cout << "Element found at index: " << index << "\n";
    else
        cout << "Element not found\n";

    cout << "Number of comparisons: " << comparisons << "\n";
    cout << "Time taken: " << duration.count() << " nanoseconds\n";

    return 0;
}
