#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int Judge(int x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return true;
    }
    return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=4;i<=n/2;i++)
    {
        if(Judge(i)&&Judge(n-i))
        {
            printf("%d %d\n",i,n-i);
            break;
        }
    }
    return 0;
}
