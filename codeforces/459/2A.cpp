#include <bits/stdc++.h>
using namespace std;
int f[100], n, name[20000];
int main() {
    scanf("%d", &n);
    f[1] = 1; f[2] = 1;
    for(int i = 3; i <= 20; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for(int i = 1; i <= 20; ++i) {
        name[f[i]] = 1;
    }
    for(int i = 1; i <= n; ++i) {
        if(name[i] == 1) printf("O"); else printf("o");
    }
    printf("\n");
    return 0;
}