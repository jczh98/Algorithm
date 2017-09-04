#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
const int N = 300;
int C[N][N], tot = 0, cnt[N][N];
double A[N][N];
double x[N];
int a, m, b, n;
void Build() {
    tot = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cnt[i][j] = tot++;
    A[0][0] = 1;
    for (int i = 1; i <= tot; i++) {
        for (int j = 0; j <= i; j++) {
            int l = j, r = i - j;
            double tmp = C[i][l] * pow(a * 1.0, l / m) * pow(b * 1.0, r / n);
            l %= m;
            r %= n;
            A[cnt[l][r]][i] += tmp;
        }
    }
    A[tot][tot] = 1;
    A[tot][tot + 1] = 1;
    tot++;
}
void Gauss() {
    for (int i = 0; i < tot; i++) {
        int r = i;
        for (int j = i + 1; j < tot; j++) {
            if (fabs(A[j][i]) > fabs(A[r][i])) r = j;
        }
        if (fabs(A[r][i]) < eps) continue;
        for (int j = i; j <= tot; j++) swap(A[r][j], A[i][j]);
        for (int j = 0; j < tot; j++) {
            if (i == j) continue;
            if (fabs(A[j][i]) < eps) continue;
            double tmp = A[j][i] / A[i][i];
            for (int k = i; k <= tot; k++) {
                A[j][k] -= tmp * A[i][k];
            }
        }
    }
    x[tot - 1] = 1.0;
    for(int i = tot - 2; i >= 0; i--) {
        x[i] = A[i][tot] / A[i][i];
    }
}
int main() {
    freopen("J.in", "r", stdin);
    for (int i = 0; i <= 20; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    while (scanf("%d%d%d%d", &a, &m, &b, &n) != EOF) {
        if (a == 0 && m == 0 && b == 0 && n == 0) break;
        memset(A, 0, sizeof(A));
        Build();
        Gauss();
        for(int i = tot - 1; i >= 0; i--) {
            if(x[i] < eps) x[i] -= 0.5;
            else x[i] += 0.5;
            printf("%d ", (int) (x[i] ));
        }
        printf("\n");
    }
    return 0;
}