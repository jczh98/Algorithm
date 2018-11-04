#include <bits/stdc++.h>
using namespace std;
int t; string s;
map<string, string> mp;
int main() {
    cin >> t;
    mp["zero"] = "ling"; mp["one"] = "yi"; mp["two"] = "er" ;
    mp["three"] = "san"; mp["four"] = "si"; mp["five"] = "wu";
    mp["six"] = "liu"; mp["seven"] = "qi"; mp["eight"] = "ba";
    mp["nine"] = "jiu"; mp["ten"] = "shi";
    while(t--) {
        cin >> s;
        cout << mp[s] << endl;
    }
    return 0;
}