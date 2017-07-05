#include <bits/stdc++.h>
using namespace std;
int a,b,x;
int main()
{
    scanf("%d%d",&a,&b);x=1;
    while(true)
    {
        if(x%2)
        {
            if(a-x<0)
            {
                printf("Vladik\n");break;
            }
        }else
        {
            if(b-x<0)
            {
                printf("Valera\n");break;
            }
        }
        if(x%2)a-=x;
        else b-=x;
        x++;
    }
}
