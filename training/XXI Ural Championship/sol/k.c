#include "stdio.h"

int n,x=0,y=0;

int outp ()
{
printf ("%d %d\n",x,y);
return 0;
}

int up (int a)
{
x+=9*a;y+=12*a;
};

int aside ()
{
x+=16,y-=12;
}

main()
{
int i,k;
scanf ("%d",&n);
if (n==3) printf ("0 0\n4 3\n-20 21\n");
else {
k=(n-1)/2;
outp();
up(k);
outp();
aside();
outp();
up(-1);
if (n%2==0) outp();

for (i=0;i<k-1;i++)
{
 aside();
 outp();
 up(-1);
 outp();
}
}
return 0;
}