#include <bits/stdc++.h>
using namespace std;
int h, w, n, num[1100000], mp[1100][1100], cnt = 1;
int main() {
    cin >> h >> w >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for(int i = 1; i <= h; i++) {
        int from = (i & 1) ? 1 : w;
        int to = (i & 1) ? w + 1 : 0;
        int delta = (i & 1) ? 1 : -1;
        for(int j = from; j != to; j += delta) {
            mp[i][j] = cnt;
            num[cnt]--;
            if(num[cnt] == 0) cnt++;
        }
    }
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j < w; j++) {
            cout << mp[i][j] << " ";
        }
        cout << mp[i][w] <<endl;
    }
    return 0;
}

