#include <cstdio>
#include <vector>
using namespace std;
int n, m, u[20000], v[20000], k;
int pos[2000], num[2000];
vector<int> ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &num[j]);
            pos[num[j]] = j;
        }
        for (int j = 1; j <= m; ++j) {
            if (pos[u[j]] > pos[v[j]]) {
                ans.push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i==ans.size()-1]);
    }
    return 0;
}
