#include <bits/stdc++.h>
using namespace std;
int n;
long long even=0,odd=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(i%2)odd++;else even++;
    }
    long long ans1=even*odd*(odd-1)/2;
    long long ans2=even*(even-1)*(even-2)/6;
    cout<<ans1+ans2<<endl;
    return 0;
}
