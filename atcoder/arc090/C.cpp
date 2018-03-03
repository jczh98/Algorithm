#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, c[10][1000], f[10][1000];
int main() {
    cin >> n;
    for(int i = 1; i <= 2; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= 2; ++i) {
        for(int j = 1; j <= n; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + c[i][j];
        }
    }
    cout << f[2][n] << endl;
    return 0;
}