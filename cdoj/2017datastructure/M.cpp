#include <bits/stdc++.h>
using namespace std;
set<int> sets;
set<int>::iterator it;
int n,t,p,x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&x),sets.insert(x);
    while(1)
    {
        it=sets.end();it--;p=t=x=(*it);
        t/=2;
        while(t)
        {
            if(sets.find(t)==sets.end()){p=t;break;}
            t/=2;
        }
        if(p==x)break;
        sets.erase(it);
        sets.insert(p);
    }
    printf("%d\n",*(--sets.end()));
    return 0;
}
