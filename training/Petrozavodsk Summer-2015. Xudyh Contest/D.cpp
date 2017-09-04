#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
LL n, m, t, cnt_x, check[1000], flag, ans[1050], fac[1000];
vector<LL> f[105];
LL QuickPow(LL a, LL b) {
    LL res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    fac[0] = 1;
    for(LL i = 1; i <= 100; i++) {
        fac[i] = (fac[i - 1] * i % MOD) % MOD;
    }
    cin >> t; cin.get();
    while(t--) {
        cnt_x = 0;
        flag = 0;
        cin >> n >> m; cin.get();
        string t;
        stringstream ss;
        for(int i = 1; i <= m; i++) {
            f[i].clear();
            memset(check, 0, sizeof(check));
            getline(cin, t);
            ss.clear();
            ss.str(t);
            LL x, cnt = 1;
            f[i].push_back(0);
            while(ss >> x) {
                f[i].push_back(x);
                if(x == -1) {
                    cnt_x++;
                }else {
                    check[x] = 1;
                }
            }
            if(x != -1) {
                for(int i = 1; i <= n; i++) {
                    if(!check[i]) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag) {
            cout << 0 << endl;
        }else {
            if(cnt_x == 0) {
                for(int i = 1; i <= n; i++) {
                    ans[i] = i;
                }
                for(int i = m; i >= 1; i--) {
                    for(int j = 1; j <= n; j++) {
                        ans[j] = f[i][ans[j]];
                        cout << ans[j] << endl;
                    }
                    cout << endl;
                }
                int ckc = 0;
                for(int i = 1; i <= n; i++) {
                    if(ans[i] != i) {
                        ckc = 1;
                        break;
                    }
                }
                if(ckc) {
                    cout << 0 << endl;
                }else {
                    cout << 1 << endl;
                }
            }else {
                cout << QuickPow(fac[n], cnt_x - 1) << endl;
            }
        }
    }
    return 0;
}

