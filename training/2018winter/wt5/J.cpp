#include <bits/stdc++.h>
using namespace std;
int n,cnt[100],cnt_r[100][100],cnt_c[100][100];
string col[100];
int main() {
    while(scanf("%d",&n)!=EOF) {
        memset(cnt,0,sizeof(cnt));
        memset(cnt_r,0,sizeof(cnt_r));
        memset(cnt_c,0,sizeof(cnt_c));
        for(int i=0;i<n;++i) {
            cin>>col[i];
            for(int j=0;j<col[i].size();++j) {
                cnt[col[i][j]-'A']++;
                cnt_r[col[i][j]-'A'][i]++;
                cnt_c[col[i][j]-'A'][j]++;
            }
        }
        int v;
        for(int i=0;i<=26;++i) if(cnt[i]&&cnt[i]==n-1) v=i;
        int flag=0;
        for(int i=0;i<n;++i) {
            if(flag)break;
            for(int j=0;j<n;++j) {
                if(!cnt_r[v][i]&&!cnt_c[v][j]) {
                    cout<<i+1<<" "<<j+1<<" "<<(char)(v+'A')<<endl;
                    flag=1;
                    break;
                }
            }
        }
    }
    return 0;
}