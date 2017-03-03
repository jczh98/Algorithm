#include <cstdio>
#include <stack>
using namespace std;

int t[10000],A,B,n,flag;

int main(){
	while(scanf("%d",&n)==1&&n){
		while(scanf("%d",&t[1])==1&&t[1]){
			for(int i=2;i<=n;i++) scanf("%d",&t[i]);
			stack<int> s;
			A=B=1;flag=1;
			while(B<=n){
				if(A==t[B]){
					A++;B++;
				}else if(!s.empty()&&s.top()==t[B]){
					s.pop();B++;
				}else if(A<=n){
					s.push(A++);
				}else {
					flag=0;break;
				}
			}
			printf("%s\n",flag?"Yes":"No");			
		}
		printf("\n");
	}
	return 0;
}
