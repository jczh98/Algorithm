#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int n;
LL ans = 1, cnt_ver = 0, cnt_hor = 0;
string s1, s2;
vector<int> type;
int main() {
    cin >> n;
    cin >> s1 >> s2;
    s1 += '\0';
    for(int i = 0; i < s1.size() - 1; i++) {
        if(s1[i] == s1[i + 1]) {
            i++;
            type.push_back(1);
        }else {
            type.push_back(0);
        }
    }
    if(type[0] == 1) {
        ans = 6;
    }else {
        ans = 3;
    }
    int last = type[0];
    for(int i = 1; i < type.size(); i++) {
        if(last == 1) {
            if(type[i] == 1) {
                ans = (ans * 3) % MOD;
            }
        }else {
            ans = (ans * 2) % MOD;
        }
        last = type[i];
    }
    cout << ans << endl;
    return 0;
}

