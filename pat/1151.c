#include <stdio.h>

int m, n;
int in[20000], pre[20000], pos[20000000];

void lca(int l, int r, int rt, int a, int b) {
    if (l > r) return ;
    int pos_rt = pos[pre[rt]], pos_a = pos[a], pos_b = pos[b];
    if (pos_a < pos_rt && pos_b < pos_rt) {
        lca(l, pos_rt-1, rt+1, a, b);
    } else if((pos_a < pos_rt && pos_b > pos_rt)||(pos_a > pos_rt && pos_b < pos_rt)) {
        printf("LCA of %d and %d is %d.\n", a, b, pre[rt]);
    } else if(pos_a > pos_rt && pos_b > pos_rt) {
        int lc = pos_rt - l;
        lca(pos_rt+1, r, rt+lc+1, a, b);
    } else if(pos_a == pos_rt) {
        printf("%d is an ancestor of %d.\n", a, b);
    } else if(pos_b == pos_rt) {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}
int check(int x) {
    if (x < 0) return 1;
    if (pos[x] == 0) return 1;
    return 0;
}
int main() {
    scanf("%d%d", &m, &n);    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &pre[i]);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (check(u) && check(v)) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (check(u) || check(v)) {
            printf("ERROR: %d is not found.\n", pos[u] == 0?u:v);
        } else {
            lca(1, n, 1, u, v);
        }
    }
}
