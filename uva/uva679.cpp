#include <cstdio>

int n,d,I,ans;

int main(){
	scanf("%d",&n);	
	for(int j=1;j<=n;j++){
		scanf("%d%d",&d,&I);
		ans=1;
		for(int i=1;i<d;i++){
			if(I%2){
				ans=ans*2;I=(I+1)/2;
			}else{
				ans=ans*2+1;I=I/2;
			}
		}
		printf("%d\n",ans);
	}
	scanf("%d",&n);
	return 0;
}
