#include <cstdio>
#include <vector>
using namespace std;
int m, n, tc[2000];
vector<int> ans;
void dfs(int u) {
    if (2*u<=n) dfs(2*u);
    if (2*u+1<=n) dfs(2*u+1);
    ans.push_back(tc[u]);
}
int main() {
    scanf("%d%d", &m, &n);
    while(m--) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &tc[i]);
        }
        int is_min = 1, is_max = 1;
        for (int i = 2; i <= n; ++i) {
            if (tc[i>>1] > tc[i]) is_min = 0;
            if (tc[i>>1] < tc[i]) is_max = 0;
        }
        if (is_max) printf("Max Heap\n");
        else if (is_min) printf("Min Heap\n");
        else printf("Not Heap\n");
        ans.clear();
        dfs(1);
        for (int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
        }
    }
    return 0;
}
