#include <bits/stdc++.h>
using namespace std;
int n, a[10000], cnt[10000];
vector<int> ans;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int flag = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] > 0) {
            cnt[a[i]]++;
        }
        if(a[i] < 0) {
            //cout << a[i] << " " << cnt[-a[i]] << endl;
            if(cnt[-a[i]] > 0) {
                cnt[-a[i]]--;
            }else {
                flag = 1;
                break;
            }
        }
        if(a[i] == 0) {
            for(int j = i + 1; j <= n; ++j) {
                if(a[j] < 0 && !cnt[-a[j]]) {
                    //cout << "true" << endl;
                    cnt[-a[j]]++; 
                    ans.push_back(-a[j]);
                    break;
                }
            }
        }
    }
    if(!flag) {
        printf("Yes\n");
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
        }
    } else {
        printf("No\n");
    }
    return 0;
}