#include <bits/stdc++.h>
using namespace std;

void findMinMaxNormal(int arr[], int n, int &minVal, int &maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
}

pair<int, int> findMinMaxDivideConquer(int arr[], int low, int high) {
    if (low == high) {
        return {arr[low], arr[low]}; // Only one element, so both min and max are the same
    }
    if (high == low + 1) {
        if (arr[low] < arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }
    int mid = (low + high) / 2;
    pair<int, int> leftMinMax = findMinMaxDivideConquer(arr, low, mid);
    pair<int, int> rightMinMax = findMinMaxDivideConquer(arr, mid + 1, high);
    int minVal = min(leftMinMax.first, rightMinMax.first);
    int maxVal = max(leftMinMax.second, rightMinMax.second);
    return {minVal, maxVal};
}

int main() {
    // Example array
    int arr[] = {12, 3, 5, 7, 19, 4, 1, 15,6,30};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Normal Method (Linear Search)
    int minValNormal, maxValNormal;
    findMinMaxNormal(arr, n, minValNormal, maxValNormal);
    cout << "Normal Method:\n";
    cout << "Minimum: " << minValNormal << ", Maximum: " << maxValNormal << endl;

    // Divide-and-Conquer Method
    pair<int, int> minMaxDivideAndConquer = findMinMaxDivideConquer(arr, 0, n - 1);
    cout << "Divide-and-Conquer Method:\n";
    cout << "Minimum: " << minMaxDivideAndConquer.first << ", Maximum: " << minMaxDivideAndConquer.second << endl;

    return 0;
}