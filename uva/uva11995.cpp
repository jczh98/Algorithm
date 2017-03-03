#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Query
{
    int c,x,r;
}q[10000];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        stack<int> st;
        queue<int> que;
        priority_queue<int> pq;
        int f1=0,f2=0,f3=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&q[i].c);
            if(q[i].c==1)scanf("%d",&q[i].x);
            else scanf("%d",&q[i].r);
        }
        for(int i=1;i<=n;i++)
        {
            if(q[i].c==1)st.push(q[i].x);
            if(q[i].c==2)
            {
                int t;
                if(!st.empty())t=st.top(),st.pop();
                else
                {
                    f1=1;break;
                }
                if(t!=q[i].r)
                {
                    f1=1;break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(q[i].c==1)que.push(q[i].x);
            if(q[i].c==2)
            {
                int t;
                if(!que.empty())t=que.front(),que.pop();
                else
                {
                    f2=1;break;
                }
                if(t!=q[i].r)
                {
                    f2=1;break;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(q[i].c==1)pq.push(q[i].x);
            if(q[i].c==2)
            {
                int t;
                if(!pq.empty())t=pq.top(),pq.pop();
                else
                {
                    f3=1;break;
                }
                if(t!=q[i].r)
                {
                    f3=1;break;
                }
            }
        }
        if((!f1)&&f2&&f3)printf("stack\n");
        else if(f1&&(!f2)&&f3)printf("queue\n");
        else if(f1&&f2&&(!f3))printf("priority queue\n");
        else if(f1&&f2&&f3)printf("impossible\n");
        else printf("not sure\n");
    }
    return 0;
}
