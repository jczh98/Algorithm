#include <bits/stdc++.h>
using namespace std;
set<string> stt;
string str;
int main() {
/*    default_random_engine dre(time(0));
    for(int i = 10; i <= 10000000; i *= 10) {
        int ans = INT_MAX;
        for(int j = 0; j < 100; ++j) {
            set<int> st;
            for(int k = 0; k < 10000; ++k) {
                uniform_int_distribution<int> dist(1, i);
                st.insert(dist(dre));
            }
            ans = std::min(ans, (int) st.size());
            //ans += st.size();
            //cout << i << " " << st.size() << endl;
        }
        //ans = round(ans * 1.0 / 100);
        cout << ans << endl;
    }*/
    for(int i = 0; i < 10000; ++i) {
        cout << "+" << endl;
        fflush(stdout);
        cin >> str;
        stt.insert(str);
    }
    cout << "= ";
    if(stt.size() >= 9987) {
        cout << 10000000 << endl;
    }else if(stt.size() >= 9925) {
        cout << 1000000 << endl;
    }else if(stt.size() >= 9462) {
        cout << 100000 << endl;
    }else if(stt.size() >= 6192) {
        cout << 10000 << endl;
    }else if(stt.size() >= 998) {
        cout << 1000 << endl;
    }else if(stt.size() >= 100) {
        cout << 100 << endl;
    }else if(stt.size() >= 10) {
        cout << 10 << endl;
    }
    return 0;
}

