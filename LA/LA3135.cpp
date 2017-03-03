#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct CC
{
    int p,num,t;
    bool operator < (const CC& rhs) const
    {
        return t>rhs.t||(t==rhs.t&&num>rhs.num);
    }
};
priority_queue<CC> pq;
int main()
{
    char s[50000];int qnum,per,k;
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='#')break;
        scanf("%d%d",&qnum,&per);
        CC t;t.p=t.t=per;t.num=qnum;
        pq.push(t);
    }
    scanf("%d",&k);
    while(k--)
    {
        CC t=pq.top();pq.pop();
        t.t+=t.p;
        printf("%d\n",t.num);
        pq.push(t);
    }
    return 0;
}
