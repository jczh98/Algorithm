#include <bits/stdc++.h>
using namespace std;
int t,n;
string lis[2000010];
vector<int> ans;
map<string,int> mp;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=1;i<=2*n;++i) {
            cin>>lis[i];
        }
        int cnt=0,cap=0;mp.clear();ans.clear();
        for(int i=1;i<=n;++i) {
            if(lis[i]==lis[i+n]&&cnt==0)ans.push_back(1);
            else {
                if(mp.find(lis[i])==mp.end()){mp[lis[i]]=1;cnt++;}
                else cnt--,cap++;
                if(mp.find(lis[i+n])==mp.end()){mp[lis[i+n]]=1;cnt++;}
                else cnt--,cap++;
                if(cnt==0){
                    ans.push_back(cap);cap=0;
                }
            }
        }
        for(int i=0;i<ans.size();++i) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    }
    return 0;
}