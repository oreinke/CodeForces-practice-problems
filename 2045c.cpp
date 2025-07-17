#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2; cin >> str1 >> str2;
    vector<int> pre (26, -1), suf (26, -1);
    for (int i = 1; i < str1.size(); ++i) {
        if (pre[str1[i] - 'a'] == -1) pre[str1[i] - 'a'] = i + 1;
    }

    for (int i = str2.size() - 2; i >= 0; --i) {
        if (suf[str2[i] - 'a'] == -1) suf[str2[i] - 'a'] = str2.size() - i;
    }

    int best = -1;
    int bestI = -1;
    for (int i = 0; i < 26; ++i) {
        if (pre[i] == -1 || suf[i] == -1) continue;
        if (best == -1 || best > pre[i] + suf[i]) {
            best = pre[i] + suf[i];
            bestI = i;
        } 
    }
    cout << str1.substr(0, pre[bestI] - 1) << str2.s

    
}