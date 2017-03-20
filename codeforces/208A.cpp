#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s,ans;
int main()
{
    cin>>s;
    int t;
    while((t=s.find("WUB"))!=string::npos)
    {
        s.replace(t,3,"1");
    }
    int f=0,ff=0,cnt=0;
    ans="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1'&&ff==0)
        {
            if(f==1)ans+=" ";
            ff=1;
        }
        if(s[i]!='1')
        {
            f=1;ff=0;
            ans+=s[i];
        }
    }
    for(int i=0;i<ans.length();i++)cout<<ans[i];
    cout<<endl;
    return 0;
}
