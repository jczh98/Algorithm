#include <bits/stdc++.h>
using namespace std;
int table[20][20],e[15][15][15][15],number,flag,ans=0;
int main()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            scanf("%d",&table[i][j]);
        }
    }
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                for(int l=0;l<10;l++)
                {
                    e[i][j][k][l]=table[table[table[table[0][i]][j]][k]][l];
                }
            }
        }
    }
    //cout<<e[9][9][9][2]<<endl;
    for(int a=0;a<10;a++)
    {
        for(int b=0;b<10;b++)
        {
            for(int c=0;c<10;c++)
            {
                for(int d=0;d<10;d++)
                {
                    number=e[a][b][c][d];flag=0;
                    if(!flag)for(int k=0;k<10;k++)if(k!=a)
                    {
                        if(table[e[k][b][c][d]][number]==0)
                        {
                            if(a==9&&b==9&&c==9&&d==9)
                            {
                                //cout<<k<<endl;
                            }
                            ans++;flag=1;break;
                        }
                    }
                    if(!flag)for(int k=0;k<10;k++)if(k!=b)
                    {
                        if(table[e[a][k][c][d]][number]==0)
                        {

                            if(a==9&&b==9&&c==9&&d==9)
                            {
                                //cout<<k<<endl;
                            }
                            //cout<<a<<b<<c<<d<<endl;
                            ans++;flag=1;break;
                        }
                    }
                    if(!flag)for(int k=0;k<10;k++)if(k!=c)
                    {
                        if(table[e[a][b][k][d]][number]==0)
                        {
                            if(a==9&&b==9&&c==9&&d==9)
                            {
                                //cout<<k<<endl;
                            }
                            //cout<<a<<b<<c<<d<<endl;
                            ans++;flag=1;break;
                        }
                    }
                    if(!flag)for(int k=0;k<10;k++)if(k!=d)
                    {
                        if(table[e[a][b][c][k]][number]==0)
                        {
                            if(a==9&&b==9&&c==9&&d==9)
                            {
                                //cout<<k<<endl;
                            }
                            //cout<<a<<b<<c<<d<<endl;
                            ans++;flag=1;break;
                        }
                    }
                    if(!flag)for(int k=0;k<10;k++)if(k!=number)
                    {
                        if(table[e[a][b][c][d]][k]==0)
                        {
                            if(a==9&&b==9&&c==9&&d==9)
                            {
                                //cout<<k<<endl;
                            }
                            //cout<<a<<b<<c<<d<<endl;
                            ans++;flag=1;break;
                        }
                    }
                    if(flag)continue;
                    if(a!=b)
                    {
                        if(table[e[b][a][c][d]][number]==0)
                        {
                            ans++;continue;
                        }
                    }
                    if(b!=c)
                    {
                        if(table[e[a][c][b][d]][number]==0)
                        {
                            ans++;continue;
                        }
                    }
                    if(c!=d)
                    {
                        if(table[e[a][b][d][c]][number]==0)
                        {
                            ans++;continue;
                        }
                    }
                    if(d!=number)
                    {
                        if(table[e[a][b][c][number]][d]==0)
                        {
                            ans++;continue;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
