#include <bits/stdc++.h>
using namespace std;
int n, a[1000005], b[1000005];
long long sum, tot;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += 1LL * a[i];
    for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + n);
    tot = 1LL * b[n] + 1LL * b[n - 1];
    if(tot >= sum) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}