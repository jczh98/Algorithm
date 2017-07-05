#include <bits/stdc++.h>
using namespace std;
int t,r,c,row[100],col[100],flag;
char mp[100][100],ans[100][100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        memset(ans,0,sizeof(ans));
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++)
        {
            scanf("%s",mp[i]);
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((mp[i][j]-'0')>0)row[i]++,col[j]++;
            }
        }
        for(int i=1;i<=r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if((mp[i][j]-'0')==0)
                {
                    if(row[i]&&col[j])flag=1;
                }
            }
        }
        if(flag)printf("impossible\n");
        else
        {
            for(int i=1;i<=r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    if((mp[i][j]-'0')==0)
                    {
                        ans[i][j]='N';
                    }else
                    {
                        if(row[i]==1||col[j]==1)ans[i][j]='P';
                        else ans[i][j]='I';
                    }
                }
            }
            for(int i=1;i<=r;i++)printf("%s\n",ans[i]);
        }
        printf("----------\n");
    }
    return 0;
}
