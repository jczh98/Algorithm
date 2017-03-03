#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
typedef long long LL;

LL ccabs(LL x) {return x>0?x:(-x);}

struct Com
{
    LL val;int id;
    bool operator <(const Com &rhs)const
    {
        return ccabs(val)>ccabs(rhs.val);
    }
};

int sign=1;
LL n,k,x,a[200200];
priority_queue<Com> Q;

int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)sign=-sign;
        Q.push((Com){a[i],i});
    }
    for(int i=1;i<=k;i++)
    {
        Com top=Q.top();Q.pop();
        if(a[top.id]<0)sign=-sign;
        if(sign>0)a[top.id]-=x;
        else a[top.id]+=x;
        if(a[top.id]<0)sign=-sign;
        Q.push((Com){a[top.id],top.id});
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";printf("\n");
    return 0;
}
