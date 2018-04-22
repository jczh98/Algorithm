#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 4e5 + 10;
LL x[maxn];
char type[maxn];
vector<LL> R;
vector<LL> B;
LL size_R, size_B;
void put_fuc(LL st, LL ed) {
    R.clear();
    B.clear();
    for (LL i = st; i <= ed; ++i) {
        if (type[i] == 1)
            R.push_back(i);
        else if (type[i] == 2)
            B.push_back(i);
    }
    size_R = R.size();
    size_B = B.size();
}
vector<LL> G;
LL n;
LL pos;
char t;
int main() {
    cin >> n;
    for (LL i = 1; i <= n; ++i) {
        cin >> pos >> t;
        x[i] = pos;
        if (t == 'P') {
            type[i] = 0;
            G.push_back(i);
        } else if (t == 'R')
            type[i] = 1;
        else
            type[i] = 2;
    }
    LL ans = 0;
    LL sz = G.size();
    if (sz == 0) {
        put_fuc(1, n);
        if (size_R > 0) ans += x[R[size_R - 1]] - x[R[0]];
        if (size_B > 0) ans += x[B[size_B - 1]] - x[B[0]];
    } else {
        put_fuc(1, G[0] - 1);
        if (size_R > 0) ans += (x[G[0]] - x[R[0]]);
        if (size_B > 0) ans += (x[G[0]] - x[B[0]]);
        put_fuc(G[sz - 1] + 1, n);
        if (size_R > 0) ans += (x[R[size_R - 1]] - x[G[sz - 1]]);
        if (size_B > 0) ans += (x[B[size_B - 1]] - x[G[sz - 1]]);
        for (LL i = 0; i < sz - 1; i++) {
            LL x1 = G[i], x2 = G[i + 1];
            LL tmp1 = 0, tmp2 = 0;
            put_fuc(x1 + 1, x2 - 1);
            if (size_R > 0) {
                tmp1 = x[R[0]] - x[x1];
                for (LL p = 1; p < size_R; p++)
                    tmp1 = max(tmp1, x[R[p]] - x[R[p - 1]]);
                tmp1 = max(tmp1, x[x2] - x[R[size_R - 1]]);
            } else
                tmp1 = x[x2] - x[x1];
            if (size_B > 0) {
                tmp2 = x[B[0]] - x[x1];
                for (LL p = 1; p < size_B; p++)
                    tmp2 = max(tmp2, x[B[p]] - x[B[p - 1]]);
                tmp2 = max(tmp2, x[x2] - x[B[size_B - 1]]);
            } else
                tmp2 = x[x2] - x[x1];
            ans += min((x[x2] - x[x1]) * 2, (x[x2] - x[x1]) * 3 - tmp1 - tmp2);
        }
    }
    cout << ans << endl;
    return 0;
}