#include <bits/stdc++.h>
using namespace std;
int a[1000], n, psum, sum;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) {
        if(a[i] >= 0) break;
        psum += a[i];
    }
    for(int i = 1; i <= n; ++i) {
        if(a[i] >= 0) sum += a[i];
    }
    cout << sum - psum << endl;
    return 0;
}