// #include <bits/stdc++.h>

// using namespace std;

// int popcount(int x) {
//     int cnt = 0;
//     while (x > 0) {
//         cnt += x % 2;
//         x = x >> 1;
//     }

//     return cnt;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         unsigned long long n, m;
//         cin >> n >> m;

//         n %= m;
//         if (n == 0) {
//             cout << "0\n";
//         }
//         else if (popcount(m / gcd(n, m)) > 1) {
//             cout << "-1\n";
//         }
//         else {
//             cout << popcount(gcd(n, m)) * m << endl;
//         }
        
//     }
// }


    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        int t;
        cin >> t;
        while (t--) {
            unsigned long long n, m;
            cin >> n >> m;
            unsigned long long cnt = 0;
            set<int> seen;
            n %= m;
            int maxOps = 30;
            while (n != 0 && seen.find(n % m) == seen.end() && maxOps > 0) {
                n = n % m;
                cnt += n;
                seen.insert(n);
     
                n *= 2;
                maxOps--;
            }
     
            if (n != 0) {
                cout << "-1\n";
            }
            else {
                cout << cnt << endl;
            }
        }
    }