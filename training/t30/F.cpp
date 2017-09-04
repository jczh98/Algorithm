#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;
struct TwoSat{
    int tot;
    vector<int> G[2 * MAXN];
    bool mark[2 * MAXN];
    int S[MAXN * 2], c;
    bool DFS(int x) {
        if(mark[x ^ 1]) return false;
        if(mark[x]) return true;
        mark[x] = true;
        S[c++] = x;
        for(int i = 0; i < G[x].size(); i++) {
            if(!DFS(G[x][i])) {
                return false;
            }
        }
        return true;
    }
    void Init(int x) {
        this->tot = x;
        for(int i = 0; i < tot * 2; i++) {
            G[i].clear();
        }
        memset(mark, 0, sizeof(mark));
    }
    void AddClause(int x,int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        G[x ^ 1].push_back(y);
        G[y ^ 1].push_back(x);
    }
    bool Solve() {
        for(int i = 0; i < tot * 2; i += 2) {
            if(!mark[i] && !mark[i + 1]) {
                c = 0;
                if(!DFS(i)) {
                    while(c > 0) mark[S[--c]] = false;
                    if(!DFS(i + 1)) return false;
                }
            }
        }
        return true;
    }
}sol;
int n, r, l, x[MAXN], y[MAXN];
int main() {
    scanf("%d%d%d", &n, &r, &l);
    for(int i = 1; i <= l; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    sol.Init(l);
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= l; j++) {
            if(i == j) continue;
            if(x[i] == x[j] && abs(y[i] - y[j]) <= 2 * r) {
                sol.AddClause(i, 1, j, 1);
            }
            if(y[i] == y[j] && abs(x[i] - x[j]) <= 2 * r) {
                sol.AddClause(i, 0, j, 0);
            }
        }
    }
    if(sol.Solve()) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }
    return 0;
}