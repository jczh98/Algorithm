#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<vector<LL> > Mat;
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

Mat Multiply(Mat mat1, Mat mat2, LL MOD) {
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

Mat MatQuickPow(Mat a, LL b, LL MOD) {
    Mat res(a.size(), vector<LL>(a[0].size()));
    res = Init(res);
    while (b) {
        if (b & 1)res = Multiply(res, a, MOD);
        a = Multiply(a, a, MOD);
        b >>= 1;
    }
    return res;
}
LL p, q, r, n, b0 = 3, a0 = 0, f1, a1;
const LL MOD = 1e9 + 7;
int main() {
    cin >> p >> q >> r >> n;
    a1 = r; f1 = a1 * b0;
    if(n == 1) {
        cout << f1 % MOD<< endl;
        return 0;
    }
    Mat A = {{q, p * b0, b0}, {0, p, 1}, {0, 0, 1}};
    Mat B = {{f1}, {a1}, {r}};
    A = MatQuickPow(A, n - 1, MOD);
    Mat res = Multiply(A, B, MOD);
    cout << res[0][0] << endl;
    return 0;
}

