#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cctype>
#define MN 100010
using namespace std;

char s[MN];
int t,num;
float ans;

int main(){
	scanf("%d",&t);
	while(t--){
		ans=0.00;
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++){
			if(isalpha(s[i])){
				num=atoi(s+i+1);
				if(num==0)num=1; 
				if(s[i]=='C'){
					ans+=12.01*(float)num; 
				}else if(s[i]=='H'){
					ans+=1.008*(float)num; 
				}else if(s[i]=='O'){
					ans+=16.00*(float)num; 
				}else if(s[i]=='N'){
					ans+=14.01*(float)num; 
				}
			}
		}
		printf("%.3f\n",ans);
	}
	return 0;
}
