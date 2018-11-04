#include <bits/stdc++.h>
using namespace std;
int n, k, sum;
int bp[1000005];
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &bp[i]);
        if(i <= k) {
            sum += bp[i];
            pq.push(bp[i]);
        }else {
            cout << sum << " ";
            int top = pq.top();
            if(bp[i] > top) {
                sum -= top; sum += bp[i];
                pq.pop();
                pq.push(bp[i]);
            }
        }
    } 
    cout << sum << endl;
    return 0;
}