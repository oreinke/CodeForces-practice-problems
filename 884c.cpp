#include <bits/stdc++.h>

using namespace std;

long long dfs (int u, vector<vector<int>> &adjL, vector<bool> &visited) {
    if (visited[u]) return 0;
    long long res = 1;
    visited[u] = true;
    for (int v : adjL[u]) res += dfs(v, adjL, visited);
    return res;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> adjL (n + 1);
    for (int i = 1 ; i <= n; ++i) {
        int num; cin >> num;
        adjL[i].push_back(num);
    }

    vector<bool> visited(n + 1, false);
    vector<long long> sizes;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            sizes.push_back(dfs(i, adjL, visited));
        }
    }

    sort(sizes.rbegin(), sizes.rend());
    long long res = 0;
    for (int i = 0; i < min(2, (int) sizes.size()); ++i) {
        res += sizes[i];
    }
    res *= res;
    for (int i = 2; i < sizes.size(); ++i) {
        res += sizes[i] * sizes[i];
    }
    cout << res << endl;
}