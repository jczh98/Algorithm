#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int c[100100],n,a[100100],cnt[100100],MN;
int Lowbit(int x){return x&(-x);}
struct Node
{
    int a,b;
}node[100100];
int cmp(Node x,Node y)
{
    if(x.b<y.b)
    {
        return 1;
    }else
    {
        if(x.b==y.b)
        {
            if(x.a<y.a)
            {
                return 1;
            }else return 0;
        }else return 0;
    }
}
void Add(int k,int num)
{
    while(k<=MN)
    {
        c[k]+=num;
        k+=Lowbit(k);
    }
}
int Sum(int k)
{
    int sum=0;
    while(k)
    {
        sum+=c[k];
        k-=Lowbit(k);
    }
    return sum;
}
int main()
{
    memset(c,0,sizeof(c));
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    MN=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&node[i].a,&node[i].b);
        MN=max(MN,node[i].a);
    }
    sort(node+1,node+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        Add(node[i].a,1);
        cnt[Sum(node[i].a)-1]++;
    }
    for(int i=0;i<=n-1;i++)
    {
        printf("%d\n",cnt[i]);
    }
    return 0;
}
