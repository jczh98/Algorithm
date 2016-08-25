#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cctype>
#define MN 100010
using namespace std;

char s[MN];
int t,flag,len;

int main(){
	cin>>t;
	while(t--){
		scanf("%s",s);
		len=strlen(s);
		for(int i=1;i<=len;i++){
			if(len%i==0){
				flag=1;
				for(int j=i;j<len;j++){
					if(s[j]!=s[j%i]){
						flag=0;break;
					}
				}
				if(flag){
					printf("%d\n",i);
					if(t) printf("\n");
					break;
				}				
			}

		}
	}
	return 0;
}
