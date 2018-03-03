#include <bits/stdc++.h>
using namespace std;
int n, m;
string readin, ip;
map<string, string> table;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> readin >> ip;
        table[ip] = readin;
    }
    for(int i = 1; i <= m; ++i) {
        cin >> readin >> ip;
        ip = ip.substr(0, ip.size() - 1);
        cout << readin << " " << ip << "; #" << table[ip] << endl; 
    }
    return 0;
}