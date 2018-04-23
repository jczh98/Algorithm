#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int max_pri[N + 10], ans, x;
int main() {
    scanf("%d", &x);
    for(int i = 2; i < N; ++i) {
        if(!max_pri[i]) {
            for(int j = i + i; j < N; j += i) max_pri[j] = i;
        }
    }
    ans = INT_MAX;
    for(int i = x - max_pri[x] + 1; i <= x; ++i) {
        ans = min(ans, i - max_pri[i] + 1);
    }
    cout << ans << endl;
}