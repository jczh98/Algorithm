#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
typedef long long LL;

int k,cnt;
pair<int,int> ans[100000];

int main()
{
    while(scanf("%d",&k)!=EOF)
    {
        cnt=0;
        for(int y=1;y<=2*k;y++)
        {
            if(y-k==0)continue;
            int x=k*y/(y-k);
            if(x<y||x<=0)continue;
            if(k*y%(y-k)!=0)continue;
            ans[++cnt]=make_pair(k*y/(y-k),y);
        }
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("1/%d = 1/%d + 1/%d\n",k,ans[i].first,ans[i].second);
    }
    return 0;
}
