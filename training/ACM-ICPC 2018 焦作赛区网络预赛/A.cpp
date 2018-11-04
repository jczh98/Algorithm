#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        if(s == "jessie") {
            cout << "Good guy!" << endl;
        }else {
            cout << "Dare you say that again?" << endl;
        }
    }
    return 0;
}