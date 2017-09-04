#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<vector<LL> > Mat;
const LL MOD = 1000000LL;

void Print(Mat mat) {
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
Mat Clear(Mat mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}

Mat Init(Mat mat) {
    Clear(mat);
    for (int i = 0; i < mat.size(); i++) {
        mat[i][i] = 1;
    }
    return mat;
}

Mat Multiply(Mat mat1, Mat mat2) {
    Mat mat(mat1.size(), vector<LL>(mat2[0].size()));
    Clear(mat);
    for (int i = 0; i < mat1.size(); i++) {
        for (int j = 0; j < mat2[0].size(); j++) {
            for (int k = 0; k < mat1[0].size(); k++) {
                mat[i][j] = (mat[i][j] + (mat1[i][k] % MOD) * (mat2[k][j] % MOD)) % MOD;
            }
        }
    }
    return mat;
}

Mat MatQuickPow(Mat a, LL b) {
    Mat res(a.size(), vector<LL>(a[0].size()));
    res = Init(res);
    while (b) {
        if (b & 1)res = Multiply(res, a);
        a = Multiply(a, a);
        b >>= 1;
    }
    return res;
}

LL n, k, l;
int main() {
    cin >> n >> k >> l;
    k %= MOD; l %= MOD; n /= 5;
    Mat A = {{k, l}, {1, 0}};
    LL x1 = k, x2 = (k * k % MOD + l) % MOD;
    if(n == 1) {
        printf("%06lld\n", x1);
        return 0;
    }else if(n == 2){
        printf("%06lld\n", x2);
        return 0;
    }
    Mat b = {{x2}, {x1}};
    Mat res = MatQuickPow(A, n - 2);
    Mat ans = Multiply(res, b);
    printf("%06lld", ans[0][0]);
    return 0;
}

