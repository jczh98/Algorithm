#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct BD{
	int a[11000],len;
	BD(){
		memset(a,0,sizeof a);
		len=1;
	}
	
	BD operator * (int x) const{
		BD re;
		re.len=len+1;
		for(int i=0;i<len;i++){
			re.a[i]+=a[i]*x;
			re.a[i+1]+=re.a[i]/10;
			re.a[i]%=10;
		}
		while(re.len>1&&!re.a[re.len-1])re.len--;
		return re;
	}
	
	friend inline BD operator - (BD x,BD y) {
		BD re;
		re.len=max(x.len,y.len);
		for(int i=0;i<re.len;i++){
			re.a[i]=x.a[i]-y.a[i];
			while(re.a[i]<0){
				re.a[i]+=10;
				x.a[i+1]--;
			}
		}
		while(re.len>1&&!re.a[re.len-1])re.len--;
		return re;
	}
	
	BD operator + (int x) const {
		BD re;re.len=len;
		for(int i=0;i<len;i++){
			re.a[i]=a[i];
		}
		re.a[0]+=x;
		for(int i=0;i<len;i++){
			if(re.a[i]>9){
				re.a[i]-=10;re.a[i+1]+=1;
			}else break;
		}
		while(re.len>1&&!re.a[re.len-1])re.len--;
		return re;
	}
	
	void print(){
		for(int i=len-1;i>=0;i--){
			printf("%d",a[i]);
		}
		printf("\n");
	}
};

BD f[110];
int n;

int main(){
	cin>>n;	
	f[1].a[0]=1;f[1].len=1;
	f[2].a[0]=5;f[2].len=1;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]*3;
		f[i]=f[i]-f[i-2];
		f[i]=f[i]+2;		
	}
	f[n].print();
} 
