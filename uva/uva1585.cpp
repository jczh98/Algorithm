#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 100010
using namespace std;

int t,len,p,ans;
char s[MN];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);p=1;ans=0;
		for(int i=0;i<len;i++){
			if(s[i]=='X')p=1;
			if(s[i]=='O'){			
				if(i>=1&&s[i]==s[i-1])p++; 
				ans+=p;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	
}
