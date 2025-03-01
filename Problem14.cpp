#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void printArray(vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Choose Sorting Algorithm:\n1. Bubble Sort\n2. Selection Sort\n";
    cin >> choice;

    if (choice == 1)
    {
        bubbleSort(arr);
        cout << "Sorted using Bubble Sort: ";
    }
    else if (choice == 2)
    {
        selectionSort(arr);
        cout << "Sorted using Selection Sort: ";
    }
    else
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    printArray(arr);
    return 0;
}
