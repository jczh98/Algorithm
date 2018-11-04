#include <bits/stdc++.h>
using namespace std;
int n, cnt0, cnt1;
string str;
int main() {
    scanf("%d", &n);
    cin >> str;
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '0') cnt0++;
        if(str[i] == '1') cnt1++;
    }
    if(cnt1) {
        printf("1");
        for(int i = 1; i <= cnt0; ++i) printf("0"); printf("\n");printf;
    }else {
        printf("0\n");
    }
    return 0;
}
