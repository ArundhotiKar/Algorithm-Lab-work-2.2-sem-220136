#include <bits/stdc++.h>
using namespace std;
using namespace chrono; // For measuring time

// Linear Search function
int linearSearch(string arr[], int n, string target, int& comparisons) {
    for (int i = 0; i < n; i++) {
        comparisons++; // Increment comparison count
        if (arr[i] == target)
            return i; // Found
    }
    return -1; // Not found
}

// Binary Search function
int binarySearch(string arr[], int n, string target, int& comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        comparisons++; // Increment comparison count
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid; // Found
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Not found
}

int main() {
    
    const int n = 1000; 
    string names[n];
    for (int i = 0; i < n; i++) {
        names[i] = "User" + to_string(i); // Generate user names like "User0", "User1", ...
    }

    // Target name to search for
    string target = "User999"; // Make sure this name is in the list

    // Linear Search
    int linearComparisons = 0;
    auto startLinear = high_resolution_clock::now();
    int linearIndex = linearSearch(names, n, target, linearComparisons);
    auto endLinear = high_resolution_clock::now();
    auto linearTime = duration_cast<microseconds>(endLinear - startLinear);

    // Binary Search (Requires sorted array)
    int binaryComparisons = 0;
    auto startBinary = high_resolution_clock::now();
    int binaryIndex = binarySearch(names, n, target, binaryComparisons);
    auto endBinary = high_resolution_clock::now();
    auto binaryTime = duration_cast<microseconds>(endBinary - startBinary);

    // Output results
    cout << "Linear Search:\n";
    if (linearIndex != -1)
        cout << "Element found at index: " << linearIndex << "\n";
    else
        cout << "Element not found\n";
    cout << "Comparisons: " << linearComparisons << "\n";
    cout << "Time taken: " << linearTime.count() << " microseconds\n";

    cout << "\nBinary Search:\n";
    if (binaryIndex != -1)
        cout << "Element found at index: " << binaryIndex << "\n";
    else
        cout << "Element not found\n";
    cout << "Comparisons: " << binaryComparisons << "\n";
    cout << "Time taken: " << binaryTime.count() << " microseconds\n";

    return 0;
}
