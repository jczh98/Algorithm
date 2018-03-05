#include <iostream>
#include <cstdio>
#include <cstring>
#define ULL unsigned long long
#define UINT unsigned int
using namespace std;
int N,M,K,ans;
void dfs(int row,int deep,UINT col,UINT dig,UINT adg){//所在行,已放皇后数量,(列、左对角线、右对角线)的状态
    if(deep == K){
        ans++;
        return;
    }
    if(row==N) return;
    UINT status=~(col|dig|adg);
    while(status){
        UINT t=status&(-status);
        dfs(row+1,deep+1,(t|col),(t|dig)>>1,(t|adg)<<1);
        status^=t;
    }
    if((N-row-1)+deep>=K)
        dfs(row+1,deep,col,dig>>1,adg<<1);
}
int main(){
    while(cin>>N>>M>>K){
        if(N<M) swap(N,M);//保证列数少，方便状态压缩
        ans=0;
        UINT col=(1<<N)-1;
        col=~col;
        dfs(0,0,col,0,0);
        cout<<ans<<endl;
    }
    return 0;
}