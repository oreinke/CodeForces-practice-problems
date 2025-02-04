#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k, q; cin >> n >> k >> q;
        vi distance(k + 1);
        distance[0] = 0;
        for (int i = 1; i <= k; ++i) {
            cin >> distance[i];
        }
        
        map<int, int> time;
        time[0] = 0;
        for (int i = 1 ; i <= k; ++i) {
            int num; cin >> num;
            time[distance[i]] = num;

        }

        for (int i = 0; i < q; ++i) {
            int offer; cin >> offer;
            auto it = lower_bound(distance.begin(), distance.end(), offer);
            if (*it == offer) {
                cout << time[offer] << " ";
            }
            else {
                int e = *it;
                int s = *(it - 1);
                cout << time[s] + ((long long)(offer - s) * (time[e] - time[s]) / (e - s)) << " ";
            }
        }
        cout << endl;
    }
}