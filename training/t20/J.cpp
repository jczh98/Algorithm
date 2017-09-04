#include <bits/stdc++.h>
using namespace std;
typedef  long long LL;
LL n,m,k,x,y;
LL seat[110][110];
LL mx = 0, mi = 1e18;
int main() {
    cin >> n >> m >> k >> x >> y;
    if(n == 1) {
        LL times = k / m;
        LL rem = k % m;
        for(int i = 1;i <= m; i++) seat[1][i] = times;
        for(int i = 1;i <= m; i++) {
            if(!rem)break;
            seat[1][i]++;
            rem--;
        }
        for(int i = 1;i <= m; i++) {
            mx = max(mx, seat[1][i]);
            mi = min(mi, seat[1][i]);
        }
        cout << mx << " " << mi << " " << seat[x][y];
        return 0;
    }
    LL tot = 2 * n * m - 2 * m;
    LL number = k % tot, rem = number;
    LL times = k / tot;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 1; j <= m; j++) {
            seat[i][j] = times * 2;
        }
    }
    for (int i = 1; i <= m; i++) {
        seat[1][i] = times;
        seat[n][i] = times;
    }
    if(k % tot) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!rem) break;
                seat[i][j]++;
                rem--;
            }
        }
        if (rem) {
            for (int i = n - 1; i >= 2; i--) {
                for (int j = 1; j <= m; j++) {
                    if (!rem) break;
                    seat[i][j]++;
                    rem--;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mx = max(mx, seat[i][j]);
            mi = min(mi, seat[i][j]);
        }
    }
    cout << mx << " " << mi << " " << seat[x][y];
    return 0;
}

