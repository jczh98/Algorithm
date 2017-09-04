#include <bits/stdc++.h>
#define eps 1e-8
#define inf 1e7 + 5
using namespace std;
int n, cnt_id, kase = 1, a, b, tot;
char currency_a[100], currency_b[100], cur[100];
string re_mp[100];
double dis[100][100];
map<string, int> mp;
void Floyd() {
    for (int k = 1; k < cnt_id; k++) {
        for (int i = 1; i < cnt_id; i++) {
            for (int j = 1; j < cnt_id; j++) {
                if (dis[i][k] != inf && dis[k][j] != inf) {
                    dis[i][j] = min(dis[i][j], dis[i][k] * dis[k][j]);
                }
            }
        }
    }
}
int main() {
    while (scanf("%d", &n) != EOF) {
        if(n == 0) break;
        mp.clear();
        cnt_id = 1;
        for (int i = 1; i < 100; i++) {
            for (int j = 1; j < 100; j++) {
                dis[i][j] = inf;
            }
        }
        for (int i = 1; i < 100; i++) {
            dis[i][i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d%s%*s%d%s", &a, currency_a, &b, currency_b);
            if (!mp[currency_a]){
                mp[currency_a] = cnt_id++;
                re_mp[cnt_id - 1] = currency_a;
            }
            if (!mp[currency_b]) {
                mp[currency_b] = cnt_id++;
                re_mp[cnt_id - 1] = currency_b;
            }
            dis[mp[currency_a]][mp[currency_b]] = (double) b / (double) a;
            dis[mp[currency_b]][mp[currency_a]] = (double) a / (double) b;
        }
        scanf("%d%s", &tot, cur);
        int id = mp[cur];
        Floyd();
        double mi = inf;
        int mx_id, mx;
        for (int i = 1; i < cnt_id; i++) {
            if (id != i) {
                int x = ceil(tot * 1.0 * dis[id][i] - eps);
                if (x > 1e5) continue;
                double y = (double) x * dis[i][id];
                if (mi > y) {
                    mi = y; mx_id = i; mx = x;
                }
            }
        }
        printf("Case %d: %d %s\n", kase++, mx, re_mp[mx_id].c_str());
    }
    return 0;
}