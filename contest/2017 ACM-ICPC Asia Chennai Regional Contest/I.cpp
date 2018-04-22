#include <bits/stdc++.h>
using namespace std;
string s;
int t, n, k, l2h, h2l, check1, check2;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        cin >> s;
        l2h = h2l = check1 = check2 = 0;
        for(int i = 0; i < n; ++i) {
            if(islower(s[i])) {
                l2h++;
            }else {
                h2l++;
            }
        }
        if(h2l <= k) check1 = 1;
        if(l2h <= k) check2 = 1;
        if(check1 && check2) printf("both\n");
        else if(check1 && !check2) printf("chef\n");
        else if(!check1 && check2) printf("brother\n");
        else printf("none\n");
    }
    return 0;
}