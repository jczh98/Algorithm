#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

int n,k,state[600],num,tot[100],check[100][100];
ll dp[100][600][100],ans=0;

int JudgeTwo(int x,int y){
	if(x&y)return 0;
	if(x&(y>>1)) return 0;
	if(x&(y<<1)) return 0;
	return 1;
}

int JudgeOne(int x){
	if(x&(x>>1)) return 0;
	if(x&(x<<1)) return 0;
	return 1;
}

int GetTot(int x){
	int tot=0;
	while(x){
		if(x&1)tot++;
		x>>=1;
	}
	return tot;
}

void Pre(){
	num=1;
	memset(state,0,sizeof state);
	memset(tot,0,sizeof tot);
	memset(check,0,sizeof check);
	for(int i=0;i<(1<<n);i++){
		if(JudgeOne(i)){
			state[num]=i;
			tot[num++]=GetTot(i);
		}
	}
	for(int i=1;i<num;i++){
		for(int j=1;j<num;j++){
			if(JudgeTwo(state[i],state[j])){
				check[i][j]=check[j][i]=1;
			}
		}
	}	
}
int main(){
	scanf("%d%d",&n,&k);
	Pre();
	dp[0][1][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<num;j++){
			for(int z=0;z<=k;z++){
				if(tot[j]<=z){
					for(int m=1;m<num;m++){
						if(check[j][m]==1&&tot[j]+tot[m]<=z){
							dp[i][j][z]+=dp[i-1][m][z-tot[j]];
						}
					}
				}
			}
		}
	}
	for(int i=1;i<num;i++){
		ans+=dp[n][i][k];
	}
	cout<<ans<<endl;
}
