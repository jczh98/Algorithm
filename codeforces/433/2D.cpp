#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node{
    LL d, f, t, c;
}flight[100005];
bool cmp(Node a, Node b) {
    return a.d < b.d;
}
LL n, m, k, tot = 1000000, pre[1000005], vis[100005], num = 0, now = 1, sum;
int main() {
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> flight[i].d >> flight[i].f >> flight[i].t >> flight[i].c;
    }
    sort(flight + 1, flight + m + 1, cmp);
    for(int i = 1; i <= tot; i++) {
        for(; now <= m && flight[now].d <= i; now++) {
            if(flight[now].f == 0) {
                continue;
            }
            if(vis[flight[now].f] && vis[flight[now].f] < flight[now].c) {
                continue;
            }
            if(!vis[flight[now].f]) num++;
            sum = sum - vis[flight[now].f] + flight[now].c;
            vis[flight[now].f] = flight[now].c;
        }
        if(num != n) {
            pre[i] = 1000000000000LL;
        }else {
            pre[i] = sum;
        }
    }
    num = 0; now = m; sum = 0;
    LL ans = 1000000000000LL;
    memset(vis, 0 ,sizeof(vis));
    for(int i = tot; i - k - 1 >= 1; i--) {
        for(; now >= 1 && flight[now].d >= i; now--) {
            if(flight[now].t == 0) {
                continue;
            }
            if(vis[flight[now].t] && vis[flight[now].t] < flight[now].c) {
                continue;
            }
            if(!vis[flight[now].t]) num++;
            sum = sum - vis[flight[now].t] + flight[now].c;
            vis[flight[now].t] = flight[now].c;
        }
        if(num == n) {
            ans = min(ans, sum + pre[i - k - 1]);
        }
    }
    if(ans == 1000000000000LL) ans = -1;
    cout << ans << endl;
    return 0;
}