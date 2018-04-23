#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans1, ans2, flag;
void dfs(LL a, LL b) {
    if(!a || !b) {
        flag = 1;
        cout << a << " " << b << endl;
        return;
    }else if(a >= 2 * b)  {
        LL k = a / (2 * b);
        dfs(a - b * 2 * k, b);
    }else if(b >= 2 * a) {
        LL k = b / (2 * a);
        dfs(a, b - 2 * a * k);
    }else {
        ans1 = a; ans2 = b;
        return;
    }
}
LL n, m;
int main() {
    cin >> n >> m;
    dfs(n, m);
    if(!flag) cout << ans1 << " " << ans2 << endl;
    return 0;
}