#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n, x; priority_queue<LL, vector<LL>, greater<LL> > que;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &x), que.push(1LL * x);
        LL ans = 0;
        while(!que.empty()) {
            LL t1 = que.top(); que.pop();
            if(que.empty()) break;
            LL t2 = que.top(); que.pop();
            ans += t1 + t2; 
            que.push(t1 + t2);
        }
        cout << ans << endl;
    }
    return 0;
}