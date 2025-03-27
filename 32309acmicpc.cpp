#include <bits/stdc++.h>

using namespace std;

int perm (int step, vector<int> &order, vector<bool> &visited, vector<vector<int>> &bad, vector<vector<int>> &badConsec) {
    if (step == order.size()) return 1;
    int sum = 0;
    for (int i = 0; i < order.size(); ++i) {
        if (visited[i]) continue;
        bool invalid = false;
        for (int b : bad[i]) {
            if (!visited[b]) invalid = true;
        }
        for (int b : badConsec[i]) {
            if (step != 0 && order[step - 1] == b) invalid = true;
        }
        if (!invalid) {
            visited[i] = true;
            order[step] = i;
            sum += perm(step + 1, order, visited, bad, badConsec);
            visited[i] = false;
        }
    }
    return sum;
}

int main() {
    int n, r; cin >> n >> r;
    vector<int> order (n); 
    vector<vector<int>> bad (n), badConsec (n);
    vector<bool> visited (n, false);

    for (int i = 0; i < r; ++i) {
        int control; cin >> control;
        char x, y; cin >> x >> y;
        if (2 == control) {
            bad[x - 'A'].push_back(y - 'A');
        }
        else if (1 == control) {
            bad[y - 'A'].push_back(x - 'A');
        }
        else {
            badConsec[x - 'A'].push_back(y - 'A');
            badConsec[y - 'A'].push_back(x - 'A');
        }
    }

    cout << perm(0, order, visited, bad, badConsec) << endl;
}