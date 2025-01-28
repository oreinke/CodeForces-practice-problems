#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = -1;
        for (int i = 2; i <= min(7, n); ++i) {
            if (res != -1)
                break;
            int cnt[] = {0, 0, 0};
            int left = 0, right = i - 1;
            for (int j = 0; j < i; j++) {
                cnt[s[j] - 'a']++;
            }
            if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                res = i;
                break;
            }

            while (right < n - 1) {
                cnt[s[left] - 'a']--;
                left++;
                right++;
                cnt[s[right] - 'a']++;

                if (cnt[0] > cnt[1] && cnt[0] > cnt[2]) {
                    res = i;
                    break;
                }
            }
        }
        cout << res << endl;
    }
}