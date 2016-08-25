#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m,num[100];
double a[100],b[100];
double fac[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};

/*int fac(int x){
	if(x==0||x==1)return 1;
	return x*fac(x-1);
}*/

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<=m;i++) a[i]=b[i]=0.00;
		for(int i=0;i<n;i++) scanf("%d",&num[i]);
		for(int i=0;i<=num[0];i++) a[i]=(1.00/fac[i]);
		for(int i=1;i<n;i++){
			for(int j=0;j<=m;j++){
				for(int k=0;k<=num[i]&&k+j<=m;k++){
					b[k+j]+=(a[j]/fac[k]);
				}
			}
			for(int j=0;j<=m;j++){
				a[j]=b[j];b[j]=0.00;
			}
		}
		printf("%.0f\n",a[m]*1.0*fac[m]);		
	}
	return 0;	
}
