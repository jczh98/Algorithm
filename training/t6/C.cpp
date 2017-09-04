#include <bits/stdc++.h>
#define MN 1010
using namespace std;
string str[MN],t,words[MN][MN];
int len[MN][MN],cnt=1,cnt_word[MN],p[MN];
int main()
{
    memset(len,0,sizeof(p));
    freopen("alignment.in","r",stdin);
    freopen("alignment.out","w",stdout);
    while(getline(cin,str[cnt]))
    {
        stringstream ss(str[cnt]);
        //cout<<str[cnt]<<endl;
        int word=1;
        while(ss>>t)
        {
            len[cnt][word]=t.size();
            words[cnt][word]=t;
            word++;
        }
        cnt_word[cnt]=word;
        cnt++;
    }
    /*for(int i=1;i<cnt;i++)
    {
        for(int j=1;j<cnt_word[i];j++)
        {
            cout<<words[i][j]<<endl;
        }
    }*/
    memset(p,0,sizeof(p));
    for(int i=1;i<cnt;i++)
    {
        for(int j=1;j<cnt_word[i];j++)
        {
            p[j]=max(p[j],len[i][j]);
        }
    }
    /*for(int i=1;i<10;i++)
    {
        cout<<p[i]<<endl;
    }*/
    for(int i=1;i<cnt;i++)
    {
        for(int j=1;j<cnt_word[i];j++)
        {
            cout<<words[i][j];
            if(j!=cnt_word[i]-1)for(int k=1;k<=p[j]+1-len[i][j];k++)
            {
                cout<<(char)32;
            }
        }
        cout<<endl;
    }
    return 0;
}
