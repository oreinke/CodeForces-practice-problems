#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi val (n);
        vector<map<int, int>> adjC (n);
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            num--;
            val[i] = num;
            adjC[i][num]++;
        } 
        vector<vector<int>> adjL (n);

        for (int i = 0; i < n - 1; ++i) {
            int u, v; cin >> u >> v;
            u--;
            v--;
            adjL[u].push_back(v);
            adjL[v].push_back(u);
            adjC[u][val[v]]++;
            adjC[v][val[u]]++;
        }
        // cout << "HIT\n";
        // fflush(stdout);
        vector<bool> maj (n, false);
        for(int i = 0; i < n; ++i) {
            if (maj[val[i]]) continue;
            for (int v : adjL[i]) {
                if (adjC[v][val[i]] > 1) maj[val[i]] = true;
            }
        }
        for (bool v : maj) {
            if (v) printf("1");
            else printf("0");
        }
        printf("\n");


    }   
}