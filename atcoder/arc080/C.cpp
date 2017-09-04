#include <bits/stdc++.h>
using namespace std;
int n, a, odd = 0, even = 0, four = 0, flag = 0;
int main () {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a);
        if(a % 2 == 1) {
            odd++;
        }else{
            even++;
            if(a % 4 == 0) {
                four++;
            }
        }
    }
    if(four >= odd) {
        flag = 1;
    }
    if(four == odd - 1 && four == even) {
        flag = 1;
    }
    if(flag) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}

