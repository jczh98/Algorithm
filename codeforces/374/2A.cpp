#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n,a[10000],cnt=0,k=0;
char s[10000];

int main(){
	scanf("%d",&n);
	scanf("%s",s);
	int len=strlen(s);
	s[len]='W';
	for(int i=0;i<=len;i++){
		if(s[i]=='W'&&s[i-1]=='B')a[k++]=cnt,cnt=0;
		if(s[i]=='B')cnt++;
	}
	if(k!=0){
		printf("%d\n",k);
		for(int i=0;i<k-1;i++)printf("%d ",a[i]);
		printf("%d\n",a[k-1]);	
	}else{
		printf("0\n");
	}
	return 0;
}
