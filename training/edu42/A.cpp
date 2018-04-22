#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[2000005];
LL pre[2000005], sum;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += 1LL * a[i], pre[i] = pre[i - 1] + 1LL * a[i];
    sum = (sum + 1) >> 1;
    int k = lower_bound(pre + 1, pre + 1 + n, sum) - pre;
    cout << k << endl;
    return 0;
}