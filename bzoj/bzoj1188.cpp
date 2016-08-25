#include <cstdio>
#include <cstring>

int t,n,a[100],sg[100],vis[100000],ans,cnt;

void PreSG(){
	sg[0]=0;
	memset(vis,0,sizeof vis);
	for(int i=1;i<=22;i++){
		for(int j=0;j<i;j++){
			for(int k=0;k<=j;k++){
				vis[sg[j]^sg[k]]=1;
			}
		}
		for(int j=0;;j++){
			if(!vis[j]){
				sg[i]=j;break;
			}
		}
	}
}

int main(){
	scanf("%d",&t);
	PreSG();
	while(t--){
		scanf("%d",&n);
		ans=0,cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(a[i]&1)ans^=sg[n-i-1];
		}	
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j;k<n;k++){
					if((ans^sg[n-i-1]^sg[n-j-1]^sg[n-k-1])==0){
						cnt++;
						if(cnt==1)printf("%d %d %d\n",i,j,k);
					}
				}
			}
		}		
		if(cnt==0)printf("-1 -1 -1\n");
		printf("%d\n",cnt);
	}	
	return 0;
}
