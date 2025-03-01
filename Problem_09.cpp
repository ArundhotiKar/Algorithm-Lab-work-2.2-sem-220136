#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    
    for (auto item : items) {
        if (W >= item.weight) {
            totalValue += item.value;
            W -= item.weight;
        } else {
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << fixed << setprecision(2) << fractionalKnapsack(W, items) << endl;

    return 0;
}
