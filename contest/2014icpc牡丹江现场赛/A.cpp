#include <bits/stdc++.h>
using namespace std;
int t, a, b, x, n, m;
char s[110];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int now, flag;
        if(s[1] == 'b') flag = 1;
        else if(s[1] == 'n') flag = 2;
        else flag = 3;
        double ans = 0;
        for(int i = 1;i <= n;i++) {
            scanf("%d", &now);
            if(now == 0) continue;
            double p = now / 100.0;
            if(flag == 1)
            ans += p * log2(p); 
            else if(flag == 2)
            ans += p * log(p);
            else
            ans += p * log10(p);
        }
        printf("%.9f\n", -ans);
    }
    return 0;
}