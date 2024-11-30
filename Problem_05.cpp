#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{

    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == x)
    {
        return mid;
    }

    if (arr[mid] > x)
    {
        return binarySearch(arr, left, mid - 1, x);
    }

    return binarySearch(arr, mid + 1, right, x);
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
    {
        cout << "Element " << x << " found at index " << result << endl;
    }
    else
    {
        cout << "Element " << x << " not found in the array." << endl;
    }

    return 0;
}
