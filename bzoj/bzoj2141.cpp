#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int M = 20005;
int C[200][M], pre[M], hh[M], cnt = 1, belong[M], block, block_cnt, l[M], r[M], ans = 0;
int n, m, x, y;
pii h[M];
map<int, int> Hash;
inline void Update(int c[], int x, int val) {
    for(; x < M; x += (x & (-x))) {
        c[x] += val;
    }
}
inline int Query(int c[], int x) {
    int ret = 0;
    for(; x > 0; x -= (x & (-x))) {
        ret += c[x];
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &h[i].first), h[i].second = i;
    sort(h + 1, h + 1 + n);
    for(int i = 1; i <= n; ++i) {
        if(Hash.find(h[i].first) == Hash.end()) Hash[h[i].first] = cnt++;
        hh[h[i].second] = Hash[h[i].first];
    }
    block = sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) belong[i] = (i - 1) / block + 1;
    if(n % block) block_cnt = n / block + 1; else block_cnt = n / block;
    for(int i = 1; i <= block_cnt; ++i) l[i] = (i - 1) * block + 1, r[i] = i * block; r[block_cnt] = n;
    for(int i = n; i >= 1; --i) {
        Update(C[belong[i]], hh[i], 1);
        ans += Query(pre, hh[i] - 1);
        Update(pre, hh[i], 1);
    }
    printf("%d\n", ans);
    scanf("%d", &m);
    for(; m; --m) {
        scanf("%d%d", &x, &y);
        if(x > y) swap(x, y);
        if(belong[x] == belong[y]) {
            for(int i = x + 1; i < y; ++i) {
                if(hh[i] < hh[x]) --ans;
                if(hh[i] > hh[x]) ++ans;
                if(hh[i] < hh[y]) ++ans;
                if(hh[i] > hh[y]) --ans;
            }
        }else {
            for(int i = x + 1; i <= r[belong[x]]; ++i) {
                if(hh[i] < hh[x]) --ans;
                if(hh[i] > hh[x]) ++ans;
                if(hh[i] < hh[y]) ++ans;
                if(hh[i] > hh[y]) --ans;
            }
            for(int i = l[belong[y]]; i < y; ++i) {
                if(hh[i] < hh[x]) --ans;
                if(hh[i] > hh[x]) ++ans;
                if(hh[i] < hh[y]) ++ans;
                if(hh[i] > hh[y]) --ans;
            }
            for(int i = belong[x] + 1; i < belong[y]; ++i) {
                ans -= Query(C[i], hh[x] - 1);
                ans += Query(C[i], n) - Query(C[i], hh[x]);
                ans += Query(C[i], hh[y] - 1);
                ans -= Query(C[i], n) - Query(C[i], hh[y]);
            }
        }
        if(hh[x] > hh[y]) --ans; if(hh[x] < hh[y]) ++ans;
        Update(C[belong[x]], hh[x], -1); Update(C[belong[y]], hh[y], -1);
        swap(hh[x], hh[y]);
        Update(C[belong[x]], hh[x], 1); Update(C[belong[y]], hh[y], 1);
        printf("%d\n", ans);
    }
    return 0;
}