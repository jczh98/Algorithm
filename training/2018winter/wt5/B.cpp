#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
string numbers;
map<LL,int> sets;
int main() {
    while(scanf("%d",&n)!=EOF) {
        sets.clear();
        for(int i=1;i<=n;++i) {
            cin>>numbers; LL Hash=0;
            for(int i=0;i<numbers.size();++i) {
                Hash|=(1<<(numbers[i]-'0'));
            }
            sets[Hash]=1;
        }
        cout<<sets.size()<<endl;
    }
    return 0;
}