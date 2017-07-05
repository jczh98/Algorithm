#include <bits/stdc++.h>
using namespace std;
#define MN 1010
using namespace std;
int t,n,x_1,y_1,x_2,y_2,c[MN][MN];
char qqq[10];
int Lowbit(int x){return x&(-x);}
void Add(int x,int y,int v)
{
    for(int i=x;i<=MN;i+=Lowbit(i))
    {
        for(int j=y;j<=MN;j+=Lowbit(j))
        {
            c[i][j]+=v;
        }
    }
}
int Sum(int x,int y)
{
    int ans=0;
    for(int i=x;i>0;i-=Lowbit(i))
    {
        for(int j=y;j>0;j-=Lowbit(j))
        {
            ans+=c[i][j];
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&qqq);
            if(qqq[0]=='C')
            {
                scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
                Add(x_1,y_1,1);Add(x_2+1,y_1,1);Add(x_1,y_2+1,1);Add(x_2+1,y_2+1,1);
            }else
            {
                scanf("%d%d",&x_1,&y_1);
                if(Sum(x_1,y_1)%2==0)
                {
                    printf("0\n");
                }else printf("1\n");
            }
        }
    }
    return 0;
}
