#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,pos_equ,pos_op,vis[100];
LL num1,num2,num3;
string expr,rep;
int get(int l, int r) {
    int flag=0,ret=0;
    if(rep[l]=='-')flag=1,l++;
    if(rep[l]=='-'&&rep[l+1]=='0')return INT_MAX;
    if(rep[l]=='0'&&r-l>=1)return INT_MAX;
    for(int i=l;i<=r;++i)ret=ret*10+rep[i]-'0';
    if(flag) ret*=-1;
    return ret;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        memset(vis,0,sizeof(vis));
        cin>>expr;rep=expr;
        int judge=0;
        for(int i=0;i<expr.size();++i) {
            if(isdigit(expr[i]))vis[expr[i]-'0']=1;
            if(expr[i]=='=') pos_equ=i;
        }
        for(int i=1;i<pos_equ;++i){
            if(expr[i]=='+'||expr[i]=='-'||expr[i]=='*') {pos_op=i;break;}
        }
        for(int digit=0;digit<=9;++digit) {
            if(vis[digit])continue;
            num1=num2=num3=0;
            for(int i=0;i<rep.size();++i) {
                if(expr[i]=='?')rep[i]=digit+'0';
            }            
            num1=get(0,pos_op-1);num2=get(pos_op+1,pos_equ-1);num3=get(pos_equ+1,rep.size()-1);
            //cout<<num1<<" "<<num2<<" "<<num3<<endl;
            if(num1==INT_MAX||num2==INT_MAX||num3==INT_MAX) continue;
            if(expr[pos_op]=='+') {
                if(num1+num2==num3) {
                    judge=1;
                    printf("%d\n",digit);break;
                }
            }else if(expr[pos_op]=='-') {
                if(num1-num2==num3) {
                    judge=1;
                    printf("%d\n",digit);break;
                }
            }else if(expr[pos_op]=='*') {
                if(num1*num2==num3) {
                    judge=1;
                    printf("%d\n",digit);break;
                }
            }
        }
        if(!judge)printf("-1\n");
    }
    return 0;
}