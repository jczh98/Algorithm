#include <bits/stdc++.h>
using namespace std;
char mp[9][9]=
{
"********",
"***  ***",
"***  ***",
"***  ***",
"* **** *",
"* *  * *",
"* *  * *",
"********"
};
char zombies[20][1200][1200];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(zombies,0,sizeof(zombies));
        if(n<8)break;
        int k=log2(n)-2;
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                zombies[1][i][j]=mp[i][j];
            }
        }
        for(int i=2;i<=k;i++)
        {
            int num=pow(2,i+2);
            for(int j=0;j<num;j++)
            {
                zombies[i][j][0]='*',zombies[i][j][num-1]='*',zombies[i][0][j]='*',zombies[i][num-1][j]='*';
            }
            int y=num/2-(pow(2,i-1)-1)*2-1;
            for(int j=pow(2,i-1);j<=pow(2,i-1)+y-1;j++)
            {
                int t=num/4;
                zombies[i][j][(int)pow(2,i-1)]='*';
                zombies[i][j][(int)pow(2,i-1)+t-1]='*';
                zombies[i][j][(int)pow(2,i-1)+2*t]='*';
                zombies[i][j][(int)pow(2,i-1)+3*t-1]='*';
                /*for(int k=pow(2,i-1);k<=pow(2,i-1)+num/4;k++)
                {
                    zombies[i][j][k]='*';
                }*/
            }
            int t=pow(2,i-1);
            for(int j=0;j<num/4;j++)zombies[i][t][t+j]='*',zombies[i][t][t+num/2+j]='*';
            for(int j=0;j<num/4;j++)zombies[i][t+y-1][t+j]='*',zombies[i][t+y-1][t+num/2+j]='*';
            for(int j=num/2;j<num;j++)
            {
                for(int k=num/4;k<num/4+num/2;k++)
                {
                    zombies[i][j][k]=zombies[i-1][num-j-1][k-num/4];
                    //cout<<j-num/2<<" "<<k-num/4<<endl;
                    //zombies[i][j][k]='*';
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(zombies[k][i][j]!='*')zombies[k][i][j]=' ';
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<zombies[k][i][j];
            }cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
