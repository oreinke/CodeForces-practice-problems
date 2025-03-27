#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

char forceQ (int check, int n, int k, string &str, vector<bool> &visited) {
    if (check >= n || visited[check]) return '?';
    if (str[check] == '?'){
        str[check] = forceQ (check + k, n, k, str, visited);
    } 
    visited[check] = true;
    return str[check];
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        string str; cin >> str;

        vector<bool> visited (n, false);
        set<int> qsI;
        int zeros = 0, ones = 0, qs = 0;
        bool bad = false;
        for (int i = 0; i < k; ++i) {
            char check = forceQ(i + k, n , k, str, visited);
            if (str[i] == '?') {
                str[i] = check; 
            }

            if (str[i] == '1') {
                ones++;
                if (check == '0') bad = true;
            }
            else if (str[i] == '0') {
                zeros++;
                if (check == '1') bad = true;
            }
            else {
                qsI.insert(i);
                qs++;
            }
        }

        
        if (abs(ones - zeros) > qs) bad = true;

        for (int i = 1; i <= n - k && !bad; ++i) {
           if (str[i - 1] == '1') {
                ones--;
            }
            else if (str[i - 1] == '0') {
                zeros--;
            }
            else {
                qsI.erase(i - 1);
                qs--;
            }

            char check = forceQ(i + k - 1 + k, n , k, str, visited);
            if (str[i + k - 1] == '?') {
                str[i + k - 1] = check;
            }
            if (str[i + k - 1] == '1') {
                if (check == '0') bad = true;
                ones++;
            }
            else if (str[i + k - 1] == '0') {
                if (check == '1') bad = true;
                zeros++;
            }
            else {
                qsI.insert(i + k - 1);
                qs++;
            }
            if (abs(ones - zeros) == qs) {
                if (ones > zeros) {
                    for (int ind : qsI) {
                        str[ind] = '0';
                    }
                    zeros = ones;
                }
                else {
                    for (int ind : qsI) {
                        str[ind] = '1';
                    }
                    ones = zeros;
                }
                qsI.clear();
            }
            if (abs(ones - zeros) > qs) bad = true;
        }
        if (bad) {
        cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }

    }
    
}




