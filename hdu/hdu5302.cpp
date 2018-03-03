#include <bits/stdc++.h>
using namespace std;
int t, w[10], b[10];
vector<int> pos;
int main() {
    scanf("%d", &t);
    while(t--) {
        for(int i = 0; i < 3; ++i) scanf("%d", &w[i]);
        for(int i = 0; i < 3; ++i) scanf("%d", &b[i]);
        if(w[1] & 1 || b[1] & 1) {printf("-1\n"); continue;}
        int n = w[0] + w[1] + w[2];
        if(n == 4) {printf("4\n1 2 0\n1 3 0\n 2 3 1\n3 4 1\n"); continue;}
        printf("%d\n", w[2] + b[2] + w[1] / 2 + b[1] / 2);
        w[2]++;
        int k = 1;
        while(w[2]--) {
            printf("%d %d 0\n", k, k + 1); ++k;
        }
        w[1]-=2;++k;
        while(w[1]) {
            printf("%d %d 0\n", k, k + 1); k+=2; w[1]-=2;
        }
        pos.clear();
        for(int i = 1; i <= n; i += 2) pos.push_back(i);
        for(int i = 2; i <= n; i += 2) pos.push_back(i);
        k = 0;
        b[2]++;
        while(b[2]--) {
            printf("%d %d 1\n", pos[k], pos[k + 1]); ++k;
        } 
        b[1] -=2; ++k;
        while(b[1]) {
            printf("%d %d 1\n", pos[k], pos[k + 1]); k += 2; b[1] -= 2;
        }
    }
    return 0;
}