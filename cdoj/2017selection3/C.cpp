#include <bits/stdc++.h>
#define eps 1e-5
using namespace std;
double X;
int qpow(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res*=a;a*=a;b>>=1;
    }
    return res;
}
int main() {
    cin>>X;
    int flag=0;
    for(int len=0;len<8;len++)
    {
        for (int an=1;an<=9;an++)
        {
            int A=an*(qpow(10,len+1)-1)/(10-X);
            if (A/qpow(10,len)==an&&abs((10-X)*A-an*qpow(10,len+1)+an)<eps)
            {
                cout<<A<<endl;flag=1;
            }
        }
    }
    if(!flag)cout<<"No solution"<<endl;
    return 0;
}
