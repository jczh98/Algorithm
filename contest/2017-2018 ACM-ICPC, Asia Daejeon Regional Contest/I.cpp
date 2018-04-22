#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], nxt[1000005], ans = INT_MAX, ans_p, ans_k;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i <= (n >> 1); ++i) swap(a[i], a[n - i + 1]);
    nxt[1] = 0;
    for(int i = 1; i < n; ++i) {
        int j = nxt[i];
        while(j && a[j + 1] != a[i + 1]) j = nxt[j];
        nxt[i + 1] = (a[j + 1] == a[i + 1]) ? j + 1 : 0;
    }
    for(int i = 1; i <= n; ++i) {
        int p = n - i + 1 - nxt[n - i + 1];
        if(ans > p + i || (ans == p + i && ans_p > p)) {
            ans_p = p; ans_k = i - 1;
            ans = p + i;
        }
    }
    cout << ans_k << " " << ans_p << endl;
    return 0;
}