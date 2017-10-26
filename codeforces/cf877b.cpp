#include<bits/stdc++.h>
using namespace std;
int f[5005][3], lenth, ans = 0;// 0 a 1 aba 2 ab
char str[5005];
int main() {
    scanf("%s", str + 1);
    lenth = strlen(str + 1);
    for(int i = 1; i <= lenth; ++i) {
        for(int j = 0; j < i; ++j) {
            if(str[i] == 'a') {
                f[i][0] = max(f[i][0], f[j][0] + 1);
                f[i][1] = max(f[i][1], f[j][2] + 1);
                f[i][1] = max(f[i][1], f[j][1] + 1);
            }            
            if(str[i] == 'b') {
                f[i][2] = max(f[i][2], f[j][0] + 1);
                f[i][2] = max(f[i][2], f[j][2] + 1);
            }
        }
    }
    for(int i = 1; i <= lenth; ++i) ans = max(ans, max(f[i][0], max(f[i][1], f[i][2])));
    printf("%d\n", ans);
    return 0;
}