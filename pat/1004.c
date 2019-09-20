#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
int son[200][200], k[200], ans[200];
int n, m, sum, tmpk, max_dep;
char tmp[20];
int convert() {
    return (tmp[0] - '0') * 10 + (tmp[1] - '0');
}
void dfs(int u, int depth) {
    max_dep = max(depth, max_dep);
    if (k[u] == 0) {
        ans[depth]++;
        return;
    }
    for (int i = 1; i <= k[u]; ++i) {
        int v = son[u][i];
        dfs(v, depth+1);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%s%d", tmp, &tmpk);
        int u = convert();
        k[u] = tmpk;
        for (int j = 1; j <= k[u]; ++j) {
            scanf("%s", tmp);
            int v = convert();
            son[u][j] = v;
        }
    }
    dfs(1, 0);
    for (int i = 0; i <= max_dep; ++i) {
        printf("%d%c", ans[i], " \n"[i==max_dep]);
    }
}
