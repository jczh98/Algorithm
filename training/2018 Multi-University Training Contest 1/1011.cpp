#include <bits/stdc++.h>
using namespace std;
int t, a, b, flag, number, n1, n2;
string utc, p, q;
char m;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> a >> b >> utc;
        m = utc[3];
        utc = utc.substr(4, utc.size());
        flag = utc.find('.');
        //cout << m << " " <<  flaAg << " " << utc << endl;
        if(flag > 0) {
            p = utc.substr(0, utc.find('.'));
            q = utc.substr(utc.find('.') + 1, utc.size());
            n1 = atoi(p.c_str()); n2 = atoi(q.c_str());
            //cout << n1 << " " << n2 << endl;
            if(m == '+') {
                if(n1 >= 8) {
                    a = (a + n1 - 8) % 24;
                    b = (b + 60 * n2 / 10);
                    if(b >= 60) {
                        a = (a + 1) % 24;
                        b %= 60;
                    }
                } else {
                    a = (a + n1 - 8 + 24) % 24;
                    b = (b - 60 * (10 - n2)/ 10);
                    if(b >= 0) {
                        if(n2) a = (a + 1) % 24;
                    } else {
                        b += 60;
                    }
                }
            } else {
                a = (a - n1 - 8 + 24) % 24;
                b = (b - 60 * n2 / 10);
                if(b < 0) {
                    a = (a - 1 + 24) % 24;
                    b += 60;
                }
            }
        }else {
            number = atoi(utc.c_str());
            if(m == '+') {
                if(number >= 8) {
                    a = (a + number - 8) % 24;
                } else {
                    a = (a + number - 8 + 24) % 24;
                }
            } else {
                a = (a - number - 8 + 24) % 24;
            }
        }
        printf("%02d:%02d\n", a, b);
    }
    return 0;
}