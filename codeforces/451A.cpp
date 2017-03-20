#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    if(n>m)swap(n,m);
    n%2==1?printf("Akshat\n"):printf("Malvika\n");
    return 0;
}
