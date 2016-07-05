#include<cstdio>
#include <cstring>

int t,n,m,s[1000000+10],p[1000000+10],next[1000000+10],ans=0;

void GetNext(){
	memset(next,0,sizeof(next));
	int k=-1,j=0;
	next[0]=-1;
	while(j<m-1){
		if(k==-1||p[k]==p[j]){
			++k;++j;
			next[j]=k;
		}else{
			k=next[k];
		}
	}
}

int Kmp(){
	int i=0,j=0,r=-1;
	while(i<n&&j<m){
		
		if(s[i]==p[j]||j==-1){
			i++;j++;
		}else{
			j=next[j];
		}
		if(j==m-1&&s[i]==p[j])break;
	}
	if(j==m-1)r=i-j+1;
	return r;
}

int main() {
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&s[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%d",&p[i]);
		}
		GetNext();
		ans=Kmp();
		printf("%d\n",ans);
	}
} 
