#include <bits/stdc++.h>
using namespace std;
int t,r,p,d;
float scf,scw;
struct Node
{
    char name[100];
    float w,per;
}rep[100];
int main()
{
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d%d",&r,&p,&d);
        scf=(float)d*1.0/(float)p;
        for(int i=1;i<=r;i++)
        {
            scanf("%s%f%f",&rep[i].name,&rep[i].w,&rep[i].per);
        }
        for(int i=1;i<=r;i++)
        {
            if(rep[i].per==100.0)
            {
                scw=rep[i].w=scf*rep[i].w;break;
            }
        }
        for(int i=1;i<=r;i++)
        {
            if(scw!=rep[i].w)
            {
                rep[i].w=scw*(rep[i].per/100.0);
            }
        }
        printf("Recipe # %d\n",k);
        for(int i=1;i<=r;i++)printf("%s %.1f\n",rep[i].name,rep[i].w);
        printf("----------------------------------------\n");
    }
}
