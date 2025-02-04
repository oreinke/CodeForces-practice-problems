#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n; cin >> n;
    vector<set<int>> adj(n);
    vector<pair<int, int>> edges;
    int node3 = -1;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        edges.emplace_back(u, v);
        
        adj[u].insert(v);
        adj[v].insert(u);
        if (node3 == -1) {
            if (adj[u].size() >= 3) {
                node3 = u;
                // cout << "node3 set on " << i << ", u = " << u<< endl;
            }
            else if (adj[v].size() >= 3) {
                node3 = v;
                // cout << "node3 set on " << i << ", v = " << v<< endl;

            }
        }
    }


    // cout << "node3: " << node3 << endl;
    if (node3 == -1) {
        for (int i = 0; i < n - 1; ++i) {
            cout << i << endl;
        }
    }
    else {
        int cnt = 2;
        int label = 3;
        bool found = false;
        for (int i = 0; i < n - 1; ++i) {
            if (cnt >= 0 && (edges[i].first == node3 || edges[i].second == node3)) {
                printf("%d\n", cnt);
                cnt--;
            }
            else {
                printf("%d\n", label);
                label++;
            }
        }

    }
    

}