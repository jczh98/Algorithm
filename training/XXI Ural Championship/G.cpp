#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a, b, c[100], x, y, m;
LL ans;
map<LL, LL> f;
void DFS1(int x, int y) {
    if(x == m) {
        f[y]++;return;
    }
    DFS1(x + 1, y + c[x]); DFS1(x + 1, y);
}
void DFS2(int x, int y) {
    if(x == n + 1) {
        ans += f[-y];
        return;
    }
    DFS2(x + 1, y + c[x]); DFS2(x + 1, y);
}
int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)cin >> x >> y, c[i] = b * x - a * y;
    m = n / 2;
    DFS1(1, 0);
    DFS2(m, 0);
    cout << ans - 1 << endl;
    return 0;
}


