#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define eps 1e-6
using namespace std;

int n;
double a[100][100],M[100][100];

void GaussJordan(){
	int r;
	for(int i=1;i<=n;i++){
		r=i;
		for(int j=i+1;j<=n;j++)if(fabs(M[j][i])>fabs(M[r][i]))r=j;
		if(fabs(M[r][i])<eps)continue;
		if(r!=i)for(int j=1;j<=n+1;j++)swap(M[i][j],M[r][j]);
		for(int k=1;k<=n;k++)if(k!=i){
			for(int j=n+1;j>=i;j--){
				M[k][j]-=M[k][i]/M[i][i]*M[i][j];
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	memset(M,0,sizeof M);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			M[i][j]+=2*(a[i+1][j]-a[i][j]);
		}
		for(int j=1;j<=n;j++){
			M[i][n+1]+=a[i+1][j]*a[i+1][j]-a[i][j]*a[i][j];
		}
	}
	GaussJordan();
	for(int i=1;i<n;i++){
		printf("%.3lf ",M[i][n+1]/M[i][i]);
	}
	printf("%.3lf",M[n][n+1]/M[n][n]);	
	return 0;
}
