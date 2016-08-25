#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cctype>
#define MN 100010
using namespace std;

int t,a[20],n,x;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			x=i;
			while(x>0){
				a[x%10]++;x/=10;
			}
		}
		for(int i=0;i<9;i++)printf("%d ",a[i]);printf("%d\n",a[9]);
	}
	return 0;
}
