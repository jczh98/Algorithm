#include <bits/stdc++.h>
using namespace std;
const int MN=20;
int n,m,ans=0,pointer=1,musician[MN*MN][100],sign[MN][10],ori[100100],mxlen,x,cur,i,j,k;
char str[10];
int GetNum(char ss[])
{
    if(ss[1]=='b')return ss[0]-'A'+7;
    else if(ss[1]=='#')return ss[0]-'A'+14;
    else return ss[0]-'A';
}
int main()
{
    memset(musician,0,sizeof(musician));
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=7;j++)
        {
            scanf("%s",str);
            sign[i][j]=GetNum(str);
        }
    }
    int cnt=1;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=7;k++)
            {
                musician[cnt][sign[i][k]]=1;
                musician[cnt][sign[j][k]]=1;
            }
            cnt++;
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        ori[i]=GetNum(str);
    }
    while(pointer<=n)
    {
        mxlen=0;
        for(i=1;i<cnt;i++)
        {
            for(cur=0;pointer+cur<=n;cur++)
            {
                if(musician[i][ori[pointer+cur]]==0)break;
            }
            mxlen=max(mxlen,cur);
        }
        pointer+=mxlen;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
