#include <stdio.h>

struct student {
    int id, c[4];
    float a;
} stu[3000];

int n, m, cntid[10000000], rk[10000000][4];
char name[4] = {'A', 'C', 'M', 'E'};
void sort(struct student *a, int len, int sel) {
    if (len <= 1) return;
    int i = 0, j = len-1;
    struct student tmp=a[0];
    while(i < j) {
        while(a[j].c[sel]>tmp.c[sel] && i<j) j--;a[i]=a[j];
        while(a[i].c[sel]<=tmp.c[sel] && i<j) i++;a[j]=a[i];
    }
    a[i] = tmp;
    sort(a, i, sel); sort(a+i+1,len-i-1,sel);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &stu[i].id, &stu[i].c[1], &stu[i].c[2], &stu[i].c[3]);
        cntid[stu[i].id] = 1;
        stu[i].c[0] = 1.0 * (stu[i].c[1]+stu[i].c[2]+stu[i].c[3])/3;
    }
    for (int i = 0; i < 4; ++i) {
        sort(stu, n, i);
        for (int j = n-1; j >= 0; --j) {
            if (stu[j].c[i] == stu[j+1].c[i]) {
                rk[stu[j].id][i] = rk[stu[j+1].id][i];
            } else rk[stu[j].id][i] = n-j;
        }
    }
    for (int q = 1; q <= m; ++q) {
        int id;
        scanf("%d", &id);
        if (cntid[id] == 0) {
            printf("N/A\n");
            continue;
        }
        int tmp = 0;
        for (int i = 0; i < 4; ++i) {
            if (rk[id][i] < rk[id][tmp]) {
                tmp = i;
            } 
        }
        printf("%d %c\n", rk[id][tmp], name[tmp]);
    }
    return 0;
}
