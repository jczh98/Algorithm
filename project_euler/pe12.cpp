#include <bits/stdc++.h>
using namespace std;
int Count(int x) {
    if(x == 1) return 1;
    int ret = 0, sqr2 = sqrt(x), i;
    for(i = 1; i < sqr2; ++i) {
        if(x % i == 0) ret++;
    }
    ret <<= 1;
    if(i * i == x) ret++;
    return ret;
}
int main() {
    for(int i = 2, sum = 1; ;++i) {
        if(Count(sum) > 500) {
            cout << sum << endl;
            break;
        }
        sum += i;
    }
}