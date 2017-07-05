#include <bits/stdc++.h>
using namespace std;
int n,vis[1000],l=0,r=0;
char str[1000];
stack<pair<int,char>> st;
int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    scanf("%s",str);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
        {
            st.push(make_pair(i,str[i]));
        }else if(str[i]==')')
        {
            if(!st.empty())
            {
                pair<int,char> top=st.top();st.pop();
                vis[top.first]=1;vis[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(str[i]=='(')r++;
            else l++;
        }
    }
    for(int i=1;i<=l;i++)printf("(");
    for(int i=0;i<n;i++)printf("%c",str[i]);
    for(int i=1;i<=r;i++)printf(")");
    printf("\n");
    return 0;
}
