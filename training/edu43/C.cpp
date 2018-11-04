#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, l, r;
} mes[400010];
int n;
bool cmp(node a, node b) {
    if (a.l == b.l)
        return a.r > b.r;
    else
        return a.l < b.l;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &mes[i].l, &mes[i].r);
        mes[i].id = i;
    }
    sort(mes + 1, mes + 1 + n, cmp);
    int lnow = mes[1].l, rnow = mes[1].r, idnow = 1;
    for (int i = 2; i <= n; ++i) {
        if (mes[i].l > rnow) {
            lnow = mes[i].l;
            rnow = mes[i].r;
            idnow = i;
        } else if (rnow >= mes[i].r) {
            printf("%d %d", mes[i].id, mes[idnow].id);
            return 0;
        } else if (rnow < mes[i].r) {
            idnow = i;
            rnow = mes[i].r;
        }
    }
    printf("-1 -1");
    return 0;
}
