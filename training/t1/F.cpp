#include <bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(k==(n+1)||(n+1)%k==0)printf("yes\n");
    else printf("no\n");
    return 0;
}
