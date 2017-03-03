#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int cur,last,n,next_p[100100];
char s[100100];

int main(){
	while(scanf("%s",s+1)!=EOF){
		s[0]=next_p[0]=0;
		cur=last=0;
		n=strlen(s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='['){
				cur=0;
			}else if(s[i]==']'){
				cur=last;
			}else{
				next_p[i]=next_p[cur];
				next_p[cur]=i;
				if(cur==last)last=i;
				cur=i;
			}
		}
		for(int i=next_p[0];i;i=next_p[i]){
			printf("%c",s[i]);
		}
		printf("\n");
	}
}
