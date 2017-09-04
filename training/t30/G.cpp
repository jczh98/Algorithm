#include<bits/stdc++.h>

using namespace std;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
char s[100];
int f[1610], b[60][60], a[60][60], v[60][60], cy[1610], cx[1610], n, m, ans, t;
vector<int> g[1610];

void dfs(int i, int j) {
    v[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x == 0 || x > n || y > m || y == 0) continue;
        if (v[x][y]) continue;
        if (a[x][y] == -1) a[x][y] = 0;
        if (a[x][y] == 1) dfs(x, y);
    }
}

int work(int x) {
    for (int i = 0; i < g[x].size(); i++) {
        int y = g[x][i];
        if (!f[y]) {
            f[y] = 1;
            if (!cy[y] || work(cy[y])) {
                cx[x] = y;
                cy[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    //freopen("1.in","r",stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            if (s[j] == 'W') a[i][j] = 0;
            if (s[j] == 'C') a[i][j] = -1;
            if (s[j] == 'L') a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!v[i][j] && a[i][j] == 1) {
                ans++;
                dfs(i, j);
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == -1) b[i][j] = ++t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ((i + j) % 2 == 0) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (b[x][y]) g[b[i][j]].push_back(b[x][y]);
                }
            }
    int s = 0;
    for (int i = 1; i <= t; i++)
        if (g[i].size()) {
            if (!cx[i]) {
                memset(f, 0, sizeof(f));
                s += work(i);
            }
        }
    printf("%d\n", ans + t - s);
}