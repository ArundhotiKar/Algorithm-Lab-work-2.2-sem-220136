#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 0)
    {
        return; 
    }

    // Step 1: Move n-1 disks from source to auxiliary, using destination as a helper
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move n-1 disks from auxiliary to destination, using source as a helper
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout<<"\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // A = source, C = destination, B = auxiliary

    return 0;
}
