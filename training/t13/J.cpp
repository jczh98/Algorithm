#include <bits/stdc++.h>
using namespace std;
char table[100100];
int k,even=0,odd=0,vis[100],len;
queue<int> even_que,odd_que;
deque<int> dq;
int main()
{
    scanf("%s%d",table+1,&k);len=strlen(table+1);
    for(int i=1;i<=len;i++)
    {
        if(isalpha(table[i]))
        {
            if(!vis[table[i]-'a'])k--;
            vis[table[i]-'a']=1;
        }else
        {
            if(i&1)odd++,odd_que.push(i);else even++,even_que.push(i);
        }
    }
    for(int i=0;i<=25;i++)if(!vis[i])dq.push_back(i);
    if(even+odd<k)
    {
        printf("-1\n");
        return 0;
    }
    int cnt=0;
    while(cnt<k)
    {
        if(26-dq.front()>dq.back())
        {
            if(!even_que.empty())
            {
                table[even_que.front()]=dq.front()+'a';
                even_que.pop();dq.pop_front();cnt++;
            }else
            {
                table[odd_que.front()]=dq.back()+'a';
                odd_que.pop();dq.pop_back();cnt++;
            }
        }else
        {
            if(!odd_que.empty())
            {
                table[odd_que.front()]=dq.back()+'a';
                odd_que.pop();dq.pop_back();cnt++;
            }else
            {
                table[even_que.front()]=dq.front()+'a';
                even_que.pop();dq.pop_front();cnt++;
            }
        }
    }
    for(int i=1;i<=len;i++)
    {
        if(table[i]=='?')
        {
            if(i&1)table[i]='z';else table[i]='a';
        }
    }
    printf("%s\n",table+1);
    return 0;
}
