#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#define MN 100100
using namespace std;

int t,n,cnt,cnt1,cnt2,flag,num[30],mat[30][30],vis[30],out_deg[30],in_deg[30];
string s[MN];

int Get(char c) {return c-'a';}

void Dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<26;i++)
    {
        if(!vis[i]&&mat[u][i])
        {
            Dfs(i);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        memset(mat,0,sizeof(mat));
        memset(in_deg,0,sizeof(in_deg));
        memset(out_deg,0,sizeof(out_deg));
        memset(num,0,sizeof(num));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            mat[Get(s[i][0])][Get(s[i][s[i].size()-1])]=1;
            out_deg[Get(s[i][0])]++;in_deg[Get(s[i][s[i].size()-1])]++;
            num[Get(s[i][0])]=num[Get(s[i][s[i].size()-1])]=1;
        }
        cnt=cnt1=cnt2=0;flag=0;;
        for(int i=0;i<26;i++)
        {
            if(in_deg[i]!=out_deg[i])
            {
                cnt++;
                if(out_deg[i]-in_deg[i]==1)cnt1++;
                else if(in_deg[i]-out_deg[i]==1)cnt2++;
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(cnt1&&cnt2&&cnt1+cnt2>2)flag=1;
        if(!flag)
        {
            memset(vis,0,sizeof(vis));
            for(int i=0;i<26;i++)
            {
                if(out_deg[i])
                {
                    Dfs(i);
                    break;
                }
            }
            int flag2=0;
            for(int i=0;i<26;i++)
            {
                if((in_deg[i]||out_deg[i])&&!vis[i])
                {
                    flag2=1;break;
                }
            }
            if(flag2)printf("The door cannot be opened.\n");
            else printf("Ordering is possible.\n");
        }else printf("The door cannot be opened.\n");
    }
    return 0;
}
