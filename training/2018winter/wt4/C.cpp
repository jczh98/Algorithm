#include <bits/stdc++.h>
using namespace std;
int t,n,num[15];
string problem;
int main() {
    freopen("scoreboard.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        cin>>problem;
        for(int i=1;i<=13;++i) {
            scanf("%d",&num[i]);
        }
        for(int i=0;i<n;++i)num[problem[i]-'A'+1]=0;
        cout<<(char)((max_element(num+1,num+1+13)-num)-1+'A')<<endl;
    }
    return 0;
}