#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
int n,m,a[100],b[100],c[100],ans=INT_MAX;
char s[100][100];
int main()
{
    memset(a,7,sizeof(a));
    memset(b,7,sizeof(b));
    memset(c,7,sizeof(c));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(s[i][j]>='0'&&s[i][j]<='9')a[i]=min(a[i],min(j,m-j));
            if(s[i][j]>='a'&&s[i][j]<='z')b[i]=min(b[i],min(j,m-j));
            if(s[i][j]=='#'||s[i][j]=='*'||s[i][j]=='&')c[i]=min(c[i],min(j,m-j));
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
        {
            if(i==j||j==k||k==i)continue;
            ans=min(ans,a[i]+b[j]+c[k]);
        }
    printf("%d\n",ans);
    return 0;
}
