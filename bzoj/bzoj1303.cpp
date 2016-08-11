#include <cstdio>

int n,b,t,a[100010],p,pre[100010],l[200010],r[200010],ans=0;

int main() {
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);
		if(t==b){
			a[i]=0;p=i;
		}else if(t>b){
			a[i]=1;
		}else if(t<b){
			a[i]=-1;
		}
	}
	l[n]=1;r[n]=1;
	for(int i=p-1;i>=1;i--){
		pre[i]=pre[i+1]+a[i];
		l[pre[i]+n]++;
	}
	for(int i=p+1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		r[pre[i]+n]++;
	}
	for(int i=0;i<=2*n;i++){
		ans+=l[i]*r[2*n-i];
	}
	printf("%d\n",ans);
	return 0;
}
