#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 1010
using namespace std;

int n,a[MN],b[MN],flag,wz,c1,c2,bb,kase=1;

int main(){
	while(scanf("%d",&n)!=EOF){
		if(n==0)break;
		printf("Game %d:\n",kase++);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		while(1){			
			flag=0;wz=0;bb=0;
			for(int i=0;i<n;i++) {
				scanf("%d",&b[i]);
				if(b[i]==0)flag++;
			}
			if(flag==n)break;
			for(int i=0;i<n;i++){
				if(a[i]==b[i])wz++;
			}
			for(int i=1;i<=9;i++){
				c1=c2=0;
				for(int j=0;j<n;j++){
					if(i==a[j])c1++;
					if(i==b[j])c2++;
				}
				bb+=min(c1,c2);
			}
			bb-=wz;
			printf("    (%d,%d)\n",wz,bb); 
		}
	}	
	return 0;
}
