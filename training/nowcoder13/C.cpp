#include <bits/stdc++.h>
using namespace std;
char str[100005];
int n, k;
int main() {
    scanf("%d%d%s", &n, &k, str + 1);
    int p = 1;
    while(k--) {
        for(; p <= n; ++p) {
            if(str[p] == '4' && str[p + 1] == '7') break;
        }
        if(p == n + 1) break;
        if(p & 1)  {
            if(str[p + 2] == '7') {
                if((k & 1) == 0) {
                    str[p + 1] = '4'; 
                }
                break;
            }
            str[p + 1] = '4'; 
        }else {
            if(str[p - 1] == '4') {
                if((k & 1) == 0) {
                    str[p] = '7';
                }
                break;
            }
            str[p] = '7';
        }
    }
    cout << str + 1 << endl;;
}