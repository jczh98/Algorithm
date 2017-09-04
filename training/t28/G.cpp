#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val, id;
    bool operator < (const Node & rhs) const {
        return val < rhs.val;
    }
}a[305];
int L, C, X[305][305], cnt_l[30000005], cnt_c[30000005], l[305], c[305], b[305];
int Solve(int * array, int n) {
    for(int i = 1; i <= n; i++) a[i].val = array[i], a[i].id = i;
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) b[i] = a[i].id;
    int ans = 0;
    for(int i = 1; i <= n ;i++) {
        if(b[i] != i) {
            for(int j = i; j <= n; j++) {
                if(b[j] == i) {
                    swap(b[j], b[i]);
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}
int main() {
    scanf("%d%d", &L, &C);
    for(int i = 1; i <= L; i++) {
        for(int j = 1; j <= C; j++) {
            scanf("%d", &X[i][j]);
        }
    }
    int flag1 = 0, flag2 = 0, cnt, sum;
    for(int i = 1; i <= L; i++) {
        cnt_l[(i - 1) * C * C + (1 + C) * C / 2] = 1;
        //cout << (i - 1) * C * C + (1 + C) * C / 2 << endl;
    }
    for(int i = 1; i <= C; i++) {
        cnt_c[i * L + C * (L - 1) * L / 2] = 1;
        //cout << i * L + C * (L - 1) * L / 2 << endl;
    }
    cnt = 0;
    for(int i = 1; i <= L; i++) {
        sum = 0;
        for(int j = 1; j <= C; j++) {
            sum += X[i][j];
        }
        //cout << sum << endl;
        if(cnt_l[sum]) cnt++;
    }
    //cout << cnt << endl;
    if(cnt == L) flag1 = 1;
    cnt = 0;
    for(int j = 1; j <= C; j++) {
        sum = 0;
        for(int i = 1; i <= L; i++) {
            sum += X[i][j];
        }
        if(cnt_c[sum]) cnt++;
    }
    if(cnt == C) flag2 = 1;
    //cout << flag1 << " " << flag2 << endl;
    if(flag1 && flag2) {
        for(int i = 1; i <= L; i++) {
            l[i] = X[i][1];
        }
        for(int i = 1; i <= C; i++) {
            c[i] = X[1][i];
        }
        int ans = 0;
        ans += Solve(l, L);
        ans += Solve(c, C);
        printf("%d\n", ans);
    }else {
        printf("*\n");
    }
    return 0;
}

