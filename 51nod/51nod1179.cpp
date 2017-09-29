#include <bits/stdc++.h>
using namespace std;
int n, s[50005], cnt[1000005], max_s, sum;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        cnt[s[i]]++;
        max_s = max(s[i], max_s);
    }
    for(int i = max_s; i; --i) {
        sum = 0;
        for(int k = i; k <= max_s; k += i) {
            sum += cnt[k];
            if(sum >= 2) {
                printf("%d\n", i);
                return 0;
            }
        }
    }
    return 0;
}

