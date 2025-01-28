#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) { 
        string str;
        cin >> str;

        bool inSeq = false;
        int count = 0;
        long long choices = 1;
        int seqCount = 1;;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                if (inSeq) {
                    seqCount++;
                    count++;
                }
                else {
                    count++;
                    seqCount = 2;
                    inSeq = true;
                }
            }
            else {
                if (inSeq) {
                    choices = (choices * 1LL * seqCount) % 998244353;
                    seqCount = 1;
                }
                inSeq = false;
            }
        }
        choices = (choices * seqCount) % 998244353;
        long long factorial = 1;
        for (int i = 2; i <= count; i++) {
            factorial = (factorial * i) % 998244353;
        }
        choices = (choices * factorial) % 998244353;


        printf("%d %d\n", count, choices);

        t--;
    }
}