#include <bits/stdc++.h>
using namespace std;
string str;
int ans = 0;
int Count(string s, string match) {
    int len = match.size(), cnt = 0;
    int p = s.find(match);
    while(~p) {
        cnt++;
        s = s.substr(p + len, 100);
        p = s.find(match);
    }
    return cnt;
}
int main() {
    cin >> str;
    ans += Count(str, "Danil");
    ans += Count(str, "Olya");
    ans += Count(str, "Slava");
    ans += Count(str, "Nikita");
    ans += Count(str, "Ann");
    if(ans == 1) cout << "YES" << endl; else cout << "NO" << endl;
    return 0;
}

