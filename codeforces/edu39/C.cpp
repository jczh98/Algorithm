#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
    cin >> s;
    char cur = 'a';
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] <= cur && cur <= 'z') {
            s[i] = cur; cur++;
        }
    }
    if(cur != 'z' + 1) cout << -1 << endl;
    else cout << s << endl;
    return 0;
}