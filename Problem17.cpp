#include <bits/stdc++.h>
using namespace std;

#define N 10  

bool isSafe(int v, vector<vector<int>> &graph, vector<int> &path, int pos) {
    if (graph[path[pos - 1]][v] == 0) 
        return false;
    
    for (int i = 0; i < pos; i++) 
        if (path[i] == v) 
            return false;

    return true;
}

bool hamiltonianCycleUtil(vector<vector<int>> &graph, vector<int> &path, int pos, int n) {
    if (pos == n) {
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < n; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, n)) 
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(vector<vector<int>> &graph, int n) {
    vector<int> path(n, -1);
    path[0] = 0;  

    if (!hamiltonianCycleUtil(graph, path, 1, n)) {
        cout << "No Hamiltonian Cycle found\n";
        return;
    }

    cout << "Hamiltonian Cycle: ";
    for (int i = 0; i < n; i++) 
        cout << path[i] << " ";
    cout << path[0] << endl;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    hamiltonianCycle(graph, n);
    return 0;
}
