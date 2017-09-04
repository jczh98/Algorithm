#include <bits/stdc++.h>
using namespace std;
struct Node{
    int up, down, lup, ldown, rup, rdown;
}node[10];
int t, pile[10][10], ans[10], tmp[10][10];
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; kase++) {
        for(int i = 0; i <= 6; i++) {
            ans[i] = i;
            for(int j = 1; j <= 6; j++) {
                scanf("%d",&pile[i][j]);
            }
        }
        while(next_permutation(ans, ans + 7)) {
            /*for(int i = 0; i <= 6; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;*/
        }
    }
    return 0;
}