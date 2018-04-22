#include <bits/stdc++.h>
using namespace std;
pair<string, string> name[2000005];
map<string, string> name2score;
bool cmp(pair<string, string> a, pair<string, string> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }else return a.first > b.first;
}
int n;
int main() {
    //freopen("out.txt", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> name[i].second >> name[i].first;
        name2score[name[i].second] = name[i].first;
    }
    for(int i = 1; i <= n; ++i) {
        int len = name[i].first.size();
        for(int j = len - 1; j >= 0; --j) {
            if(name[i].first[j] == '0') {
                name[i].first.erase(j);
            }else break;
        }
    }
    sort(name + 1, name + 1 + n, cmp);
    for(int i = 1; i <= n; ++i) cout << name[i].second << " " << name2score[name[i].second] << endl;
    return 0;
}