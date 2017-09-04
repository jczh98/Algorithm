#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

/**
 * 関節点の検出
 */

template <int V>
struct JointPoint {
    vector<int> g[V];
    void add(int a, int b) {
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int co;
    int ord[V], low[V];
    bool used[V], jp[V];
    int root[V];
    int sz[V], odd[V];
    void dfs(int i, int b, int ro, int dp) {
//        printf("dfs %d %d\n", i, b);
        ord[i] = low[i] = co; co++;
        root[i] = ro;
        used[i] = true;
        sz[i] = 1;
        odd[i] = false;
        for (int d: g[i]) {
            if (used[d]) {
                low[i] = min(low[i], ord[d]);
            } else {
                dfs(d, i, ro, dp+1);
                low[i] = min(low[i], low[d]);
                if (i == ro && ord[d] != ord[i]+1) {
                    jp[i] = true;
                }
                if (i != ro && low[d] >= ord[i]) {
                    jp[i] = true;
                }
                if (i == ro && sz[d] % 2 == 1) {
                    odd[i] = true;
                }
                if (i != ro && low[d] >= ord[i] && sz[d] % 2 == 1) {
                    odd[i] = true;
                }
                sz[i] += sz[d];
            }
        }
    }

    void exec(int v = V) {
        co = 0;
        fill_n(used, v, false);
        for (int i = 0; i < v; i++) {
            if (used[i]) continue;
            dfs(i, -1, i, 0);
        }
    }
};


const int MN = 200200;

JointPoint<2*MN+1> jp;
vector<P> xg[2*MN+1], yg[2*MN+1];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2*n+1; i++) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        xg[x].push_back(P(y, i));
        yg[y].push_back(P(x, i));
    }

    for (int i = 0; i < 2*n+1; i++) {
        sort(xg[i].begin(), xg[i].end());
        int m = (int)xg[i].size();
        for (int j = 0; j < m-1; j++) {
            P p1 = xg[i][j];
            P p2 = xg[i][j+1];
            jp.add(p1.second, p2.second);
        }
        for (int j = 0; j < m-2; j++) {
            P p1 = xg[i][j];
            P p2 = xg[i][j+2];
            jp.add(p1.second, p2.second);
        }
    }

    for (int i = 0; i < 2*n+1; i++) {
        sort(yg[i].begin(), yg[i].end());
        int m = (int)yg[i].size();
        for (int j = 0; j < m-1; j++) {
            P p1 = yg[i][j];
            P p2 = yg[i][j+1];
            jp.add(p1.second, p2.second);
        }
        for (int j = 0; j < m-2; j++) {
            P p1 = yg[i][j];
            P p2 = yg[i][j+2];
            jp.add(p1.second, p2.second);
        }
    }

    jp.exec(2*n+1);

    int kc = -1;
    for (int i = 0; i < 2*n+1; i++) {
        if (jp.root[i] != i) continue;
        if (jp.sz[i] % 2 == 0) continue;
        if (kc != -1) {
            // 
            for (int i = 0; i < 2*n+1; i++) {
                printf("NG\n");
            }
            return 0;
        }
        kc = i;
    }

    for (int i = 0; i < 2*n+1; i++) {
//        printf("%d %d %d %d %d %d %d\n", i, jp.root[i], kc, jp.jp[i], jp.odd[i], jp.ord[i], jp.low[i]);
        if (jp.root[i] == kc && (!jp.jp[i] || !jp.odd[i])) {
            printf("OK\n");
        } else {
            printf("NG\n");
        } 
    }
    return 0;
}