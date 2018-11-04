#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
//set<int>::iterator set_stater
//typedef pair<int,int> pii;
using namespace std;
typedef long long ll;
int cnt[100010],n,m,p[100010],res[100010];
int r_find(int x)
{
    if(p[x]==x)return x;
    else
    {
        int now=r_find(p[x]);
        p[x]=now;
        return now;
    }
}
typedef struct ques
{
    int l,r,id,od;
};
ques mes[110000];
bool cmp(ques a,ques b)
{
    if(a.id==b.id)
        return a.r<b.r;
    return a.id<b.id;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int f=sqrt(n);
        ff(i,1,n)
        {
            p[i]=i;
            cnt[i]=0;
        }
        ff(i,1,m)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            int rt1=r_find(a),rt2=r_find(b);
            p[rt2]=rt1;
        }
        int q;
        scanf("%d",&q);
        ff(i,1,q)
        {
            scanf("%d%d",&mes[i].l,&mes[i].r);
            mes[i].id=mes[i].l/f;
            mes[i].od=i;
        }
        sort(mes+1,mes+1+q,cmp);
        int l=1,r=0,ans=0;
        ff(i,1,q)
        {
            int ln=mes[i].l,rn=mes[i].r,now;
            while(r<rn)
            {
                r++;
                now=r_find(r);
                cnt[now]++;
                if(cnt[now]==1)
                    ans++;
            }
            while(r>rn)
            {
                now=r_find(r);
                cnt[now]--;
                r--;
                if(cnt[now]==0)
                    ans--;
            }
            while(l<ln)
            {
                now=r_find(l);
                cnt[now]--;
                l++;
                if(cnt[now]==0)
                    ans--;
            }
            while(l>ln)
            {
                l--;
                now=r_find(l);
                cnt[now]++;
                if(cnt[now]==1)
                    ans++;
            }
            res[mes[i].od]=ans;
        }
        ff(i,1,q)
        printf("%d\n",res[i]);
    }
    return 0;
}