#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, m, cnt[1005][1005], a[100005], b[100005], op, x, y;
ll sum;
bool check(ll x, ll k) {
    ll ret = 0;
    for(int i = 1; i <= 1000; ++i) {
        ret += x/i*cnt[i][0];
        ret -= cnt[i][x%i+1];
    }
    if(ret - sum >= k) return true; else return false;
}
ll solve(ll k) {
    ll l = 1, r = 1e13, mid;
    while(l < r) {
        mid = (l+r)>>1;
        if(check(mid, k)) {
            r = mid;
        }else {
            l = mid+1;
        }
    } 
    return l;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        sum = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
            sum += b[i]/a[i];
            cnt[a[i]][b[i]%a[i]]++;
        }
        for(int i = 1; i <= 1000; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                cnt[i][j] += cnt[i][j+1];
            }
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &op);
            if(op == 1) {
                scanf("%d%d", &x, &y);
                sum -= b[x]/a[x];
                for(int j = b[x]%a[x]; j >= 0; --j) cnt[a[x]][j]--;
                sum += b[x]/y;
                for(int j = b[x]%y; j >= 0; --j) cnt[y][j]++;
                a[x] = y;
            } else if(op == 2) {
                scanf("%d%d", &x, &y);
                sum -= b[x]/a[x];
                for(int j = b[x]%a[x]; j >= 0; --j) cnt[a[x]][j]--;
                sum += y/a[x];
                for(int j = y%a[x]; j >= 0; --j) cnt[a[x]][j]++;
                b[x] = y;
            } else {
                scanf("%d", &x);
                cout << solve(x) << endl;
            }
        }
    }
    return 0;
}