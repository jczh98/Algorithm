#include <cstdio>
#include <vector>
#include <cstring>

int n, m, k, q, D[300][300], paths[300], cnt[300];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        D[u][v] = D[v][u] = d;
    }
    scanf("%d", &q);
    int min_dis=1e7, min_ind;
    for(int l = 1; l <= q; ++l) {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &paths[i]);
        }
        int dis = 0;
        bool flag = false;
        cnt[paths[1]]++;
        for (int i = 2; i <= k; ++i) {
            if (D[paths[i]][paths[i-1]] == 0) {
                flag = true;
                break;
            }
            cnt[paths[i]]++;
            dis += D[paths[i]][paths[i-1]];
        }
        if (flag) {
            printf("Path %d: NA (Not a TS cycle)\n", l);
        } else {
            bool flag2 = false, flag3 = false;
            if (paths[1] != paths[k]) flag2 = true;
            for (int i = 1; i <= n; ++i) {
                if (cnt[i]==0) {
                    flag2 = true;
                }
                if (cnt[i] > 1 && (i!=paths[1])) {
                    flag3 = true;
                }
            }
            printf("Path %d: ", l);
            if (flag2) {
                printf("%d (Not a TS cycle)\n", dis);
            } else if (flag3) {
                if (min_dis > dis) {
                    min_dis = dis;
                    min_ind = l;
                }
                printf("%d (TS cycle)\n", dis);
            } else {
                if (min_dis > dis) {
                    min_dis = dis;
                    min_ind = l;
                }
                printf("%d (TS simple cycle)\n", dis);
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", min_ind, min_dis);
    return 0;
}
