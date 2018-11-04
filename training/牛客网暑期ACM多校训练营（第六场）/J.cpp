#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int t, n, A, B, C;
vector<ull> vec, k;
unsigned x = A, y = B, z = C;
inline unsigned tang() {
    unsigned t;
    x ^= x << 16;
    x ^= x >> 5;
    x ^= x << 1;
    t = x;
    x = y;
    y = z;
    z = t ^ x ^ y;
    return z;
}
int main() {
    cin >> t;
    for(int kase = 1; kase <= t; ++kase) {
        cin >> n >> A >> B >> C;
        //k.clear(); 
        vec.clear();
        //k.push_back(A); k.push_back(B); k.push_back(C);
        x = A, y = B, z = C;
        ull a, b;
        for(int i = 1; i <= n; ++i) {
            vec.push_back(tang());
        } 
        ull ans = 1, ans2 = 0, Max = 0, Second = 0;
        //sort(vec.begin(), vec.end());
        // for(int i = 0; i < vec.size(); ++i) {
        //     cout << vec[i] << " ";
        // }cout << endl;
        //sort(k.begin(), k.end());
        if(n <= 1000000) {
            int nn = vec.size();
            for(int i = nn - 2; i >= 0; --i) {
                if(__gcd(vec[nn - 1], vec[i]) == 1) {
                    ans = ans * vec[i] / __gcd(ans, vec[i]); break;
                }  
            }            
        } else {
            for(int i = 0; i < nn; ++i) {
                if(vec[i] > Max) {
                    Second = Max;
                    Max = vec[i];
                }else if(vec[i] > Second){
                    Second = vec[i];
                }
            }
            ans = 
        }
        // for(int i = nn - 1; i >= 0; --i) {
        //     if(vec[i] == Max) continue;
        //     if(__gcd(Max, vec[i]) == 1) {
        //         ans = max(ans, Max * vec[i] / __gcd(Max, vec[i]));
        //     }
        // }
        // cout << vec[nn - 1] << endl;
        // for(int i = 0; i < vec.size(); ++i) {
        //     for(int j = 0; j < i; ++j) {
        //         ans2 = max(ans2, vec[i] * vec[j] / __gcd(vec[i], vec[j]));
        //     }
        // }
        // for(int i = 0; i < nn; ++i) {
        //     for(int j = 0; j < i; ++j) {
        //         if(vec[i] * vec[j] / __gcd(vec[i], vec[j]) == ans2) {
        //             cout << vec[i] << " " << vec[j] << endl;
        //         }
        //     }
        // }
        cout << "Case #" << kase << ": " << ans << endl;      
    }
    return 0;
}