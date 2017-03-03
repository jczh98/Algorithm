#include <cstdio>
#include <cstring>
#include <cctype>
#include <climits>
#include <algorithm>
#include <sstream>
#include <string>
#include <iostream>
#define MN 10000
using namespace std;
string s;
int a[MN],n;
void Reverse(int x)
{
    for(int i=0;i<x-i;i++)swap(a[i],a[x-i]);
    printf("%d ",n-x);
}
int main()
{
    while(getline(cin,s))
    {
        cout<<s<<endl;
        stringstream ss(s);
        n=0;
        while(ss>>a[n])n++;
        for(int i=n-1;i>0;i--)
        {
            int p=max_element(a,a+i+1)-a;
            if(p==i)continue;
            if(p>0)Reverse(p);
            Reverse(i);
        }
        printf("0\n");
    }
    return 0;
}
