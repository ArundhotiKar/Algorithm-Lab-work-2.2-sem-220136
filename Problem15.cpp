#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void primsAlgorithm(int n, vector<vector<pii>> &adj) 
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> inMST(n, false);
    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);

    key[0] = 0; 
    pq.push({0, 0}); 

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u]) continue;
        inMST[u] = true;

        for (auto &[weight, v] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Minimum Spanning Tree Edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u}); 
    }

    primsAlgorithm(n, adj);

    return 0;
}
