#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
string s[2];
int n;
int main()
{
    cin>>s[0]>>s[1];
    cout<<s[0]<<" "<<s[1]<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1.compare(s[0])==0)s[0]=s2;
        else s[1]=s2;
        cout<<s[0]<<" "<<s[1]<<endl;
    }
    return 0;
}
