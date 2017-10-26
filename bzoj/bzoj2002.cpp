#include <bits/stdc++.h>
using namespace std;
int n, m, ki[200005], block, belong[200005], l[200005], pos[200005], times[200005], kdt, x, y;
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &ki[i]);
    block = (int) sqrt(n * 1.0);
    for(int i = 0; i < n; ++i) belong[i] = i / block + 1;
    for(int i = 0; i * block < n; ++i) l[i + 1] = i * block;
    //for(int i = 0; i < n; ++i) cout << belong[i] << " "; cout << endl;
    //for(int i = 0; i * block < n; ++i) cout << l[i] << " "; cout << endl;
    for(int i = n - 1; ~i; --i) {
        if(i + ki[i] >= n) pos[i] = -1, times[i] = 1;
        else if(belong[i] == belong[i + ki[i]]) pos[i] = pos[i + ki[i]], times[i] = times[i + ki[i]] + 1;
        else pos[i] = i + ki[i], times[i] = 1;
    }
    scanf("%d", &m);
    for(; m; --m) {
        scanf("%d%d", &kdt, &x);
        if(kdt == 1) {
            int ans = 0;
            for(int i = x; ~i; i = pos[i]) ans += times[i];
            printf("%d\n", ans);
        }else {
            scanf("%d", &y);
            ki[x] = y;
            for(int i = x; i >= l[belong[x]]; --i) {
                if(i + ki[i] >= n) pos[i] = -1, times[i] = 1;
                else if(belong[i] == belong[i + ki[i]]) pos[i] = pos[i + ki[i]], times[i] = times[i + ki[i]] + 1;
                else pos[i] = i + ki[i], times[i] = 1;
            }
        }
    }
    return 0;
}

