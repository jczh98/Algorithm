#include <bits/stdc++.h>
using namespace std;
int n,k,mini_broken,max_safe;
char str[1000];
vector<int> safe,broken;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%s",&x,&str);
        if(str[0]=='S')safe.push_back(x);
        if(str[0]=='B')broken.push_back(x);
    }
    safe.push_back(1);broken.push_back(k);
    sort(safe.begin(),safe.end());
    sort(broken.begin(),broken.end());
    max_safe=*broken.begin()-1;
    mini_broken=*(safe.end()-1)+1;
    printf("%d %d\n",mini_broken,max_safe);
    return 0;
}
