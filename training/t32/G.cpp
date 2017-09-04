#include <bits/stdc++.h>
using namespace std;
int n, q, a[1000][1000], x_1, y_1, x_2, y_2, sz, aa, bb;
vector<int> seq;
int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int k = 1; k <= q; k++) {
        scanf("%d%d%d%d", &x_1, &y_1, &x_2, &y_2);
        seq.clear();
        for(int i = x_1; i <= x_2; i++) {
            for(int j = y_1; j <= y_2; j++) {
                seq.push_back(a[i][j]);
            }
        }
        sz = seq.size();
        if(sz % 2 == 0) {
            nth_element(seq.begin(), seq.begin() + sz / 2 - 1, seq.end());
            /*cout << "first" << endl;
            for(int i = 0; i < sz; i++) {
                cout << seq[i] << " ";
            }
            cout << endl;*/
            aa = seq[sz / 2 - 1];
            nth_element(seq.begin(), seq.begin() + sz / 2, seq.end());
            /*cout << "second" << endl;
            for(int i = 0; i < sz; i++) {
                cout << seq[i] << " ";
            }
            cout << endl;*/
            bb = seq[sz / 2];
            printf("%d\n", min(aa, bb));
        }else {
            nth_element(seq.begin(), seq.begin() + sz / 2, seq.end());
            printf("%d\n", seq[sz / 2]);
        }
    }
    return 0;
}

