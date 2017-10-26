#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, m, k, s1, t1, s2, t2, vis[1005][1005], dis[1005][1005], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char mp[1005][1005];
void BFS() {
    memset(dis, 1, sizeof(dis));
    queue<pii> que;
    que.push(make_pair(s1, t1));
    dis[s1][t1] = 0; vis[s1][t1] = 1;
    while(!que.empty()) {
        int x = que.front().first, y = que.front().second;que.pop();
        if(x == s2 && y == t2) return;
        for(int i = 0; i < 4; ++i) {
            for(int j = 1; j <= k; ++j) {
                int nx = x + dx[i] * j, ny = y + dy[i] * j;
                if(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == '#' || dis[nx][ny] < dis[x][y] + 1) break;
                dis[nx][ny] = dis[x][y] + 1;
                if(!vis[nx][ny]) que.push(make_pair(nx, ny)), vis[nx][ny] = 1;
            }
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%s", mp[i] + 1);
    }
    scanf("%d%d%d%d", &s1, &t1, &s2, &t2);
    BFS();
    if(dis[s2][t2] == 16843009) {printf("-1\n"); return 0;}
    printf("%d\n", dis[s2][t2]);
    return 0;
}