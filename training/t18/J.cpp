#include <bits/stdc++.h>
#define S 1
#define M 0
using namespace std;
int t;
char mp[100][100];
string str;
int Dfs(string now,int player)
{
    if(now.size()==1)
    {
        //cout<<now<<" ";cout<<(player==1?"S":"M")<<endl;
        char cur=now[0];
        if(cur=='a'||cur=='e'||cur=='i'||cur=='o'||cur=='u')
        {
            //cout<<"h"<<endl;
            return 1;
        }
        //cout<<"n"<<endl;
        return 0;
    }else if(now.size()>1)
    {
        //cout<<now<<" ";cout<<(player==1?"S":"M")<<endl;
        string l,r;l="";r="";
        int len=now.size();
        //cout<<len<<endl;
        for(int i=0;i<len-1;i+=2)l+=mp[now[i]-'a'][now[i+1]-'a'];
        if(len&1)l+=now[len-1],r+=now[0];
        for(int i=(len&1);i<len;i+=2)r+=mp[now[i]-'a'][now[i+1]-'a'];
        //cout<<l<<" "<<r<<endl;
        int L=Dfs(l,player^1);
        int R=Dfs(r,player^1);
        //cout<<L<<" "<<R<<endl;
        if(player==S)
        {
            if(L||R)return 1;else return 0;
        }else
        {
            if(!L||!R)return 0;else return 1;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<26;i++)scanf("%s",mp[i]);
        cin>>str;
        if(Dfs(str,S))cout<<"Salah"<<endl;else cout<<"Marzo"<<endl;
    }
    return 0;
}
