#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> ans;
int main() {
    scanf("%d",&n);
    while(n) {
        if(n&1)ans.push_back('A'),n=(n-1)/2;
        else ans.push_back('B'),n=(n-2)/2;
    }
    for(int i=ans.size()-1;i>=0;--i) printf("%c",ans[i]);
    printf("\n");
    return 0;
}