#include <bits/stdc++.h>
using namespace std;
int Max, Max_val, record[2000005];
int main() {
    record[1] = 1;
    for(int i = 2;  i <= 1000000; ++i) {
        int st = i, cnt = 0;
        while(st > i || record[st] == 0) {
            if(st & 1) st = 3 * st + 1;else st = st / 2; cnt++;
        }
        cnt += record[st];
        record[i] = cnt;
        if(cnt > Max) {
            Max = cnt;
            Max_val = i;
        }
    }
    cout << Max_val << endl;
}