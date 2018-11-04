#include <bits/stdc++.h>
using namespace std;
int p[500005], a[500005];
map<int, int> mp;
int rev(int x) {
    if(x == 0) return 0;
    int pos = 0;
    for(int i = 30; i >= 0; --i) {
        if(x&(1<<i)) {
            pos = i;
            break;
        }
    }
    for(int i = pos; i >= 0; --i) {
        x^=(1<<i);
    }
    return x;
}
int main() {
    int n, ans = INT_MAX;
    scanf("%d", &n);
    // for(int i = 0; i < n; ++i) p[i] = i;
    // do {
    //     int tmp = 0;
    //     for(int i = 0; i < n; ++i) tmp += i&p[i];
    //     if(ans > tmp) {
    //         ans = tmp;
    //         memcpy(a, p, sizeof(p));
    //     }
    // }while(next_permutation(p,p+n));
    // for(int i = 0; i < n; ++i) {
    //     cout << a[i] << " ";
    // }cout << endl;
    for(int i = n - 1; i >= 0; --i) {
        int x = rev(i);
        if(mp.find(i) != mp.end()) {
            p[i] = mp[i];
        }else {
            mp[i] = x; mp[x] = i;
            p[i] = x;            
        }
    }
    for(int i = 0; i < n; ++i) {
        printf("%d%c", p[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}