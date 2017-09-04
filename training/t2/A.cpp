#include <bits/stdc++.h>
using namespace std;
const int MN=100;
int t,n,a[MN],b[MN],maxnum,minnum,sign,maxpos,minpos;
set<int> st;
set<int>::iterator it;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);st.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);sign=a[i];st.insert(a[i]);
        }
        while(true)
        {
            maxnum=-1e9,minnum=1e9;
            for(int i=1;i<=n;i++)
            {
                if(maxnum<a[i])
                {
                    maxnum=a[i];maxpos=i;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(minnum>a[i]&&i!=maxpos)
                {
                    minnum=a[i];minpos=i;
                }
            }
            a[minpos]=maxnum-minnum;a[maxpos]=maxnum-minnum;
            //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
            int flag=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[i]!=a[j])
                    {
                        flag=1;break;
                    }
                }
            }
            if(flag==0)break;
        }
        printf("%d\n",a[1]);
    }
    return 0;
}
