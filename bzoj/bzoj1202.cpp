#include <cstdio>
#include <cstring>

int w,n,m,s,t,v,fa[110],val[110],temp,flag;

int Find(int x){
	if(fa[x]==x)return x;
	temp=Find(fa[x]);
	val[x]+=val[fa[x]];
	fa[x]=temp;
	return fa[x];
}

void Solve(int x,int y,int z){
	int f1=Find(x),f2=Find(y);
	if(f1!=f2){
		fa[f1]=f2;
		val[f1]=val[y]-val[x]-z;
	}else if(val[y]-val[x]!=z) flag=1;
}

void Init(){
	for(int i=0;i<=n;i++)fa[i]=i;
}

int main(){
	scanf("%d",&w);
	while(w--){
		memset(val,0,sizeof val);
		flag=0;
		scanf("%d%d",&n,&m);
		Init();
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&s,&t,&v);
			Solve(s-1,t,v);
		}
		if(flag==1)printf("false\n");
		else printf("true\n");
	}
	return 0;
}
