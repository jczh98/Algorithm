#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], p[N], ans[N];
int ch[N * 32][2], cnt = 1, val[N * 32], ed[N * 32];
inline void insert(int x) {
    int u = 0;
    for(int i = 30; i >= 0; --i) {
        int v = (x >> i) & 1;
        if(!ch[u][v]) {
            memset(ch[cnt], 0, sizeof(ch[cnt]));
            val[cnt] = 0; ed[cnt] = 0;ch[u][v] = cnt++;
        }
        u = ch[u][v]; val[u]++;
    }
    ed[u] = x;
}
inline void del(int x) {
    int u = 0;
    for(int i = 30; i >= 0; --i) {
        int v = (x >> i) & 1;
        u = ch[u][v]; val[u]--;
    }
}
inline int find(int x) {
    int u = 0;
    for(int i = 30; i >= 0; --i) {
        int v = (x >> i) & 1;
        if(ch[u][v] && val[ch[u][v]])  u = ch[u][v];
        else u = ch[u][v ^ 1];
    }
    return ed[u];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i) scanf("%d", &p[i]), insert(p[i]);
    for(int i = 1; i <= n; ++i) {
        int t = find(a[i]);
        ans[i] = t ^ a[i];
        del(t);
    }
    for(int i = 1; i <= n; ++i) {
        cout << ans[i];
        if(i == n) cout << endl; else cout << " ";
    }
    return 0;
}