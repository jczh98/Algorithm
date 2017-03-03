#include <cstdio>
#include <cstring>
int n,u,v,c[100100],q[100100],cnt[100100];
struct Edge
{
    int u,v;
}e[100100];
int main()
{
    memset(cnt,0,sizeof(cnt));
    memset(q,0,sizeof(q));
    scanf("%d",&n);
    for(int i=1;i<n;i++) scanf("%d%d",&e[i].u,&e[i].v);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    int k=1,f=0;
    for(int i=1;i<n;i++)if(c[e[i].u]!=c[e[i].v]) q[k++]=i;
    for(int i=1;i<k;i++)cnt[e[q[i]].u]++,cnt[e[q[i]].v]++;
    for(int i=1;i<=n;i++)if(cnt[i]==k-1){
        printf("YES\n%d\n",i);f=1;break;
    }
    if(f==0)printf("NO\n");
    return 0;
}
