#include <bits/stdc++.h>
using namespace std;
int mp[100][100],op;
int main()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            scanf("%d",&mp[i][j]);
        }
    }
    scanf("%d",&op);
    if(op==0)
    {
        for(int i=1;i<=4;i++)
        {
            for(int j=2;j<=4;j++)
            {
                if(mp[i][j]&&!mp[i][j-1])
                {
                    int k=j-1;
                    while(!mp[i][k]&&k>=1)k--;
                    swap(mp[i][j],mp[i][k+1]);
                }
                //if(mp[i][j]==mp[i][j-1])mp[i][j]*=2,mp[i][j-1]=0;
            }
            for(int j=1;j<4;j++)
            {
                if(mp[i][j]==mp[i][j+1])mp[i][j]*=2,mp[i][j+1]=0;
            }
            for(int j=2;j<=4;j++)
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
        for(int j=1;j<=4;j++)
        {
            for(int i=2;i<=4;i++)
            {
                if(mp[i][j]&&!mp[i-1][j])
                {
                    int k=i-1;
                    while(!mp[k][j]&&k>=1)k--;
                    swap(mp[i][j],mp[k+1][j]);
                }
            }
            for(int i=1;i<4;i++)
            {
                if(mp[i][j]==mp[i+1][j])mp[i][j]*=2,mp[i+1][j]=0;
            }
            for(int i=2;i<=4;i++)
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
        for(int i=1;i<=4;i++)
        {
            for(int j=3;j>=1;j--)
            {
                if(mp[i][j]&&!mp[i][j+1])
                {
                    int k=j+1;
                    while(!mp[i][k]&&k<=4)k++;
                    swap(mp[i][j],mp[i][k-1]);
                }
            }
            for(int j=4;j>1;j--)
            {
                if(mp[i][j]==mp[i][j-1])mp[i][j]*=2,mp[i][j-1]=0;
            }
            for(int j=3;j>=1;j--)
            {
                if(mp[i][j]&&!mp[i][j+1])
                {
                    int k=j+1;
                    while(!mp[i][k]&&k<=4)k++;
                    swap(mp[i][j],mp[i][k-1]);
                }
            }
        }
    }else if(op==3)
    {
        for(int j=1;j<=4;j++)
        {
            for(int i=3;i>=1;i--)
            {
                if(mp[i][j]&&!mp[i+1][j])
                {
                    int k=i+1;
                    while(!mp[k][j]&&k<=4)k++;
                    swap(mp[i][j],mp[k-1][j]);
                }
            }
            for(int i=4;i>1;i--)
            {
                if(mp[i][j]==mp[i-1][j])mp[i][j]*=2,mp[i-1][j]=0;
            }
            for(int i=3;i>=1;i--)
            {
                if(mp[i][j]&&!mp[i+1][j])
                {
                    int k=i+1;
                    while(!mp[k][j]&&k<=4)k++;
                    swap(mp[i][j],mp[k-1][j]);
                }
            }
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<4;j++)
        {
            printf("%d ",mp[i][j]);
        }printf("%d\n",mp[i][4]);
    }
    return 0;
}
