#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int t; cin >> t;
    while(t--) {
        ull n, m; cin >> n >> m;
        vi nums(n), cnt(n + m, 0), seen(n + m, -1);
        for (int i = 0; i < n; ++i) {
            int num; cin >> num;
            nums[i] = num;
            seen[num - 1] = 0;
        }

        for (int i = 1; i <= m; ++i) {
            int ind, num; cin >> ind >> num;
            ind--;
            cnt[nums[ind] - 1] += i - seen[nums[ind] - 1];
            seen[nums[ind] - 1] = -1;
            nums[ind] = num;
            seen[num - 1] = i;
        }

        ull count = 0;
        for (int i = 0; i < n + m; ++i) {
            if (seen[i] != -1) {
                cnt[i] += m + 1 - seen[i];
            }
            count += (m * (m + 1)) / 2 - ((m - cnt[i]) * (m + 1 - cnt[i])) / 2;
        }

        cout << count <<endl;
    }
}