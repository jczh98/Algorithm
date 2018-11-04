#include <bits/stdc++.h>
using namespace std;
int t, ex, ey, ans;
queue<pair<int,int>> que;
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        scanf("%d%d", &ex, &ey); ans = 0;
        que.push(make_pair(ex, ey));
        while(!que.empty()) {
            ans++;
            int cx = que.front().first, cy = que.front().second; que.pop();
            int g = __gcd(cx, cy);
            int k1 = cx / g, k2 = cy / g;
            if(k2 % (k1+1) == 0) {
                que.push(make_pair(k1*g, k2/(k1+1)*g));
            }
            if(k1 % (k2 + 1) == 0) {
                que.push(make_pair(k1/(k2+1)*g, k2*g));
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}