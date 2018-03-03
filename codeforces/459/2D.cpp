#include <bits/stdc++.h>
using namespace std;
const int N = 106, M = 10005;
int n, m, a, b, f[N][N][N];
char c[100];
int head[N], nxt[M], to[M], val[M], cnt = 0;
inline void add(int u, int v, int w) {
    to[cnt] = v; val[cnt] = w; nxt[cnt] = head[u]; head[u] = cnt++;
}
int dfs(int x, int y, int z) {
    if(~f[x][y][z]) return f[x][y][z];
    int flag = 0;
    for(int i = head[x]; ~i; i = nxt[i]) {
        if(z <= val[i] && !dfs(y, to[i], val[i])) flag = 1;
    }
    return f[x][y][z] = flag;
}
int main() {
    memset(f, -1, sizeof(f));
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%s", &a, &b, c);
        add(a, b, c[0] - 'a' + 1);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(dfs(i, j, 0)) printf("A");
            else printf("B");
        }
        printf("\n");
    }
    return 0;
}