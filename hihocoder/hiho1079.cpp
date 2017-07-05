#include <bits/stdc++.h>
#define MN 200010
using namespace std;
int l,pl[MN],pr[MN];
int n,vis[4*MN],ans=0;
vector<int> pos;
map<int,int> mapping;
struct Node
{
    int l,r,lazy;
    void update(int v)
    {
        lazy=v;
    }
}tree[4*MN];
void PushDown(int x)
{
    int lazyv=tree[x].lazy;
    if(lazyv)
    {
        tree[x<<1].lazy=tree[x<<1|1].lazy=lazyv;
        tree[x].lazy=0;
    }
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;
    tree[x].lazy=0;
    if(l!=r)
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
    }
}
void Update(int x,int l,int r,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)tree[x].update(v);
    else
    {
        PushDown(x);
        int mid=(L+R)/2;
        if(l<=mid)Update(x<<1,l,r,v);
        if(r>mid)Update(x<<1|1,l,r,v);
    }
}
void Query(int x,int l,int r)
{
    if(tree[x].lazy)
    {
        vis[tree[x].lazy]=1;
        return;
    }
    if(l==r)return;
    int mid=(l+r)/2;
    Query(x<<1,l,mid);
    Query(x<<1|1,mid+1,r);
}
int main()
{
    //freopen("input.txt","r",stdin);
    memset(vis,0,sizeof(vis));
    cin>>n>>l;
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>pl[i]>>pr[i];
        pos.push_back(pl[i]);
        pos.push_back(pr[i]);
    }
    sort(pos.begin(),pos.end());
    pos.erase(unique(pos.begin(),pos.end()),pos.end());
    for(int i=0;i<pos.size();i++)
    {
        mapping[pos[i]]=i+1;
    }
    Build(1,1,pos.size());
    for(int i=1;i<=n;i++)Update(1,mapping[pl[i]],mapping[pr[i]]-1,i);
    Query(1,1,pos.size());
    for(int i=1;i<=n;i++)if(vis[i])ans++;
    cout<<ans<<endl;
    return 0;
}
