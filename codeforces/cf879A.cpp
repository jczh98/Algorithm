#include <bits/stdc++.h>
using namespace std;
int n, s, d, last;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &s, &d);
        if(s > last) {
            last = s;
        }else {
            last = s + ((last - s) / d + 1)* d;
        }
    }
    printf("%d\n", last);
    return 0;
}