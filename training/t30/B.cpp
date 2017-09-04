#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef pair<int, int> pii;
int n, m, len, f[100][100][100], vis[100][100], ans = inf, check[100][100];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
pii s, t;
char G[100][100], ope[100];
void BFS(int k) {
    queue<pii > que;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(check[i][j]) {
                que.push(make_pair(i, j));
                vis[i][j] = 1;
            }
        }
    }
    while(!que.empty()) {
        int nowx = que.front().first, nowy = que.front().second;que.pop();
        vis[nowx][nowy] = 0;
        for(int i = 0; i < 4; i++) {
            int x = nowx + dx[i], y = nowy + dy[i];
            if(!check[x][y]) continue;
            if(f[x][y][k] > f[nowx][nowy][k] + 1) {
                f[x][y][k] = f[nowx][nowy][k] + 1;
                if(!vis[x][y]) {
                    que.push(make_pair(x, y));
                    vis[x][y] = 1;
                }
            }
        }
    }
}
int main() {
    memset(f, 127, sizeof(f));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", G[i] + 1);
    }
    scanf("%s", ope + 1);
    len = strlen(ope + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(G[i][j] != '#') check[i][j] = 1;
            if(G[i][j] == 'R') {
                s.first = i;
                s.second = j;
            }
            if(G[i][j] == 'E') {
                t.first = i;
                t.second = j;
            }
        }
    }
    f[s.first][s.second][0] = 0;
    for(int k = 1; k <= len + 1; k++) {
        BFS(k - 1);
        ans = min(ans, f[t.first][t.second][k - 1]);
        if(k == len + 1) break;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(check[i][j]) {
                    int dir;
                    if(ope[k] == 'L') dir = 3;
                    if(ope[k] == 'R') dir = 1;
                    if(ope[k] == 'U') dir = 2;
                    if(ope[k] == 'D') dir = 0;
                    int x = i + dx[dir], y = j + dy[dir];
                    if(check[x][y]) {
                        f[x][y][k] = min(f[i][j][k - 1], f[x][y][k]);
                    }else {
                        f[i][j][k] = min(f[i][j][k - 1], f[i][j][k]);
                    }
                    f[i][j][k] = min(f[i][j][k - 1] + 1, f[i][j][k]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

