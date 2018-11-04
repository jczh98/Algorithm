#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
string s, ans_s;
map<string, int> mp;
int main() {
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size() - 1; ++i) {
        string t = s.substr(i, 2);
        int cnt = 0;
        for(int j = 0; j < s.size() - 1; ++j) {
            string t2 = s.substr(j, 2);
            if(t2 == t) cnt++;
        }
        if(cnt > ans) {
            ans = cnt; ans_s = t;
        }
    }
    cout << ans_s << endl;
    return 0;
}