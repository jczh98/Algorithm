#include <stdio.h>
#include <math.h>
using namespace std;
int s;
int main() {
    scanf("%d", &s);
    double ans = s * 1.0 * sqrt(s * 1.0 / 72.0 / acos(-1.0));
    printf("%lf\n", ans);
    return 0;
}
