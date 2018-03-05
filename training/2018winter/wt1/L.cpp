#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,c,a,b;
int pre[7]={2,4,8,16,32,64,128};
string expr;
LL get(int l,int r) {
    int ret=0;
    for(int i=l;i<=r;++i) {
        ret=ret*10+expr[i]-'0';
    }
    return ret;
}
bool judge(LL num,int a, int b,int len) {
    double percise=1.0;
    for(int i=1;i<=len;++i)percise*=0.1;
    double tmp2=a*1.0/b;
    //cout << num<< " " << percise << " " << tmp2 << endl;
    if(fabs(num*percise-tmp2)<=percise) return true;
    else return false;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        cin>>expr;
        if(expr[expr.size()-1]=='.') {
            c=get(0,expr.size()-2);
            printf("%d\"\n",c);
            continue;
        }
        int pos=-1;
        for(int i=0;i<expr.size();++i) {
            if(expr[i]=='.') pos=i;
        }
        if(pos==-1) {
            c=get(0,expr.size()-1);
            printf("%d\"\n",c);
            continue;
        }
        LL num=get(pos+1,expr.size()-1);
        c=get(0,pos-1);
        int flag=0;
        for(int i=0;i<7;++i){
            if(flag)break;
            for(int j=1;j<pre[i];++j) {
                if(judge(num,j,pre[i],expr.size()-1-pos)) {
                    flag=1;
                    a=j;b=pre[i];
                    break;
                }
            }
        }
        if(c!=0) printf("%d ",c);
        printf("%d/%d\"\n",a,b);
    }
    return 0;
}