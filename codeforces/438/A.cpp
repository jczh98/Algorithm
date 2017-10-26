#include <bits/stdc++.h>
using namespace std;
string pat, bark[1000];
int n;
int main() {
    cin >> pat;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> bark[i];
    for(int i = 1; i <= n; ++i) {
        if(bark[i][1] == pat[0]) {
            for(int j = 1; j <= n; ++j) {
                if(bark[j][0] == pat[1]) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}

