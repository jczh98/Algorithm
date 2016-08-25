#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 100010
using namespace std;

int t,l,ans;
char s[MN];

int Compare(int a,int b){
	for(int i=0;i<l;i++){
		if(s[(a+i)%l]!=s[(b+i)%l]){
			return s[(a+i)%l]<s[(b+i)%l];
		}
	}
	return 0;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		l=strlen(s);ans=0;
		for(int i=1;i<l;i++){
			if(Compare(i,ans))ans=i;
		}
		for(int i=0;i<l;i++)putchar(s[(i+ans)%l]);
		printf("\n");
	}
	return 0;
}
