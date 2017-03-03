#include <cstdio>

int n,a[1000];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(a[n]==15){
		printf("DOWN\n");
	}else if(a[n]==0){
		printf("UP\n");
	}else if(n==1){
		printf("-1\n");
	}else if(a[n]>a[n-1]){
		printf("UP\n");
	}else printf("DOWN\n");
	return 0;
}
