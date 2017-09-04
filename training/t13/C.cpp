#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
struct Query
{
    int l,r,id,answer,block;
}query[MAXN];
int n,k,Stack[MAXN],a[MAXN],pre[MAXN],stack_top=1,block,pos[MAXN],cnt=1,ans=0,num[MAXN]={0};
bool cmp(Query a,Query b)
{
    if(a.block==b.block) return a.r<b.r;
    else return a.block<b.block;
}
bool cmp_id(Query a,Query b)
{
    return a.id<b.id;
}
inline void Update(int x,int d)
{
    if(d==1){if(!num[a[x]])ans++;num[a[x]]++;}
    else {num[a[x]]--;if(!num[a[x]])ans--;}
}
int main()
{
    scanf("%d%d",&n,&k);
    block=ceil(sqrt(n*1.0));
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
        if(!pre[a[i]])
        {
            Stack[stack_top++]=a[i];
        }else
        {
            query[cnt].l=pre[a[i]]+1;
            query[cnt].r=i-1;
            query[cnt].id=pre[a[i]];
            cnt++;
        }
        pre[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(pre[i])
        {
            query[cnt].l=pre[i]+1;
            query[cnt].r=k;
            query[cnt].id=pre[i];
            cnt++;
        }
    }
    for(int i=1;i<=k;i++)
    {
        query[i].block=query[i].l/block;
    }
    for(int i=1;i<=n;i++)
    {
        if(!pre[i])
        {
            Stack[stack_top++]=i;
        }
    }
    for(int i=1;i<stack_top-1;i++)
    {
        printf("%d ",Stack[i]);
    }printf("%d\n",Stack[stack_top-1]);
    sort(query+1,query+k+1,cmp);

    /*cout<<cnt<<endl;
    for(int i=1;i<=k;i++)
    {
        cout<<query[i].l<<" "<<query[i].r<<endl;
    }
    cout<<endl;*/

    int l=query[1].l,r=query[1].r;
    for(int i=l;i<=r;i++)Update(i,1);
    query[1].answer=ans;
    for(int i=2;i<=k;i++)
    {
        while(r<query[i].r)Update(++r,1);
        while(r>query[i].r)Update(r--,-1);
        while(l<query[i].l)Update(l++,-1);
        while(l>query[i].l)Update(--l,1);
        query[i].answer=ans;
    }
    sort(query+1,query+k+1,cmp_id);
    for(int i=1;i<=k;i++)
    {
        printf("%d\n",query[i].answer);
    }
    return 0;
}
