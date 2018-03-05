#include <bits/stdc++.h>
using namespace std;
int mp[100][100],op;
string sop;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);cin>>sop;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }
        
        if(sop=="left")op=0;
        else if(sop=="up")op=1;
        else if(sop=="right")op=2;
        else if(sop=="down")op=3;
        if(op==0)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=2;j<=n;j++)
                {
                    if(mp[i][j]&&!mp[i][j-1])
                    {
                        int k=j-1;
                        while(!mp[i][k]&&k>=1)k--;
                        swap(mp[i][j],mp[i][k+1]);
                    }
                    //if(mp[i][j]==mp[i][j-1])mp[i][j]*=2,mp[i][j-1]=0;
                }
                for(int j=1;j<n;j++)
                {
                    if(mp[i][j]==mp[i][j+1])mp[i][j]*=2,mp[i][j+1]=0;
                }
                for(int j=2;j<=n;j++)
                {
                    if(mp[i][j]&&!mp[i][j-1])
                    {
                        int k=j-1;
                        while(!mp[i][k]&&k>=1)k--;
                        swap(mp[i][j],mp[i][k+1]);
                    }
                }
            }
        }else if(op==1)
        {
            for(int j=1;j<=n;j++)
            {
                for(int i=2;i<=n;i++)
                {
                    if(mp[i][j]&&!mp[i-1][j])
                    {
                        int k=i-1;
                        while(!mp[k][j]&&k>=1)k--;
                        swap(mp[i][j],mp[k+1][j]);
                    }
                }
                for(int i=1;i<n;i++)
                {
                    if(mp[i][j]==mp[i+1][j])mp[i][j]*=2,mp[i+1][j]=0;
                }
                for(int i=2;i<=n;i++)
                {
                    if(mp[i][j]&&!mp[i-1][j])
                    {
                        int k=i-1;
                        while(!mp[k][j]&&k>=1)k--;
                        swap(mp[i][j],mp[k+1][j]);
                    }
                }
            }
        }else if(op==2)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=n-1;j>=1;j--)
                {
                    if(mp[i][j]&&!mp[i][j+1])
                    {
                        int k=j+1;
                        while(!mp[i][k]&&k<=n)k++;
                        swap(mp[i][j],mp[i][k-1]);
                    }
                }
                for(int j=n;j>1;j--)
                {
                    if(mp[i][j]==mp[i][j-1])mp[i][j]*=2,mp[i][j-1]=0;
                }
                for(int j=n-1;j>=1;j--)
                {
                    if(mp[i][j]&&!mp[i][j+1])
                    {
                        int k=j+1;
                        while(!mp[i][k]&&k<=n)k++;
                        swap(mp[i][j],mp[i][k-1]);
                    }
                }
            }
        }else if(op==3)
        {
            for(int j=1;j<=n;j++)
            {
                for(int i=n-1;i>=1;i--)
                {
                    if(mp[i][j]&&!mp[i+1][j])
                    {
                        int k=i+1;
                        while(!mp[k][j]&&k<=n)k++;
                        swap(mp[i][j],mp[k-1][j]);
                    }
                }
                for(int i=n;i>1;i--)
                {
                    if(mp[i][j]==mp[i-1][j])mp[i][j]*=2,mp[i-1][j]=0;
                }
                for(int i=n-1;i>=1;i--)
                {
                    if(mp[i][j]&&!mp[i+1][j])
                    {
                        int k=i+1;
                        while(!mp[k][j]&&k<=n)k++;
                        swap(mp[i][j],mp[k-1][j]);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<n;j++)
            {
                printf("%d ",mp[i][j]);
            }printf("%d\n",mp[i][n]);
        }    
    }
    
    return 0;
}