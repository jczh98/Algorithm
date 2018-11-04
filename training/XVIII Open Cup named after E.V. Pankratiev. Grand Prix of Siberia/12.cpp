#include <bits/stdc++.h>
using namespace std;
string z, x, y;
int t;
int main() {
    cin >> t;
    while(t--) {
        int flag = 0;
        cin >> z >> x >> y;
        int pos = z.find(x);
        string tmp = z.substr(pos+x.size(), z.size());
        int pos2= z.find(y);
        string tmp2 = z.substr(pos2+y.size(), z.size());
        //cout << tmp << endl;
        if(tmp.find(y) != -1 || tmp2.find(x) != -1) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }
    return 0;
}