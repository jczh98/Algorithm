#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int d,h,vis[100];
LL C[100][100];
vector<LL> vec;
void Dfs(int cur,int last,int sum)
{
    if(sum>=h-1&&cur<d)
    {
        return;
    }
    if(cur>d)
    {
        if(sum==h-1)
        {
            LL t=1;int tsum=sum;
            for(int i=1;i<=d;i++)
            {
                t*=C[tsum][vis[i]];
                tsum-=vis[i];
            }
            vec.push_back(t);
        }
    }else
    {
        for(int i=last;i<=h;i++)
        {
            vis[cur]=i;
            Dfs(cur+1,i,sum+i);
            vis[cur]=0;
        }
    }
    return;
}
int main()
{
    C[1][0]=C[1][1]=1;
    for(int i=2;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=50;j++) C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    scanf("%d%d",&d,&h);
    Dfs(1,0,0);
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0;
}
