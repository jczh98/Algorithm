#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pii;
int n, k, a[200005];
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    k--;
    sort(a + 1, a + 1 + n);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(make_pair((LL)a[1], 1));
    while(k--) {
        pii top = pq.top();
        pq.pop();
        if(top.second == n) continue;
        pq.push(make_pair(top.first - a[top.second] + a[top.second + 1], top.second + 1));
        pq.push(make_pair(top.first + a[top.second + 1], top.second + 1));
    }
    cout << pq.top().first << endl;
    return 0;
}