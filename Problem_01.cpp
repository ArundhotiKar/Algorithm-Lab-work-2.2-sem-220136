#include <bits/stdc++.h>
using namespace std;
using namespace chrono; 

void findMaxMin(const vector<int>& arr) 
{
    int maxVal = arr[0], minVal = arr[0];
    int comparisons = 0; 
    for (int i = 1; i < arr.size(); ++i) {
        comparisons++;
        if (arr[i] > maxVal) maxVal = arr[i];
        comparisons++;
        if (arr[i] < minVal) minVal = arr[i];
    }
    cout << "Max: " << maxVal << ", Min: " << minVal << "\n";
    cout << "Number of comparisons: " << comparisons << "\n";
}

int main() {
    
    int n = 100000; 
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100000; 
    }

    // Measure the time taken
    auto start = high_resolution_clock::now();
    findMaxMin(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "Time taken: " << duration.count() << " microseconds\n";
    return 0;
}
