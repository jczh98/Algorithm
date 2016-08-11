#include <cstdio>

int n=0,m;
long long s=1;
int main(){
	scanf("%d",&m);
	while(s<=m){
		s*=2;
		n++;
	}
	printf("%d",n);
}
