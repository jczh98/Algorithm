#include <bits/stdc++.h>
using namespace std;
int n, a[1000], sum[1000];
int main() {
    freopen("out.txt", "w", stdout);
    n = 100;
    a[1] = 0;
    for(int i = 2; i <= n; ++i) {
        if((i * (i + 1) / 2) & 1) a[i] = a[i / 2] - 1;
        else a[i] = a[i / 2] + 1;
    }
    sum[1] = abs(a[1]);
    for(int i = 2; i <= n; ++i) {
        sum[i] = sum[i - 1] + abs(a[i]);
    }
    for(int i = 1; i <= n; ++i) {
        cout << abs(a[i]) << ",";
    }
    return 0;
}