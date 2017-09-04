#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
int n,x;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(n%2)
        {
            if(i%2)dq.push_front(x);
            else dq.push_back(x);
        }else
        {
            if(i%2==0)dq.push_front(x);
            else dq.push_back(x);
        }
    }
    for(int i=0;i<dq.size()-1;i++)printf("%d ",dq[i]);printf("%d\n",dq[dq.size()-1]);
    return 0;
}
