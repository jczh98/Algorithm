#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, a[200005], Max = 0, Max_num, f[200005], last[200005];
map<int, int> pos;
vector<int> ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); 
    }
    for(int i = 1; i <= n; ++i) {
        f[i] = f[pos[a[i] - 1]] + 1;
        last[i] = pos[a[i] - 1];
        pos[a[i]] = i;
        if(Max < f[i]) {
            Max = f[i]; Max_num = i;
        }
    }
    while(Max_num) {
        ans.push_back(Max_num); Max_num = last[Max_num];
    }
    cout << Max << endl;
    for(int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    return 0;
}