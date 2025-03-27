#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, m; cin >> n >> m;
    map<string, int> sToInd;
    map<int, string> indToS;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        sToInd[s] = i;
        indToS[i] = s;
    }

    vector<set<int>> enemies (n);
    for (int i = 0; i < m; ++i) {
        string u, v; cin >> u >> v;
        enemies[sToInd[u]].insert(sToInd[v]);
        enemies[sToInd[v]].insert(sToInd[u]);
    }

    int best = -1;
    int cnt = -1;
    for (int i = 0; i < pow(2, n); ++i) {
        // printf("cur i: %d\n", i);
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            if ((i & (1 << j)) == 0) continue;
            cur++;
            for (int k = j + 1; k < n; ++k) {
                if (i & (1 << k)) {
                    if (enemies[j].find(k) != enemies[j].end()) {
                        cur = -1;
                        break;
                    }
                }
            }
            if (cur == -1) break;
        }

        if (cur > cnt) {
            best = i;
            cnt = cur;
            // printf("updated cnt to %d\n", cnt);
        }
    }

    printf("%d\n", cnt);
    vector<string> res;
    for (int i = 0; i < n; ++i) {
        if (best & (1 << i)) {
            // printf("%d\n", i);
            // cout << indToS[i] << endl;
            res.push_back(indToS[i]);
        }
    }
    sort(res.begin(), res.end());
    for (string s : res) {
        printf("%s\n", s.c_str());
    }
}