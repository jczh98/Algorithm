#include <stdio.h>
int isPalindrome(int n);
int main()
{
	int i,n=0;
	for (i=1;i<=1221;i++)	
	{
		if (isPalindrome(i))
		{
			printf("%7d",i);
			if (++n%10==0)
				printf("\n");
		}
 
	}
	printf("\n");
}
int isPalindrome(int n)
{
	int m=0,a,b;
	for (b=n;b>0;b/=10)
	{
		a=b%10;
		m=m*10+a;
	}
		return(m==n);
}