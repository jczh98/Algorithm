#include <bits/stdc++.h>
using namespace std;
int n,flag=0;
vector<vector<int> > pre,cur;
vector<int> single;
int main()
{

    scanf("%d",&n);
    single.push_back(1);
    pre.push_back(single);
    for(int i=2;i<=n;i++)
    {
        cur.clear();
        flag=0;
        for(int j=0;j<pre.size();j++)
        {
            if(flag)
            {
                for(int k=0;k<i;k++)
                {
                    single.clear();
                    for(int l=0;l<k;l++)
                    {
                        single.push_back(pre[j][l]);
                    }
                    single.push_back(i);
                    for(int l=k;l<i-1;l++)
                    {
                        single.push_back(pre[j][l]);
                    }
                    cur.push_back(single);
                }
            }else
            {
                for(int k=i-1;k>=0;k--)
                {
                    single.clear();
                    for(int l=0;l<k;l++)
                    {
                        single.push_back(pre[j][l]);
                    }
                    single.push_back(i);
                    for(int l=k;l<i-1;l++)
                    {
                        single.push_back(pre[j][l]);
                    }
                    cur.push_back(single);
                }
            }
            flag^=1;
        }
        /*for(int i=0;i<pre.size();i++)
        {
            for(int j=0;j<pre[i].size();j++)
            {
                cout<<pre[i][j]<<" ";
            }cout<<endl;
        }*/
        pre=cur;
    }
    for(int i=0;i<pre.size();i++)
    {
        for(int j=0;j<pre[i].size();j++)
        {
            cout<<pre[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
