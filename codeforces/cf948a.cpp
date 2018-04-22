#include <bits/stdc++.h>
using namespace std;
char mp[505][505];
int r, c, flag, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int main() {
    scanf("%d%d", &r, &c);
    for(int i = 1; i <= r; ++i) scanf("%s", mp[i] + 1);
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(mp[i][j] == 'W') {
                for(int l = 0; l < 4; ++l) {
                    if(mp[i + dx[l]][j + dy[l]] == 'S') {
                        flag = 1;
                    }else if(mp[i + dx[l]][j + dy[l]] == '.') {
                        mp[i + dx[l]][j + dy[l]] = 'D';
                    }
                }
            }
        }
    }
    if(flag) {
        printf("No\n");
    }else {
        printf("Yes\n");
        for(int i = 1; i <= r; ++i) {
            for(int j = 1; j <= c; ++j) {
                printf("%c", mp[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}