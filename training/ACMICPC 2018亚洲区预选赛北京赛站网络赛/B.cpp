#include <bits/stdc++.h>
using namespace std;
int n, len;
string s[20], tmp;
bool check(char *a, char *b, int lena, int lenb) {
    int pos = 0;
    for(int i = 0; i < lenb; ++i) {
        if(b[i] == a[pos]) pos++;
    }
    return pos == lena;
}
void dfs(int k, string ret) {
    if(k == len) {
        //cout << ret << endl;
        
        return;
    } else {
        for(int i = 0; i < len; ++i) {
            dfs(k+1, ret + tmp[i]);
        }
        dfs(k+1, ret);
    }
}
int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 1; i <= n; ++i) {
            cin >> s[i];
        }
        tmp = s[1];
        len = tmp.size();
        dfs(0, "");
    }
}