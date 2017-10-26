#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, a[2005], b[2005], ans = 0;
unordered_map<LL, LL> Hash;
int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i], Hash[a[i]] = 1;
    for(int i = 1; i <= n; ++i) cin >> b[i], Hash[b[i]] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(Hash.find(a[i] ^ b[j]) != Hash.end()) ans++;
        }
    }
    if(!(ans & 1)) cout << "Karen" << endl; else cout << "Koyomi" << endl;
    return 0;
}