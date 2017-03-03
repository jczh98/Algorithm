#include <cstdio>

int T,W;

int Solve(int &w)
{
    int w1,d1,w2,d2;
    int b1=1,b2=1;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    if(!w1)b1=Solve(w1);
    if(!w2)b2=Solve(w2);
    w=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        if(Solve(W))printf("YES\n");else printf("NO\n");
        if(T)printf("\n");
    }
    return 0;
}
