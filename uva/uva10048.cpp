#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 10010
using namespace std;
int c,s,q,d[110][110],kase=1;
int main()
{
    while(scanf("%d%d%d",&c,&s,&q)!=EOF)
    {
        memset(d,0,sizeof(d));
        if(c==0&&s==0&&q==0)break;
        for(int i=1;i<=c;i++)for(int j=1;j<=c;j++)d[i][j]=INF;
        d[1][1]=0;
        int u,v,w;
        for(int i=1;i<=s;i++)scanf("%d%d%d",&u,&v,&w),d[u][v]=w,d[v][u]=w;
        for(int k=1;k<=c;k++)
            for(int i=1;i<=c;i++)
                for(int j=1;j<=c;j++)
                    d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
        if(kase>1)printf("\n");
        printf("Case #%d\n",kase++);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&u,&v);
            if(d[u][v]==INF)printf("no path\n");
            else printf("%d\n",d[u][v]);
        }
    }
    return 0;
}
