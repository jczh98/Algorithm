#include <bits/stdc++.h>
#define MN 2020
using namespace std;
int t,n;
char mp[3000][3000];
bitset<MN> pb[MN],qb[MN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)pb[i].reset(),qb[i].reset();
        for(int i=0;i<n;i++)scanf("%s",mp[i]);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mp[i][j]=='P')pb[i].set(j);
                if(mp[i][j]=='Q')qb[i].set(j);
            }
        }
        int flag1=0,flag2=0;
        for(int i=0;i<n&&!flag1;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pb[i][j]&&((pb[i]&pb[j])!=pb[j]))
                {
                    flag1=1;break;
                }
            }
        }
        for(int i=0;i<n&&!flag2;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((qb[i][j])&&(qb[i]&qb[j])!=qb[j])
                {
                    flag2=1;break;
                }
            }
        }
        if(flag1||flag2) printf("N\n");
        else printf("T\n");
    }
    return 0;
}
