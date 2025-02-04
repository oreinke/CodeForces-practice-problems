#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

int main() {
    int n, m, k; cin >> n >> m >> k;
    vii grid (n, vi (m));
    vii cols(m, vi (n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int num; cin >> num;
            if (num == 2) {
                for (int k = i; k >= 0; --k) {
                    cols[j][k]++;
                }
            }
            grid[i][j]= num;
        }
    }

    for (int i = 0; i < k; ++i) {
        int col; cin >> col;
        col--;
        int row = 0;
        while (row < n) { 
            if (cols[col][row] == (n  - row)) {
                row = n;
            }
            else if (grid[row][col] == 1) {
                grid[row][col] = 2;
                for (int k = row; k >= 0; --k) {
                    cols[col][k]++;
                }
                col++;
            }
            else if (grid[row][col] == 2) {
                row++;
            }
            else {
                grid[row][col] = 2;
                for (int k = row; k >= 0; --k) {
                    cols[col][k]++;
                }
                col--;
            }
        }
        printf("%d ", col + 1);
    }
    cout << endl;

    
}