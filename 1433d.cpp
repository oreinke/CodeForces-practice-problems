#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nGangs = 0;
        map<int, int> gangToIndex;
        vector<int> rep;
        vector<vector<int>> districts(5000);
        for (int i = 1; i <= n; ++i) {
            int g;
            cin >> g;
            if (gangToIndex.find(g) == gangToIndex.end()) {
                gangToIndex[g] = nGangs;
                nGangs++;
                rep.push_back(i);
            }
            districts[gangToIndex[g]].push_back(i);
            
        }
        if (nGangs == 1) {
            cout << "NO\n";
        } 
        else {
            cout << "YES\n";
            for (int i = 0; i < nGangs - 1; i++) {
                for (int g : districts[(i + 1) % (nGangs)]) {
                    cout << rep[i] << " " << g << endl;
                }
            }
            for (int g : districts[(0) % (nGangs)]) {
                if (g != rep[0]) {
                    cout << rep[nGangs - 1] << " " << g << endl;
                }
            }
        }
    }
}