#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

char s[1000010];
int t,next[1000010],len,num[1000010];
ll ans;

void GetNext(){
	int k=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(k==-1||s[k]==s[j]){
			k++;j++;
			next[j]=k;
			num[j]=num[k]+1;
		}else{
			k=next[k];
		}
	}
	k=-1;j=0;ans=1;
	while(j<len){
		if(k==-1||s[k]==s[j]){
			k++;j++;
			while((k<<1)>j)k=next[k];
			ans*=num[k]+1;
			ans%=1000000007;
		}else{
			k=next[k];
		}
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);
		memset(num,0,sizeof(num));
		GetNext();
		cout<<ans<<endl;
	}
} 
