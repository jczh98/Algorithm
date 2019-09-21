#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
int m, n, tc[20000];
map<int,int> mp;
int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tc[i]);
        mp[tc[i]] = i;
    }
    while(m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (mp[u] == 0 && mp[v] == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (mp[u] == 0 || mp[v] == 0) {
            printf("ERROR: %d is not found.\n", mp[u] == 0?u:v);
        } else {
            int p;
            for (int i = 1; i <= n; ++i) {
                p = tc[i];
                if ((p<=u&&p>=v)||(p<=v&&p>=u)) {
                    break;
                }
            }
            if (p == u || p == v) {
                printf("%d is an ancestor of %d.\n", p==u?u:v, p==u?v:u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, p);
            }
        }
    }
    return 0;
}
