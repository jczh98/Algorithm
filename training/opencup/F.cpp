#include <bits/stdc++.h>
using namespace std;
string ver[1100], hor[1100], mp[1100];
deque<string> vec_hor, vec_ver;
vector<string> ans_hor, ans_ver;
int n, m;
int main() {
    scanf("%d%d",&n, &m);
    for(int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    for(int i = 0; i < n; i++) {
        hor[i] = mp[i];
        vec_hor.push_back(hor[i]);
    }
    for(int j = 0; j < m; j++) {
        ver[j] = "";
        for(int i = 0; i < n; i++) {
            ver[j] += mp[i][j];
        }
        vec_ver.push_back(ver[j]);
    }
    sort(vec_ver.begin(), vec_ver.end(), greater<string>() );
    sort(vec_hor.begin(), vec_hor.end(), greater<string>() );
    for(int i = 0; i < n; i++) {
        deque<string> t = vec_hor;
        t.erase(find(t.begin(), t.end(), hor[i]));
        int max_pos = -1, max = -1;
        string st, ed;
        for(int j = 0; j < hor[i].size(); j++) {
            if(hor[i][j] - '0' > max) {
                max = hor[i][j] - '0';
                max_pos = j;
            }
        }
        for(int j = 0; j < hor[i].size(); j++) {
            if(hor[i][j] == max + '0') {
                deque<string> tt = t;
                st = ""; ed = "";
                for(int k = j; k < hor[i].size(); k++) {
                    st += hor[i][k];
                }
                for(int k = 0; k < j; k++) {
                    ed += hor[i][k];
                }
                tt.push_front(st);tt.push_back(ed);
                string cur = "";
                for(int k = 0; k < tt.size(); k++) {
                    cur += tt[k];
                }
                ans_hor.push_back(cur);
            }
        }
    }
    sort(ans_hor.begin(), ans_hor.end(), greater<string>() );

    for(int i = 0; i < m; i++) {
        deque<string> t = vec_ver;
        t.erase(find(t.begin(), t.end(), ver[i]));
        int max_pos = -1, max = -1;
        string st, ed;
        for(int j = 0; j < ver[i].size(); j++) {
            if(ver[i][j] - '0' > max) {
                max = ver[i][j] - '0';
                max_pos = j;
            }
        }
        for(int j = 0; j < ver[i].size(); j++) {
            if(ver[i][j] == max + '0') {
                deque<string> tt = t;
                st = ""; ed = "";
                for(int k = j; k < ver[i].size(); k++) {
                    st += ver[i][k];
                }
                for(int k = 0; k < j; k++) {
                    ed += ver[i][k];
                }
                tt.push_front(st);tt.push_back(ed);
                string cur = "";
                for(int k = 0; k < tt.size(); k++) {
                    cur += tt[k];
                }
                ans_ver.push_back(cur);
            }
        }
    }
    sort(ans_ver.begin(), ans_ver.end(), greater<string>() );
    cout << max(ans_hor[0], ans_ver[0]) <<endl;
    return 0;
}

