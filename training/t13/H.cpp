#include <bits/stdc++.h>
using namespace std;
int n,section[50000],arrange[3000][3000],height[50000]={0};
string time_s[50000],t,words[50][500][50],lines;
vector<string> course[50000];
stringstream ss;
int main()
{
    //freopen("out.txt","w",stdout);
    //for(int i=1;i<100;i++)for(int j=1;j<100;j++)words[i][j]="";
    scanf("%d",&n);
    getline(cin,t);
    for(int i=1;i<=n;i++)
    {
        getline(cin,lines);
        ss.clear();
        ss.str(lines);
        while(ss>>lines)
        {
            course[i].push_back(lines);
        }
        cin>>time_s[i]>>section[i];
        getline(cin,t);
        if(time_s[i]=="Tuesday")
        {
            arrange[section[i]][1]=i;
        }else if(time_s[i]=="Thursday")
        {
            arrange[section[i]][2]=i;
        }else if(time_s[i]=="Saturday")
        {
            arrange[section[i]][3]=i;
        }
    }
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=3;j++)
        {
            int cur=arrange[i][j];
            if(cur==0)
            {
                continue;
            }
            int len=course[cur].size();
            int max_height=1;
            words[i][max_height][j]="";
            for(int k=0;k<len;k++)
            {
                if(words[i][max_height][j].size()+course[cur][k].size()>10)
                {
                    max_height++;
                    words[i][max_height][j]+=course[cur][k];
                    if(words[i][max_height][j].size()!=10)words[i][max_height][j]+=" ";
                }else
                {
                    words[i][max_height][j]+=course[cur][k];
                    if(words[i][max_height][j].size()!=10)words[i][max_height][j]+=" ";
                }
            }
            height[i]=max(height[i],max_height);
        }
    }
    printf("+----------+----------+----------+\n");
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=max(height[i],1);j++)
        {
            for(int k=1;k<=3;k++)
            {
                int len=words[i][j][k].size();
                printf("%c%-10s",124,words[i][j][k].c_str());
            }printf("%c\n",124);
        }
        printf("+----------+----------+----------+");
        if(i!=4)cout<<endl;
    }
    return 0;
}
