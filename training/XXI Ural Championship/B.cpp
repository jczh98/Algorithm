#include <bits/stdc++.h>
using namespace std;
int k[5], b[5], s[5], h[5][110], ind[5][20005];
int main() {
    for(int i = 1; i <= 2; ++i) {
        cin >> k[i] >> b[i] >> s[i];
        for(int j = 1; j <= k[i]; ++j) cin >> h[i][j];
        for(int j = 1; j <= k[i]; ++j) {
            for(int l = b[i] + (j - 1) * s[i]; l < b[i] + j * s[i]; ++l) {
                ind[i][l] = j;
            }
        }
    }
    for(int i = 0; i <= 20000; i++) {
        while(h[1][ind[1][i]] > 0 && h[2][ind[2][i]] > 0) h[1][ind[1][i]]--, h[2][ind[2][i]]--;
    }
    for(int i = 1; i <= 2; i++) {
        for(int j = 1; j <= k[i]; j++) {
            if(h[i][j] > 0) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}

