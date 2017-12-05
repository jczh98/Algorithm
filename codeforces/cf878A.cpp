#include <bits/stdc++.h>
using namespace std;
int n, zero = 0, one = 1023, x, AND = 1023, OR = 0, XOR = 0;
char opt[10];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%s%d", opt, &x);
        if(opt[0] == '|') zero |= x, one |= x;
        if(opt[0] == '^') zero ^= x, one ^= x;
        if(opt[0] == '&') zero &= x, one &= x;
    }
    for(int i = 0; i <= 9; ++i) {
        if((zero & (1 << i))) {
            if((one & (1 << i))) { // 1 1
                OR |= (1 << i); 
            }else{ // 1 0
                XOR |= (1 << i);
            }           
        }else {
            if((one & (1 << i))) { // 0 1
            }else{ // 0 0
                AND &= ~(1 << i);
            }   
        }
    }
    printf("3\n& %d\n| %d\n^ %d\n", AND, OR, XOR);
    return 0;
}