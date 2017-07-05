#include <bits/stdc++.h>
using namespace std;
set<string> st;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        st.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            st.insert(str);
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
