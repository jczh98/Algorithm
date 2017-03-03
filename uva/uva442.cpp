#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;
typedef long long ll;

struct Com{
	int a,b;
	Com(int a=0,int b=0):a(a),b(b){
	}
}M[100];

int n,flag;
string s,exp;
stack<Com> st;
ll ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>s;
		cin>>M[s[0]-'A'].a>>M[s[0]-'A'].b;	
	}
	while(cin>>exp){
		ans=0;flag=1;
		for(int i=0;i<exp.length();i++){
			if(isalpha(exp[i])){
				st.push(M[exp[i]-'A']);
			}else if(exp[i]==')'){
				Com t2=st.top();st.pop();
				Com t1=st.top();st.pop();
				if(t1.b!=t2.a){
					flag=0;break;
				}
				ans+=t1.a*t1.b*t2.b;
				st.push(Com(t1.a,t2.b));
			}
		}
		if(flag)cout<<ans<<endl;
		else printf("error\n");
	}
	return 0;
}
