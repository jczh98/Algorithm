#include<bits/stdc++.h>
#define ff(i, x, y) for(int i=x; i<=y; i++)
#define fs(i, x, y) for(int i=x; i>=y; i--)
using namespace std;
typedef long long ll;
int n;
int main() {
    scanf("%d", &n);
    ff(i, 1, n) {
        int now;
        scanf("%d", &now);
        while(now--) {
            printf("Abiyoyo,  Abiyoyo.\n");
        }
        printf("Abiyoyo,  yo  yoyo  yo  yoyo.\n");
        if(i != n)
        printf("Abiyoyo,  yo  yoyo  yo  yoyo.\n");
        else
            printf("Abiyoyo,  yo  yoyo  yo  yoyo.");
    }
    return 0;
}