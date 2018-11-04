#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, d, a[500005], que[500005];
int main() {
    cin >> n >> k >> d;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int head = 1, tail = 1;
    for(int i = k; i <= n; ++i) {
        while(a[i] - a[que[head]+1]>d&&head<=tail)head++;
        if(head <= tail && i - que[head]>=k) {
            que[++tail] =i ;
        }
    }
    if(que[tail] == n)cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}