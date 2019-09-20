#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
struct node {
    int id, val;
};
int n, m, k, q, tim[2000], ans[2000], query;
struct node queue[30][30000];
int front[30], end[30], current[2000];
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &tim[i]);
    }
    for (int i = 1; i <= k; ++i) {
        int min_len = 1, first_fin = 1;
        for (int j = 1; j <= n; ++j) {
            if (end[j]-front[j]==0) {
                min_len = j;
                break;
            } else {
                if (end[j]-front[j]<end[min_len]-front[min_len]) {
                    min_len = j;
                }
                if (ans[queue[j][front[j]].id] < ans[queue[first_fin][front[first_fin]].id]) {
                    first_fin = j;
                }
            }
        }
        struct node nod; nod.id = i;
        if (end[min_len]-front[min_len]<m) {
            //printf(":%d -> %d\n", i, min_len);
            if (end[min_len]-front[min_len]!=0) {
                nod.val = queue[min_len][end[min_len]-1].val + tim[i];
            } else {
                nod.val = tim[i];
            }
            queue[min_len][end[min_len]++] = nod;
            ans[i] = nod.val;
        } else {
            //printf("::%d -> %d\n", i, first_fin);
            nod.val = queue[first_fin][end[first_fin]-1].val + tim[i];
            front[first_fin]++;
            queue[first_fin][end[first_fin]++] = nod;
            ans[i] = nod.val;
        }
    }
    for (int i = 1; i <= q; ++i) {
        scanf("%d", &query);
        if (ans[query] - tim[query] >= 540) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", ans[query]/60+8,ans[query]%60);
        }
    }
    return 0;
}
