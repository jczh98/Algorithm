#include <bits/stdc++.h>
using namespace std;
int t, n;
unordered_map<int, int> mp;
int main() {
    for(int i = 0; i * i <= 1e9; ++i) {
        mp[i * i + i + 2] = 1;
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cout << mp[2 * n] << endl;
    }
    return 0;
}

