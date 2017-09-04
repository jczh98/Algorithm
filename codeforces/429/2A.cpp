#include <bits/stdc++.h>
using namespace std;
int n, k, cnt[1000], mi = INT_MAX, cnt_color;
char color[1000];
int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", color + 1);
    for(int i = 1; i <= strlen(color + 1); i++) {
        cnt[color[i]]++;
    }
    for(int i = 'a'; i <= 'z'; i++) {
        if(cnt[i]) {
            cnt[i] -= k;
        }
    }
    for(int i = 'a'; i <= 'z'; i++) {
        if(cnt[i] > 0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}