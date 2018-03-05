#include <bits/stdc++.h>
using namespace std;
int v,e,f,t;
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d", &v, &e);
        printf("%d\n", 2+e-v);
    }
    return 0;
}