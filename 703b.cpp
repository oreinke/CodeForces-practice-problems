#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> cities(n);
    unsigned long long citySum = 0;
    for (auto &x : cities){
        cin >> x;
        citySum += x;
    } 
    set<int> capital;
    vector<int> capitals(k);
    unsigned long long capSum = 0;
    for (int i = 0; i < k; ++i) {
        int cap;
        cin >> cap;
        cap--;
        capital.insert(cap);
        capitals[i] = cap;
        capSum += cities[cap];
    }
    citySum -= capSum;
    unsigned long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += cities[i] * cities[(i + 1) % n];
    }

    unsigned long long capTotal = 0;
    for (int i = 0; i < k; i++) {
        int curCap = capitals[i];
        total += citySum * cities[curCap];
        capTotal += (capSum - cities[curCap]) * cities[curCap];
        if (capital.find(((curCap - 1 < 0) ? n - 1 : curCap - 1)) == capital.end()) {
            total -= cities[((curCap - 1 < 0) ? n - 1 : curCap - 1)] * cities[curCap];
        }
        total -= cities[(curCap + 1) % n] * cities[curCap];
    }

    total += capTotal / 2;
    cout << total << endl;
}