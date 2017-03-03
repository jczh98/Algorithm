#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
int a1[6]={1,2,2,1,0,0},a2[6]={0,0,1,2,2,1},a3[6]={2,1,0,0,1,2};
LL n,x;
int main()
{
    cin>>n>>x;
    if(n%6==0)
    {
        if(x==1)printf("1\n");
        if(x==0)printf("0\n");
        if(x==2)printf("2\n");
        return 0;
    }
    if(a1[n%6-1]==x)
    {
        cout<<"0"<<endl;
        return 0;
    }else if(a2[n%6-1]==x)
    {
        cout<<"1"<<endl;
        return 0;
    }else if(a3[n%6-1]==x)
    {
        cout<<"2"<<endl;
        return 0;
    }
}
