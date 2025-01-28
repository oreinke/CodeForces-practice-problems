#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

void addEdge(int s, int e, vector<pair<int, int>> &edges) {
    printf("? %d %d\n", s, e);
    fflush(stdout);
    int c; cin >> c;
    if (c == s || c == e) {
        edges.push_back({s, e});
    }
    else {
        addEdge(s, c, edges);
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pair<int, int>> edges;

        for (int i = 1; i < n; ++i) {
            addEdge(i, n, edges);
        }

        cout << "!";
        for (auto [x, y] : edges) {
            cout << " " << x << " " << y;
        }
        cout << endl;
    }   
}