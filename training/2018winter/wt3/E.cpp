#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int nxt[MAXN], extend[MAXN];
string s1, s2;
int n;
void GetNext(string S) {
    nxt[0] = S.size();
    int j = 0, k = 1, p, L;
    while(j + 1 < S.size() && S[j] == S[j + 1]) j++;
    nxt[1] = j;
    for(int i = 2; i < S.size(); i++) {
        p = nxt[k] + k - 1;
        L = nxt[i - k];
        if(i + L < p + 1) nxt[i] = L;
        else {
            j = max(0, p - i + 1);
            while(i + j < S.size() && S[i + j] == S[j]) j++;
            nxt[i] = j;
            k = i;
        }
    }
}
void ExtendKmp(string P, string T) {
    GetNext(P);
    int j = 0, k = 1, p, L;
    while(j < P.size() && j < T.size() && P[j] == T[j]) j++;
    extend[0] = j;
    for(int i = 1; i < T.size(); i++) {
        p = extend[k] + k - 1;
        L = nxt[i - k];
        if(i + L < p + 1) extend[i] = L;
        else {
            j = max(0, p - i + 1);
            while(i + j < T.size() &&  j < P.size() && T[i + j] == P[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}
int C[200005];
int lowbit(int x) {return x&(-x);}
void update(int x,int y) {
    for(int i=x;i<=100000;i+=lowbit(i)) C[i]+=y;
}
int query(int x) {
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)) ret+=C[i];
    return ret;
}
int main() {
    getline(cin,s1);
    getline(cin,s2);
    cin>>n;
    ExtendKmp(s2,s1);
    for(int i=0;i<s1.size();++i) {
        update(1,1);
        update(extend[i]+1,-1);
    }
    for(int i=s1.size();i>=1;--i) {
        if(query(i)>=n) {
            for(int j=0;j<i;++j) {
                cout<<s2[j];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}