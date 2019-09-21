#include <cstdio>
#include <vector>
using namespace std;
int n, tc[2000];
vector<int> vec;
void dfs(int u) {
    if (2*u>n&&2*u+1>n) {
        if(u > n) return;
        for (int i = 0; i < vec.size(); ++i) {
            printf("%d%c", vec[i], " \n"[i==vec.size()-1]);
        }
        return;
    }
    vec.push_back(tc[2*u+1]);
    dfs(2*u+1);
    vec.pop_back();
    vec.push_back(tc[2*u]);
    dfs(2*u);
    vec.pop_back();
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tc[i]);
    }
    vec.push_back(tc[1]);
    dfs(1);
    bool is_max = true, is_min = true;
    for (int i = 2; i <= n; ++i)  {
        if (tc[i>>1] > tc[i]) is_min = false;
        if (tc[i>>1] < tc[i]) is_max = false;
    }
    if (is_min) {
        printf("Min Heap\n");
    } else {
        if (is_max) {
            printf("Max Heap\n");
        } else {
            printf("Not Heap\n");
        }
    }
    return 0;
}
