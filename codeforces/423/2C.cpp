#include <bits/stdc++.h>
#define MN 3000100
using namespace std;
int n,k,t,cnt;
struct Node
{
    int pos,id;
    bool operator < (const Node &rhs) const
    {
        return pos<rhs.pos;
    }
}nodes[MN];
string str[100100];
char ans[MN];
int main()
{
    scanf("%d",&n);
    cnt=1;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            scanf("%d",&t);
            nodes[cnt].pos=t;
            nodes[cnt].id=i;
            cnt++;
        }
    }
    sort(nodes+1,nodes+cnt);
    int now=1;
    for(int i=1;i<cnt;i++)
    {
        while(now<nodes[i].pos)
        {
            ans[now-1]='a';
            now++;
        }
        for(int j=now-nodes[i].pos;j<str[nodes[i].id].size();j++)
        {
            ans[now-1]=str[nodes[i].id][j];
            now++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
