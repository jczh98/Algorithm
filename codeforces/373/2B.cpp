#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int n,x,y,ans;
char str[100100];

int main(){
	cin>>n;x=y=0;
	scanf("%s",str);
	for(int i=0;i<n;i++){
		if(i%2){
			if(str[i]!='r')x++;
		}else{
			if(str[i]!='b')y++;
		} 
	}
	ans=max(x,y);
	x=y=0;
	for(int i=0;i<n;i++){
		if(i%2){
			if(str[i]!='b')x++;
		}else{
			if(str[i]!='r')y++;
		} 
	}	
	ans=min(ans,max(x,y));
	printf("%d\n",ans);
	return 0;
}
