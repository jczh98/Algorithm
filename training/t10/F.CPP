#include <bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=1000;i++)
    {
        int cnt=(3*i*i+i)/2;
        if(cnt%4==0)
        {
            printf("%d %d\n",i,cnt);
        }
    }
}
