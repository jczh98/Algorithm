#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
using namespace std;
int n, m, k;
set<int> G;
map<int,vector<int> > pr;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        pr[x].push_back(y);pr[y].push_back(x);
    }
    while(m--) {
        scanf("%d", &k);
        G.clear();
        while(k--) {
            int x;
            scanf("%d", &x);
            G.insert(x);
        }
        bool flag = true;
        for(auto x:G) {
            for (auto y:pr[x]) {
                if (G.find(y)!=G.end()) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
}
