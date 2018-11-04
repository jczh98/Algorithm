#include <bits/stdc++.h>
using namespace std;
int t, n, m, f[10005];
vector<int> ans;
int main() {
    scanf("%d", &t);
    while(t--) {
        ans.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= m; ++i) {
            scanf("%d", &f[i]);
        }
        for(int i = 1; i <= m;) {
            if(!f[i]) ++i;
            else {
                ans.push_back(i);
                for(int j = i; j <= m; ++j) {
                    f[j] -= f[j-i];
                }
            }
        }
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], (i==ans.size()-1)?'\n':' ');
        }
    }
}