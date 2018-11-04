#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i, x, y) for (int i = x; i < y + 1; i++)
#define fs(i, x, y) for (int i = x; i > y - 1; i--)
#define all(x) x.begin(), x.end()
#define Ins(x) inserter(x, x.begin())
#define pi 3.14159265358979323846
using namespace std;
typedef long long ll;
int n;
typedef struct node {
    int a, b;//a 学分 b成绩
};
node mes[100010];
int k, up = 0, down = 0;
int cmp(node aa, node bb) { 
    return (up - aa.a*aa.b) * (down - bb.a) < (up - bb.a*bb.b) * (down - aa.a); 
}
int main() {
    scanf("%d%d", &n, &k);
    ff(i, 1, n) scanf("%d", &mes[i].a);
    ff(i, 1, n) scanf("%d", &mes[i].b);
    for(int i = 1; i <= n; ++i) {
        up += mes[i].a * mes[i].b;
        down += mes[i].a;
    }
    sort(mes + 1, mes + 1 + n, cmp);
    double ans = 0, sum = 0;
    ff(i, 1, n - k) {
        ans += mes[i].a * mes[i].b;
        sum += mes[i].a;
    }
    ans /= sum;
    printf("%.9f", ans);
    return 0;
}
