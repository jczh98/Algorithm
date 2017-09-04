#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,diff,same,mx,mi;
char derek[100100],alfia[100100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        diff=0;same=0;
        scanf("%d%d%d",&n,&x,&y);
        scanf("%s%s",derek+1,alfia+1);
        for(int i=1;i<=n;i++)
        {
            if(derek[i]==alfia[i])same++;
            else diff++;
        }
        mx=min(x,same);
        mi=max(0,x-diff);
        if(2*mx+diff-x>=y&&mi<=y)cout<<"Not lying"<<endl;
        else cout<<"Lying"<<endl;
    }
    return 0;
}
