#include <bits/stdc++.h>
using namespace std;
int n,m;
int A[5][6]=
{
 1 , 2 , 2 , 3 , 4 , 4,
 1  ,5,  5 , 3 , 6 , 7,
 8  ,9 ,10 ,10 , 6  ,7,
 8  ,9 ,11, 12, 12 ,13,
14 ,14 ,11 ,15 ,15 ,13
};
int B[6][8]=
{
1,2,2,4,5,5,7,7,
1,3,3,4,6,6,8,9,
10,10,11,12,12,13,8,9,
14,15,11,16,16,13,17,17,
14,15,18,18,19,20,20,21,
22,22,23,23,19,24,24,21
};
int f[1000][1000],b[1000][1000];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(f,0,sizeof(f));
        if(n==1&&m==2)
        {
            printf("1 1\n");
        }else if(((n*m)&1)||(n<=4||m<=4)||(m==6&&n==6))
        {
            printf("No\n");
        }else
        {
            if((n&1)&&!(m&1))
            {
                int k=16;
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=6;j++)
                    {
                        f[i][j]=A[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][5]==f[i][6])
                    {
                        swap(f[i][5],f[i][m-1]);swap(f[i][6],f[i][m]);
                    }else
                    {
                        swap(f[i][6],f[i][m]);
                    }
                }
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[4][j]==f[5][j])
                    {
                        swap(f[4][j],f[n-1][j]);swap(f[5][j],f[n][j]);
                    }else
                    {
                        swap(f[5][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }

                    }
                }
            }else if(!(n&1)&&!(m&1))
            {
                int k=25;
                for(int i=1;i<=6;i++)
                {
                    for(int j=1;j<=8;j++)
                    {
                        f[i][j]=B[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][7]==f[i][8])
                    {
                        swap(f[i][7],f[i][m-1]);swap(f[i][8],f[i][m]);
                    }else
                    {
                        swap(f[i][8],f[i][m]);
                    }
                }
                for(int i=1;i<=6;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[5][j]==f[6][j])
                    {
                        swap(f[5][j],f[n-1][j]);swap(f[6][j],f[n][j]);
                    }else
                    {
                        swap(f[6][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }
                    }
                }
            }else if(!(n&1)&&(m&1))
            {
                swap(n,m);
                int k=16;
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=6;j++)
                    {
                        f[i][j]=A[i-1][j-1];
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(f[i][5]==f[i][6])
                    {
                        swap(f[i][5],f[i][m-1]);swap(f[i][6],f[i][m]);
                    }else
                    {
                        swap(f[i][6],f[i][m]);
                    }
                }
                for(int i=1;i<=5;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i][j+1]&&f[i][j]==0)
                        {
                            f[i][j]=f[i][j+1]=k;k++;
                        }
                    }
                }
                for(int j=1;j<=m;j++)
                {
                    if(f[4][j]==f[5][j])
                    {
                        swap(f[4][j],f[n-1][j]);swap(f[5][j],f[n][j]);
                    }else
                    {
                        swap(f[5][j],f[n][j]);
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(f[i][j]==f[i+1][j]&&f[i][j]==0)
                        {
                            f[i][j]=f[i+1][j]=k;k++;
                        }

                    }
                }
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        b[j][i]=f[i][j];
                    }
                }
                swap(n,m);
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        f[i][j]=b[i][j];
                    }
                }
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    printf("%d ",f[i][j]);
                }printf("\n");
            }
            printf("\n");
            /*int a[101],b[101];
            for (int i=1;i<=n;++i) a[i]=0;
            for (int j=1;j<=m;++j) b[j]=0;
            for (int i=1;i<=n;++i)
                for (int j=1;j<=m;++j) {
                    if (j!=m&&f[i][j]==f[i][j+1]) b[j]=1;
                    if (i!=n&&f[i][j]==f[i+1][j]) a[i]=1;
                }
            int flag=0;
            for (int i=1;i<n;++i) if(!a[i])flag=1;
            for (int j=1;j<m;++j) if(!b[j])flag=1;
            if(flag)printf("wa\n");*/
        }
    }
    return 0;
}
