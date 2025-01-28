#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> ind;
    int cnt = 0;
    for (char c : s) {
        if (ind.find(c) == ind.end()) {
            ind[c] = cnt;
            cnt++;
        }
    }

    vi total(ind.size(), 0);
    cnt = 0;
    int start = 0, end = 0;
    total[ind[s[0]]]++;
    cnt++;
    int shortest = n;
    if (cnt == ind.size()) {
        shortest = 1;
    }
    else {
        while (end < n - 1) {
            if (cnt < ind.size()) {
                end++;
                total[ind[s[end]]]++;
                if (total[ind[s[end]]] == 1) {
                    cnt++;
                    if (cnt == ind.size()) {
                        shortest = min(shortest, end - start + 1);
                    }
                }
            } 
            else {
                total[ind[s[start]]]--;
                if (total[ind[s[start]]] == 0) {
                    cnt--;
                }

                start++;
                if (cnt == ind.size()) {
                    shortest = min(shortest, end - start + 1);
                }

                
            }
        }

        while (start < n - 1 && cnt == ind.size()) {
            total[ind[s[start]]]--;
            if (total[ind[s[start]]] == 0) {
                cnt--;
            }

            start++;
            if (cnt == ind.size()) {
                shortest = min(shortest, end - start + 1);
            }

            
        }
    }
    cout << shortest << endl;
}