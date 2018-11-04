#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL a[1000], id = 0;
int indeg[1000], outdeg[1000];
map<LL, int> H;
map<int, LL> rH;
int head[1000], nxt[20000], to[20000], cnt, vis[20000];
vector<int> ans;
inline void add(int u, int v) {
    to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
}
void euler(int s) {
    for(int i = head[s]; ~i; i = nxt[i]) {
        if(!vis[i]) {
            vis[i] = 1;
            euler(to[i]);
        }
    }
    ans.push_back(s);
}
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(H.find(a[i]) == H.end()) {
            H[a[i]] = ++id; rH[id] = a[i];
        }
    }
    if(n == 2) {
        sort(a + 1, a + 1 + 2);
        if(a[1] * 2 == a[2]) {
            cout << a[1] << " " << a[2] << endl;
        }else {
            cout << a[2] << " " << a[1] << endl;
        }
        return 0;
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            if(a[i] % 3 == 0 && a[i] / 3 == a[j]) {
                add(H[a[i]], H[a[j]]);
                indeg[H[a[i]]]++; outdeg[H[a[j]]]++;
            }
            if(a[i] * 2 == a[j]) {
                add(H[a[i]], H[a[j]]);
                indeg[H[a[i]]]++; outdeg[H[a[j]]]++;
            }
        }
    }
    for(int i = 1; i <= id; ++i) {
        if(indeg[i] > outdeg[i]) {
            euler(H[a[i]]);
        }
    }
    for(int i = ans.size() - 1; i >= 0; --i) {
        cout << rH[ans[i]] << " ";
    }
    cout << endl;
    return 0;
}