#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pLL;
LL n, k, ans[300005], c[300005];
LL sum;
priority_queue<pLL> pq;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for(int i = 1; i <= n + k; i++) {
        if(i <= n) {
            pq.push(make_pair(c[i], i));
        }
        if(i >= k + 1) {
            pLL top = pq.top(); pq.pop();
            sum += (i - top.second) * 1LL * top.first;
            ans[top.second] = i;
        }
    }
    cout << sum << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
        if(i != n) {
            cout << " ";
        }
    }
    return 0;
}

