#include <bits/stdc++.h>
using namespace std;
int n, q, a[100005], l, r, bl[100005], len, cnt[100005];
struct node {
    int l, r, id;
    bool operator < (const node& rhs) const {
        if(bl[l] == bl[rhs.l]) return r < rhs.r;
        else return bl[l] < bl[rhs.l];
    }
}query[100005];
int answer[100005], ans;
int main() {
    while(scanf("%d%d", &n, &q) != EOF) {
        memset(cnt, 0, sizeof(cnt));
        len = (int) sqrt(1.0 * n); 
        for(register int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]); bl[i] = (i - 1) / len + 1; 
        }
        //cout << ans << endl;
        for(register int i = 1; i <= q; ++i) {
            scanf("%d%d", &l, &r);
            query[i].l = l; query[i].r = r; query[i].id = i;
        }
        sort(query + 1, query + 1 + q);
        int l = 0, r = n + 1, ans = 0; 
        for(register int i = 1; i <= q; ++i) {
            for (; r < query[i].r; ) {
                cnt[a[r]]--; if(!cnt[a[r]]) ans--; ++r;
            }
            for (; r > query[i].r; ) {
                --r; if(!cnt[a[r]]) ans++; cnt[a[r]]++;
            }
            for (; l < query[i].l; ) {
                ++l; if(!cnt[a[l]]) ans++; cnt[a[l]]++;
            }
            for (; l > query[i].l; ) {
                cnt[a[l]]--; if(!cnt[a[l]]) ans--; --l;
            }
            answer[query[i].id] = ans;
        }
        for(register int i = 1; i <= q; ++i) {
            printf("%d\n", answer[i]);
        }       
    } 
    return 0;
}
