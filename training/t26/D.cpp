#include <bits/stdc++.h>
using namespace std;
int N = 1000000000 + 5;
map<int,int> fa;
int Find(int x) {
    if(!fa[x]) {
        fa[x] = x;
    }
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}
void Union(int x, int y) {
    int fx = Find(x), fy = Find(y);
    if(fx != fy) {
        fa[fx] = fy;
    }
}
int n, a, b, t, ans = 0, flag = 0;
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &a, &b, &t);b++;
        if(flag) continue;
        if(t == 0) {
            Union(a, b);
            Union(a + N, b + N);
        }else {
            Union(a, b + N);
            Union(a + N, b);
        }
        if(Find(a) == Find(a + N) || Find(b) == Find(b + N)) {
            flag = 1;
        }
        ans++;
    }
    printf("%d\n", ans - 1);
    return 0;
}