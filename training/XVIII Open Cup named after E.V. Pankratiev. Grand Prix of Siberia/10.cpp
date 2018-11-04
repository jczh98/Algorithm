#include <bits/stdc++.h>
using namespace std;
string a, b;
int A, B;
int main() {
    cin >> a >> b;
    for(int i = 0; i < a.size(); ++i) {
        if(a[i] > b[i]) B++;
        if(a[i] < b[i]) A++;
    }
    cout << A << endl;
    cout << B << endl;
}