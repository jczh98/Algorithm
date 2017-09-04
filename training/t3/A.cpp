#include <bits/stdc++.h>
using namespace std;
char str[11000];
stack<int> bracket;
int vis[11000],op[11000];
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        memset(op,0,sizeof(op));
        while(!bracket.empty())
        {
            bracket.pop();
        }
        int len=strlen(str);
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]=='(')
            {
                bracket.push(i);
                op[i]=0;
            }else if(str[i]=='+')
            {
                vis[i]=1;
                if(!bracket.empty())
                {
                    int top=bracket.top();
                    op[top]=1;
                }
            }
            else if(str[i]==')')
            {
                int top=bracket.top();bracket.pop();
                if(op[top])
                {
                    if(top-1>=0&&i<len-1)
                    {
                        if((str[top-1]!='+'&&str[top-1]!='(')||(str[i+1]!='+'&&str[i+1]!=')'))
                        {
                            vis[top]=vis[i]=1;
                        }
                        if(str[top-1]=='('&&str[i+1]==')') op[top-1]=1;
                    }
                    else if(top==0&&i<len-1)
                    {
                        if(str[i+1]!='+'&&str[i+1]!=')')vis[i]=vis[top]=1;
                    }else if(top-1>=0&&len-1==i)
                    {
                        if(str[top-1]!='+'&&str[top-1]!='(')vis[i]=vis[top]=1;
                    }
                }
            }else vis[i]=1;
        }
        for(int i=0;i<len;i++)
        {
            if(!vis[i])continue;
            cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
