#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n; cin >> n;

    vector<string> rawNums;
    vector<int> nums;

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        string rawNum; cin >> rawNum;
        rawNums.push_back(rawNum);

        int num = floor(stod(rawNum.substr(0)));

        sum += num;
        nums.push_back(num);
        // cout <<"i: " << i << ", raw: " << rawNum << ", num: " << num << endl;
        fflush(stdout);
    }

    for (int i = 0; i < n; ++i) {
        
        if (sum != 0 && rawNums[i].substr(rawNums[i].length() - 5) != "00000") {
            cout << nums[i] + 1 << endl;
            sum++;
        }
        else {
            cout << nums[i] << endl;           
        }
    }
}