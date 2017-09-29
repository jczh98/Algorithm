#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[24] = {0, 1, 8, 49, 288, 1681, 9800, 57121, 332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048, 76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328, 101302819786919521};
/*bool Judge(LL x){
    LL t = floor(sqrt((double) x));
    if(t * t == x) {
        return 1;
    }else {
        return 0;
    }
};*/
LL t, n;
int main() {
    cin >> t;
    for(int kase = 1; kase <= t; kase++) {
        cin >> n;
        cout << "Case #" << kase << ": ";
        cout << * lower_bound(a, a + 24, n) << endl;
    }
}

