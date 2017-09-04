#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n,ans=0,a[10001000],last;
set<int> st;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    last=-inf;
    for(int i=1;i<=n;i++)
    {
        st.erase(st.upper_bound(a[i]),st.end());
        if(a[i]>last)
        {
            st.insert(a[i]);
            last=a[i];
        }
    }
    printf("%d\n",st.size());
    return 0;
}
