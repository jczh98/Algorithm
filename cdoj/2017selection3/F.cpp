#include <bits/stdc++.h>
using namespace std;
char mat[100][100];
int num,ss[100],ind=0,ans=0;
string d[10][5]={
"***",
"* *",
"* *",
"* *",
"***",

"  *",
"  *",
"  *",
"  *",
"  *",

"***",
"  *",
"***",
"*  ",
"***",

"***",
"  *",
"***",
"  *",
"***",

"* *",
"* *",
"***",
"  *",
"  *",

"***",
"*  ",
"***",
"  *",
"***",

"***",
"*  ",
"***",
"* *",
"***",

"***",
"  *",
"  *",
"  *",
"  *",

"***",
"* *",
"***",
"* *",
"***",

"***",
"* *",
"***",
"  *",
"***"
};
int main()
{
    for(int i=0;i<5;i++)fgets(mat[i],100,stdin);
    //for(int i=0;i<5;i++)printf("%s",mat[i]);
    num=strlen(mat[0])/4;int flag=0;
    for(int i=num;i>=1;i--)
    {
        int f_cnt=0;
        for(int x=0;x<10;x++)
        {
            for(int y=0;y<5;y++)
            {
                for(int z=0;z<3;z++)
                {
                    if((d[x][y][z]==' '&&mat[y][ind+z]=='*')||(d[x][y][z]=='*'&&mat[y][ind+z]!='*'))
                    {
                        //if(ind==24)cout<<y<<" "<<z<<d[x][y][z]<<" "<<mat[y][ind+z]<<endl;
                        f_cnt++;goto out;
                    }
                }
            }
            out:;
        }
        /*for(int x=0;x<10;x++)
        {
            for(int y=0;y<5;y++)
            {
                for(int z=0;z<3;z++)
                {
                    cout<<d[x][y][z];
                }
                cout<<endl;
            }
        }*/
        //cout<<ind<<" "<<f_cnt<<endl;
        if(f_cnt==10){flag=1;break;}
        int cnt=0;
        for(int j=0;j<5;j++)
        {
            for(int k=ind;k<ind+3;k++)
            {
                if(mat[j][k]=='*')cnt++;
            }
        }
        if(cnt==12)
        {
            if(mat[1][ind+2]!='*')ss[i]=6;
            else if(mat[2][ind+1]=='*')ss[i]=9;else ss[i]=0;
        }else if(cnt==11)
        {
            if(mat[1][ind+2]!='*')ss[i]=5;
            else if(mat[3][ind+2]=='*')ss[i]=3;else ss[i]=2;
        }else if(cnt==5) ss[i]=1;
        else if(cnt==9)ss[i]=4;
        else if(cnt==11)ss[i]=5;
        else if(cnt==7)ss[i]=7;
        else if(cnt==13)ss[i]=8;
        ind+=4;
    }
    if(flag)
    {
        printf("BOOM!!\n");return 0;
    }
    int mul=1;
    for(int i=1;i<=num;i++)ans+=ss[i]*mul,mul*=10;
    //printf("%d\n",ans);
    if(ans%6==0)printf("BEER!!\n");else printf("BOOM!!\n");
    return 0;
}
