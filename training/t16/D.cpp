#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
char str[1100000];
LL query,M=0,L=0,len;
stack<LL> st1,st2;
stack<char> op1,op2;
int main()
{
    char *ss="1+12*3+4";
    cin>>str>>query;
    len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='+'||str[i]=='*')
        {
            op1.push(str[i]);
        }else
        {
            LL num=0;
            while(isdigit(str[i]))
            {
                num+=str[i]-'0';i++;
            }i--;
            if(!op1.empty())
            {
                char op=op1.top();
                if(op=='*')
                {
                    int t=st1.top();st1.pop();
                    st1.push(t*num);
                    op1.pop();
                }else st1.push(num);
            }else st1.push(num);
        }
    }
    while(!st1.empty())
    {
        LL t=st1.top();st1.pop();
        M+=t;
    }
    for(int i=0;i<len;i++)
    {
        if(isdigit(str[i]))
        {
            LL num=0;
            while(isdigit(str[i]))
            {
                num+=str[i]-'0';i++;
            }i--;
            if(!op2.empty())
            {
                char op=op2.top();op2.pop();
                LL t=st2.top();st2.pop();
                if(op=='+')
                {
                    st2.push(num+t);
                }else if(op=='*')
                {
                    st2.push(num*t);
                }
            }else st2.push(num);
        }else if(str[i]=='+'||str[i]=='*')
        {
            op2.push(str[i]);
        }
    }
    L=st2.top();
    //cout<<L<<" "<<M<<endl;
    if(M==query&&L!=query)
    {
        printf("M\n");
    }else if(M!=query&&L==query)
    {
        printf("L\n");
    }else if(M==query&&L==query)
    {
        printf("U\n");
    }else if(M!=query&&L!=query)
    {
        printf("I\n");
    }
    return 0;
}
