#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        int resLength = 1e9;
        int curLength = 2;
        string res = "-1";
        int cnt[3] = {0};
        int left = 0, right = 1;
        cnt[s[0] - 'a']++;
        cnt[s[1] - 'a']++;

        while (right < n - 1) {
            if (curLength == 1) {
                right++;
                cnt[s[right] - 'a']++;
            }
            else {
                if ((right - left + 1) > resLength) {
                    cnt[s[left] - 'a']--;
                    left++;
                }
                else if (s[left] != 'a') {
                    cnt[s[left] - 'a']--;
                    left++;
                }
                else if (cnt[1] + cnt[2] - cnt[0] > 2) {

                }
            }
        }
    }
}