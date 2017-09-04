#include <bits/stdc++.h>
using namespace std;
const int MN=1010;
struct Point
{
    int x,y,id;
    Point(int x=0,int y=0,int id=0):x(x),y(y),id(id){};
    operator < (const Point &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x;
        else return y<rhs.y;
    }
    //Point operator - (const Point &rhs) const {return Point(x-rhs.x,y-rhs.y,id);}
    //int operator ^ (const Point &rhs) const {return x*rhs.y-y*rhs.x;}
}p[MN],convex[MN];
//double Length(Point a,Point b){return sqrt((double)(a.x-b.x)*(a.x-b.x)+(double)(a.y-b.y)*(a.y-b.y));}
struct Edge
{
    int u,v;
}edge[MN*MN];
int n;
int cnt=1,vis[MN][MN]={0},deg[MN]={0};
void AddEdge(int u,int v)
{
    edge[cnt].u=u;deg[u]++;
    edge[cnt].v=v;deg[v]++;
    cnt++;
    vis[u][v]=1;vis[v][u]=1;
}
/*int ConvexHull()
{
    int top=0;
    for(int i=1;i<=n;i++)
    {
        while(top>1&&((convex[top]-convex[top-1])^(p[i]-convex[top-1]))<=0)top--;
        convex[++top]=p[i];
    }
    int k=top;
    for(int i=n;i>=1;i--)
    {
        while(top>k&&((convex[top]-convex[top-1])^(p[i]-convex[top-1]))<=0)top--;
        convex[++top]=p[i];
    }
    return top-1;
}*/
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);p[i].id=i;
    }
    sort(p+1,p+1+n);
    for(int i=1;i<n;i++)
    {
        AddEdge(p[i].id,p[i+1].id);
    }
    //int m=ConvexHull();
    int flag=1;
    /*cout<<endl;
    cout<<m<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<convex[i].id<<endl;
    }
    cout<<endl;*/
    for(int i=1;i+2<=n;i++)
    {
        if((p[i+2].y-p[i].y)*(p[i+1].x-p[i].x)!=(p[i+1].y-p[i].y)*(p[i+2].x-p[i].x))
        {
            if(vis[p[i].id][p[i+1].id])
            {
                if(deg[p[i].id]<=2&&deg[p[i+2].id]<=2)
                {
                    flag=0;AddEdge(p[i].id,p[i+2].id);break;
                }
            }else
            {
                if(deg[p[i].id]<=2&&deg[p[i+1].id]<=2)
                {
                    flag=0;AddEdge(p[i].id,p[i+1].id);break;
                }
            }
        }
    }
    if(flag)printf("-1\n");
    else
    {
        for(int i=1;i<cnt;i++)
        {
            printf("%d %d\n",edge[i].u,edge[i].v);
        }
    }
    return 0;
}
