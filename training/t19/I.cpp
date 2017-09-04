#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
int t,n,w[1100],query,id,len[1100],ans;
char magic[1100][1100];
ULL Hash[1100][1100],base[1100];
vector<int> pos[1100];
ULL seed=23,mod=1e9+7;
ULL GetHash(int i,int j,int length)
{
    return (Hash[i][j]-Hash[i][j+1]*base[length]+mod)%mod;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        base[0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%s%d",magic[i],&w[i]);
            len[i]=strlen(magic[i]);
            base[i]=(base[i-1]*seed)%mod;
            pos[i].clear();
        }
        for(int i=1;i<=n;i++)
        {
            Hash[i][len[i]]=0;
            for(int j=len[i]-1;j>=0;j--)
            {
                Hash[i][j]=(Hash[i][j+1]*seed+magic[i][j]-'a')%mod;
            }
        }
        for(int x=1;x<=n;x++)
        {
            for(int i=1;i<=n;i++)
            {
                if(len[x]==len[i])
                {
                    if(GetHash(x,0,len[x])==GetHash(i,0,len[i]))
                    {
                        pos[x].push_back(i);
                    }
                }else if(len[x]<len[i])
                {
                    if(GetHash(x,0,len[x])==GetHash(i,len[i]-len[x],len[x]))
                    {
                        pos[x].push_back(i);
                    }
                }
            }
        }
        scanf("%d",&query);
        int x,y;
        for(int i=1;i<=query;i++)
        {
            scanf("%d",&id);
            if(id==1)
            {
                scanf("%d%d",&x,&y);
                w[x]=y;
            }else
            {
                ans=0;
                scanf("%d",&x);
                for(int j=0;j<pos[x].size();j++)
                {
                    if(w[x]>=w[pos[x][j]])ans++;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
