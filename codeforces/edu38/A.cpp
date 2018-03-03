#include <bits/stdc++.h>
using namespace std;
string s;
int vis[1000], n;
bool check(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return true;
    else return false;
}
bool check_(string str) {
    for(int i = 0; i < str.size() - 1; ++i) {
        if(check(str[i]) && check(str[i + 1])) return true;
    }
    return false;
}
int main() {
    cin >> n >> s;
    while(check_(s)) {
        int flag = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(check(s[i]) && check(s[i + 1])) {
                flag = i + 1; break;
            }
        }
        string tmp;
        for(int i = 0; i < s.size(); ++i) {
            if(i == flag) continue;
            tmp += s[i];
        }
        s = tmp;
    }
    cout << s << endl;
    return 0;
}