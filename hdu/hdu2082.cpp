#include <cstdio>
#include <cstring>

int n,num,a[100],b[100],ans;

int main(){
	scanf("%d",&n);
	while(n--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		ans=0;
		for(int i=1;i<=26;i++){
			scanf("%d",&num);
			a[0]=1;
			if(num==0)continue;
			for(int j=0;j<=50;j++){
				for(int k=0;k<=num&&k*i+j<=50;k++){
					b[k*i+j]+=a[j];
				}
			}
			for(int j=0;j<=50;j++){
				a[j]=b[j];
				b[j]=0;
			}
		}
		for(int i=1;i<=50;i++){
			ans+=a[i];
		}
		printf("%d\n",ans);
	}	
	return 0;
} 
