#include<bits/stdc++.h>
#define MN 100100
using namespace std;
int t,s,k,vis[MN],sg[MN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&k);
        /*for(int i=1;i<=s;i++)
        {
            memset(vis,0,sizeof(vis));
            if(k==1)
            {
                vis[sg[i-1]]=1;
            }else
            {
                for(int j=1;j<=s;j*=k)if(i-j>=0)vis[sg[i-j]]=1;
            }
            for(int j=0;j<=s;j++)if(!vis[j]){sg[i]=j;break;}
        }
        for(int i=0;i<=s;i++)printf("%d ",sg[i]);printf("\n");*/
        if(k%2)
        {
            sg[0]=0;sg[1]=1;
            cout<<sg[s%2]<<endl;
        }else
        {
            for(int i=0;i<k;i++)
            {
                if(i%2==0)sg[i]=0;
                else sg[i]=1;
            }
            sg[k]=k;
            cout<<sg[s%(k+1)]<<endl;
        }
    }
}
