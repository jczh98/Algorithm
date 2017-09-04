#include <bits/stdc++.h>
using namespace std;
const int MN=100100;
set<int> st;
int n,k,d[MN],maxk=0;
double ans=0;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&d[i]),st.insert(d[i]);
    maxk=st.size();
    for(int i=2;i<=n;i++)
    {
        if(d[i]!=d[i-1])ans+=(double)(k-1)/(double)(k);
    }
    printf("%.9f",ans);
    return 0;
}
