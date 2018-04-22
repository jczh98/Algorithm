#include <bits/stdc++.h>
using namespace std;
string num; int n;
bool check(string s) {
    int flag = 1;
    for(int i = s.size() - 1; i >= 0; --i) {
        if(flag && s[i] == '0') return 0;
        if(s[i] != '0') flag = 0;
    }
    return 1;
}
int main() {
    cin >> num; n = num.size(); int ans = INT_MAX;
    for(int s = 0; s < (1 << n) - 1; ++s) {
        int del = 0; string tmp;
        for(int i = 0; i < n; ++i) {
            if(s & (1 << i)) {
                del++;
            }else tmp += num[n - i - 1];
        }
        if(!check(tmp)) continue;
        //cout << tmp << endl;
        int new_num = 0, base = 1;
        for(int i = 0; i < tmp.size(); ++i) {
            new_num += base * (tmp[i] - '0'); base *= 10;
        }
        int k = sqrt(new_num);
        if(k * k == new_num)  {
            ans = min(del, ans);
        }
    }
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}