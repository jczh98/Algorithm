#include <stdio.h>
#include <string.h>

int n, k, cnt[1000], proc;
char arr[100];

struct node {
    int arr, ti;
} rec[20000];

void sort(struct node *a, int len) {
    if (len <= 1) return;
    int i = 0, j = len-1;
    struct node tmp = a[0];
    while(i < j) {
        while(a[j].arr > tmp.arr && i < j) j--; a[i] = a[j];
        while(a[i].arr <= tmp.arr && i < j) i++; a[j] = a[i];
    }
    a[i] = tmp;
    sort(a, i); sort(a+i+1, len-i-1);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d %d", &h, &m, &s, &proc);
        rec[i].arr = h*3600+m*60+s;
        rec[i].ti = proc*60;
    }
    sort(rec, n);
    double ans = 0.0;
    int cntnum = 0;
    for (int j = 0; j < k; ++j) cnt[j] = 28800;
    for (int i = 0; i < n; ++i) {
        if (rec[i].arr > 61200) continue;
        cntnum++;
        int first = cnt[0], first_ind = 0;
        for (int j = 0; j < k; ++j) {
            if (first > cnt[j]) {
                first = cnt[j];
                first_ind = j;
            }
        }
        if (cnt[first_ind] <= rec[i].arr) {
            cnt[first_ind] = rec[i].arr + rec[i].ti;
        } else {
            ans += cnt[first_ind] - rec[i].arr;
            cnt[first_ind] += rec[i].ti;
        }
    }
    if (cntnum == 0) {
        printf("0.0\n");
        return 0;
    }
    printf("%.1f\n",ans/(1.0*cntnum)/60.0);
    return 0;
}
