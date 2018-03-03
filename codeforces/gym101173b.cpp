#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1 << 20;
int n, m, a[N + 5], b[N + 5], cnt[N + 5], L[N + 5], R[N + 5], fl[N + 5], fr[N + 5], t;
char str[100][100];
vector<int> g1, g2;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) scanf("%s", str[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < m; ++i) scanf("%d", &b[i]);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(str[i][j] == '1') {
                L[i] |= (1 << j); R[j] |= (1 << i);
            }
        }
    }
    scanf("%d", &t);
    for(int i = 0; i <= max((1 << n), (1 << m)); ++i) cnt[i] = cnt[i>>1] + (i & 1);
    for(int s = 0; s < (1 << n); ++s) {
        int now = 0, v = 0;
        fl[s] = 1;
        for(int i = 0; i < n; ++i) {
            if((s >> i) & 1) {
                v += a[i]; now |= L[i];
                fl[s] &= fl[s ^ (1 << i)];
            }
        }
        if(fl[s] && cnt[s] <= cnt[now]) g1.push_back(v);
        else fl[s] = 0;
    }
    for(int s = 0; s < (1 << m); ++s) {
        int now = 0, v = 0;
        fr[s] = 1;
        for(int i = 0; i < m; ++i) {
            if((s >> i) & 1) {
                v += b[i]; now |= R[i];
                fr[s] &= fr[s ^ (1 << i)];
            }
        }
        if(fr[s] && cnt[s] <= cnt[now]) g2.push_back(v);
        else fr[s] = 0;
    }
    sort(g1.begin(), g1.end());
    LL ans = 0;
    for(int i = 0; i < g2.size(); ++i) {
        ans += g1.size() - (lower_bound(g1.begin(), g1.end(), t - g2[i]) - g1.begin());
    }
    cout << ans << endl;
    return 0;
}
/* 
3 3
010
111
010
1 2 3
8 5 13
21
 */
/* 
3 2
01
11
10
1 2 3
4 5
8
 */