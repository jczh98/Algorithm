#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int st[100100], f[100100];
int n, k, m, a, flag = 0, top = 1;
LL ans = 0;
int main() {
    scanf("%d%d%d", &n, &k, &m);
    st[0] = 0;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        if(st[top - 1] != a) st[top] = a, f[top++] = 1;
        else  {
            if(f[top - 1] + 1 < k) f[top - 1] += 1;
            else if(f[top - 1] + 1 == k)  top--;
        }
    }
    if(k >= n) {
        for(int i = 1; i < top - 1; ++i) if(st[i] != st[i + 1]) flag = 1;
        if(!flag) cout << 1LL * n * m % k << endl; else cout << 1LL * n * m << endl;
        return 0;
    }
    for(int i = 1; i < top; ++i) ans += f[i];
    if(m == 1 || ans == 0) {cout << ans << endl; return 0;}
    ans = 1LL * m * ans;
    int L = 1, R = top - 1;
    while(L < R) {
        if(st[L] != st[R]) {cout << ans << endl; return 0;}
        if(f[L] + f[R] == k) {L++; R--;ans -= 1LL * (m - 1) * k; continue;}
        if(f[L] + f[R] > k) ans -= 1LL * (m - 1) * k;
        cout << ans << endl; return 0;
    }
    if(L > R) {cout << 0 << endl; return 0;}
    if(L == R) {
        LL x = 1LL * f[L] * m;
        if(x % k == 0) {cout << 0 << endl;}
        else {cout << ans - x / (LL)k * (LL)k << endl;}
    }
    return 0;
}