#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,t;
char s[100000];
int main()
{
    scanf("%d%d",&n,&t);
    scanf("%s",s);
    for(int i=1;i<=t;i++)
        for(int j=0;j<n;)
        {
            if(s[j]=='B'&&s[j+1]=='G')swap(s[j],s[j+1]),j+=2;
            else j++;
        }
    printf("%s",s);
    return 0;
}
