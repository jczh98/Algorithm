#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
map<int,vector<int> > mp;
int n,m,a[1000100],v,k;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        mp.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mp[a[i]].push_back(i);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&k,&v);
            if(!mp.count(v)||mp[v].size()<k)
            {
                printf("0\n");continue;
            }
            printf("%d\n",mp[v][k-1]);
        }
    }
    return 0;
}
