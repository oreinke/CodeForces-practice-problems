#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, m; cin >> n >> m;

    int start;
    vector<vector<int>> edges(n); 
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
        start = u;
    }
    int step = 0;
    int last;
    queue<int> frontier;
    frontier.push(start);
    vector<bool> visited(n, false);
    while(!frontier.empty()) {
        step++;
        queue<int> next;
        while (!frontier.empty()) {
            int source = frontier.front();
            frontier.pop();
            if (visited[source]) {
                continue;
            }
            last = source;
            visited[source] = true;
            for (int d : edges[source]) {
                if (!visited[d]) {
                    next.push(d);
                }
            }
        }
        frontier = next;
    }

    step = 0;
    frontier.push(last);
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }


    while(!frontier.empty()) {
        step++;
        queue<int> next;
        while (!frontier.empty()) {
            int source = frontier.front();
            frontier.pop();
            if (visited[source]) {
                continue;
            }
            last = source;
            visited[source] = true;
            for (int d : edges[source]) {
                if (!visited[d]) {
                    next.push(d);
                }
            }
        }
        frontier = next;
    }

    cout << step - 1 << endl;


}
