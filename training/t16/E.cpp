#include <bits/stdc++.h>
using namespace std;
int t,x,vis[100000],cnt[100000];
vector<int> a,ans,final_ans;
int main()
{
    for(int i=3;i<=65535;i++)
    {
        if(i&1)ans.push_back(i);
    }
    int len=ans.size(),p=2;
    while(ans[0]*p<=65535)
    {
        for(int i=0;i<len;i++)
        {
            if(ans[i]*p>65535)break;
            ans.push_back(ans[i]*p);
        }
        p*=2;
    }
    a.push_back(1);
    for(int i=2;i<=65535;i*=2)
    {
        a.push_back(i);
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<a.size();i++)ans.push_back(a[i]);
    /*for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }*/
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        a.clear();final_ans.clear();
        while(scanf("%d",&x)!=EOF)
        {
            if(x==0)break;
            a.push_back(x);
            vis[x]=1;
            cnt[x]++;
        }
        for(int i=0;i<ans.size();i++)
        {
            if(vis[ans[i]])
            {
                for(int j=0;j<cnt[ans[i]];j++)final_ans.push_back(ans[i]);
            }
        }
        for(int i=0;i<final_ans.size()-1;i++)cout<<final_ans[i]<<" ";
        cout<<final_ans[final_ans.size()-1]<<endl;
    }
    return 0;
}
