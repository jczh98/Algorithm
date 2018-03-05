#include <bits/stdc++.h>
using namespace std;  
typedef long long LL;
LL dp[100][10];
int len;
char n[100],a[100];
LL dfs(int pos, int pre, bool limit) {
    if(pos==-1) return 1;
    if(!limit&&dp[pos][pre]!=-1)return dp[pos][pre];
    int up=limit?(a[pos]-'0'):9;
    LL ans=0;
    for(int i=pre;i<=up;++i) ans+=dfs(pos-1,i,limit&&i==(a[pos]-'0'));
    if(!limit)dp[pos][pre]=ans;
    return ans;
} 
bool judge() {
    for(int i=0;i<len-1;++i){
        if(n[i]>n[i+1])return false;
    }
    return true;
}
int t;
int main() {
    scanf("%d",&t);
    while(t--) {
        memset(dp,-1,sizeof(dp));
        scanf("%s",n);
        len=strlen(n);
        if(!judge()){printf("-1\n");continue;}
        for(int i=len-1;i>=0;--i)a[len-1-i]=n[i];
        printf("%lld\n",dfs(len-1,0,true)-1);
    }
    return 0;
}