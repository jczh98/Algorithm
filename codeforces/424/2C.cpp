#include <bits/stdc++.h>
using namespace std;
int k,n,a[10000],b[10000],sum[10000]={0};
vector<int> finder;
set<int> ans;
int main()
{
    scanf("%d%d",&k,&n);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i],finder.push_back(sum[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    sort(finder.begin(),finder.end());
    sort(sum+1,sum+1+n);
    sort(b+1,b+1+n);
    /*for(int i=0;i<finder.size();i++)
    {
        cout<<finder[i]<<" ";
    }cout<<endl;
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    cout<<endl;*/
    for(int i=1;i<=k;i++)
    {
        int st=b[1]-sum[i],flag=0;
        //cout<<st<<" "<<b[1]<<" "<<sum[i]<<endl;
        for(int j=2;j<=n;j++)
        {
            if(find(finder.begin(),finder.end(),b[j]-st)==finder.end()){flag=1;break;}
        }
        if(!flag)ans.insert(st);
    }
    printf("%d\n",ans.size());
    return 0;
}
