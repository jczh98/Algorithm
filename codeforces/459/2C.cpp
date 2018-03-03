#include <bits/stdc++.h>
using namespace std;
string s;
int marks, lb, rb, par[5005][5005], ans;
int main() {
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        marks = 0; lb = 0; rb = 0;
        for(int j = i; j < s.size(); ++j) {
            if(s[j] == '(') {
                lb++;
            }else if(s[j] == '?') {
                marks++;
            }else if(s[j] == ')') {
                rb++;
            }    
            if(rb > lb + marks) break;
            if((j - i + 1) % 2 == 0) {
                if(abs(lb - rb) <= marks) {
                    par[i][j]++;
                }
            }      
        }
    }
    for(int i = s.size() - 1; i >= 0; --i) {
        marks = 0; lb = 0; rb = 0;
        for(int j = i; j >= 0; --j) {
            if(s[j] == '(') {
                lb++;
            }else if(s[j] == '?') {
                marks++;
            }else if(s[j] == ')') {
                rb++;
            }    
            if(lb > rb + marks) break;
            if((j - i + 1) % 2 == 0) {
                if(abs(lb - rb) <= marks) {
                    par[j][i]++;
                }
            }      
        }
    }    
    for(int i = 0; i < s.size(); ++i) {
        for(int j = 0; j < s.size(); ++j) {
            if(par[i][j] == 2) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}