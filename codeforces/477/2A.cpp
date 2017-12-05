#include <bits/stdc++.h>
using namespace std;
string str;int ans = 0;
int main() {
    cin >> str;int l = str.size();
    for(int i = 0; i < l; ++i) {
        for(int j = i + 1; j < l; ++j) {
            for(int k = j + 1; k < l; ++k) {
                if(str[i] == 'Q' && str[j] == 'A' && str[k] == 'Q') ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}